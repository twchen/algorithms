/*
Given an array of strings, group anagrams together.

For example, given: ["eat", "tea", "tan", "ate", "nat", "bat"], 
Return:

[
  ["ate", "eat","tea"],
  ["nat","tan"],
  ["bat"]
]
Note: All inputs will be in lower-case.
 */

// 122ms
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<vector<int>, vector<string>> table;
        for(auto s: strs){
            vector<int> freq(26);
            for(auto c: s)
                ++freq[c - 'a'];
            table[freq].push_back(s);
        }
        vector<vector<string>> result;
        for(auto it = table.begin(); it != table.end(); ++it)
            result.push_back(it->second);
        return result;
    }
};

// 66ms, 88ms if use map instead of unordered_map
// same idea, but use string instead of vector to store the number of occurrences of characters.
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> table;
        for(auto s: strs){
            string freq(26, 0);
            for(auto c: s)
                ++freq[c - 'a'];
            table[freq].push_back(s);
        }
        vector<vector<string>> result;
        for(auto it = table.begin(); it != table.end(); ++it)
            result.push_back(it->second);
        return result;
    }
};

// even more efficient solution
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, int> hash;
        vector<vector<string>> res;
        for(string& str: strs){
            string count(26, '\0');
            for(char c: str){
                ++count[c - 'a'];
            }
            auto it = hash.find(count);
            if(it == hash.end()){
                hash[count] = res.size();
                vector<string> words;
                words.push_back(str);
                res.push_back(words);
            }else{
                res[it->second].push_back(str);
            }
        }
        return res;
    }
};
