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
