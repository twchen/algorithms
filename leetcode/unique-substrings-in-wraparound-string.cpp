/*
Consider the string s to be the infinite wraparound string of "abcdefghijklmnopqrstuvwxyz", so s will look like this:
"...zabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcd....".

Now we have another string p. Your job is to find out how many unique non-empty substrings of p are present in s.
In particular, your input is the string p and you need to output the number of different non-empty substrings of p
in the string s.

Note: p consists of only lowercase English letters and the size of p might be over 10000.

Example 1:
Input: "a"
Output: 1

Explanation: Only the substring "a" of string "a" is in the string s.
Example 2:
Input: "cac"
Output: 2
Explanation: There are two substrings "a", "c" of string "cac" in the string s.
Example 3:
Input: "zab"
Output: 6
Explanation: There are six substrings "z", "a", "b", "za", "ab", "zab" of string "zab" in the string s.
*/

// 1st attempt, BFS
// timeout
class Solution {
public:
    int findSubstringInWraproundString(string p) {
        map<char, vector<int>> h1, h2;
        auto prev = &h1, curr = &h2;
        int n = p.size();
        for(int i = 0; i < n; ++i){
            h1[p[i]].push_back(i);
        }
        int count = 0;
        while(!prev->empty()){
            count += prev->size();
            for(auto it = prev->begin(); it != prev->end(); ++it){
                for(int i : it->second){
                    if(i + 1 < n && p[i + 1] - 'a' == (it->first + 1 - 'a') % 26 ) {
                        (*curr)[p[i + 1]].push_back(i + 1);
                    }
                }
            }
            prev->clear();
            swap(prev, curr);
        }
        return count;
    }
};

// 2nd attempt, still BFS, use vector instead of map to speed up
// accepted. T^T
class Solution {
public:
    int findSubstringInWraproundString(string p) {
        vector<vector<int>> h1(26), h2(26);
        auto prev = &h1, curr = &h2;
        int n = p.size();
        for(int i = 0; i < n; ++i){
            h1[p[i] - 'a'].push_back(i);
        }
        int count = 0;
        do{
            int size = 0;
            for(int i = 0; i < 26; ++i){
                if((*prev)[i].size() > 0) ++size;
                else continue;
                for(int j : (*prev)[i]){
                    if(j + 1 < n && (p[j + 1] - 'a' - i + 26) % 26 == 1){
                        (*curr)[(i + 1) % 26].push_back(j + 1);
                    }
                }
                (*prev)[i].clear();
            }
            if(size > 0) count += size;
            else break;
            swap(prev, curr);
        }while(true);
        return count;
    }
};

class Solution {
public:
    int findSubstringInWraproundString(string p) {
        int n = p.size();
        vector<int> lengths(26, 0); // lengths[i]: length of longest substring of s in p starting with 'a' + i
        for(int i = 0; i < n; ){
            int j = i + 1;
            while(j < n && (p[j] - p[i] - j + i) % 26 == 0) ++j;
            for(int k = i; k < i + 26 && k < j; ++k){
                if(lengths[p[k] - 'a'] < j - k)
                    lengths[p[k] - 'a'] = j - k;
            }
            i = j;
        }
        return accumulate(lengths.begin(), lengths.end(), 0);
    }
};

// credit: https://leetcode.com/problems/unique-substrings-in-wraparound-string/discuss/95439/Concise-Java-solution-using-DP
class Solution {
public:
    int findSubstringInWraproundString(string p) {
        int n = p.size();
        if(n == 0) return 0;
        vector<int> dp(26, 0); // dp[i]: length of longest substring of s in p ending with 'a' + i
        int len = 1;
        dp[p[0] - 'a'] = 1;
        for(int i = 1; i < p.size(); ++i){
            //if((p[i] - p[i - 1] + 26) % 26 == 1) ++len;
            if(p[i] == p[i-1] + 1 || p[i-1] == 'z' && p[i] == 'a') ++len; // slightly faster
            else len = 1;
            dp[p[i] - 'a'] = max(dp[p[i] - 'a'], len);
        }
        return accumulate(dp.begin(), dp.end(), 0);
    }
};