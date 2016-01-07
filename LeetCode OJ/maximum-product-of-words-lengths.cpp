/*
Given a string array words, find the maximum value of length(word[i]) * length(word[j]) where the two words do not share common letters. You may assume that each word will contain only lower case letters. If no such two words exist, return 0.

Example 1:
Given ["abcw", "baz", "foo", "bar", "xtfn", "abcdef"]
Return 16
The two words can be "abcw", "xtfn".

Example 2:
Given ["a", "ab", "abc", "d", "cd", "bcd", "abcd"]
Return 4
The two words can be "ab", "cd".

Example 3:
Given ["a", "aa", "aaa", "aaaa"]
Return 0
No such pair of words.
*/

// 156ms
class Solution {
public:
    int maxProduct(vector<string>& words) {
        vector<int> tables(words.size());
        for(int i = 0; i < words.size(); ++i){
            for(char c : words[i])
                tables[i] |= 1 << (c - 'a'); // bit0 = 1 means the word has 'a', bit1 = 1 means the word has 'b', ...
        }
        int maxPro = 0;
        int pro;
        for(int i = 0; i < words.size(); ++i){
            for(int j = 0; j < i; ++j){
                pro = words[i].size() * words[j].size();
                if(pro > maxPro && !(tables[i] & tables[j])){
                    maxPro = pro;
                }
            }
        }
        return maxPro;
    }
};

// 400ms
class Solution {
public:
    int maxProduct(vector<string>& words) {
        vector<vector<bool>> tables(words.size());
        for(int i = 0; i < words.size(); ++i){
            vector<bool> &t = tables[i];
            t = vector<bool>(26, false);
            for(char c : words[i]){
                t[c - 'a'] = true;
            }
        }
        int maxPro = 0;
        int pro;
        for(int i = 0; i < words.size(); ++i){
            for(int j = 0; j < i; ++j){
                pro = words[i].size() * words[j].size();
                if(pro > maxPro && !hasCommon(tables[i], tables[j])){
                    maxPro = pro;
                }
            }
        }
        return maxPro;
    }
    
    bool hasCommon(const vector<bool> &t1, const vector<bool> &t2){
        for(int i = 0; i < 26; ++i){
            if(t1[i] && t2[i])
                return true;
        }
        return false;
    }
};

// 1800ms
class Solution {
public:
    int maxProduct(vector<string>& words) {
        int maxPro = 0;
        int pro;
        for(int i = 0; i < words.size(); ++i){
            for(int j = 0; j < i; ++j){
                pro = words[i].size() * words[j].size();
                if(pro > maxPro && !hasCommon(words[i], words[j]))
                    maxPro = pro;
            }
        }
        return maxPro;
    }

    bool hasCommon(const string &s1, const string &s2){
        table = vector<char>(26);
        for(char c : s1){
            table[c - 'a']++;
        }
        for(char c : s2){
            if(table[c - 'a']) return true;
        }
        return false;
    }

private:
    vector<char> table;
};
