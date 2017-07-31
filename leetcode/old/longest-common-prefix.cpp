/*
Write a function to find the longest common prefix string amongst an array of strings.
*/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0)
            return "";
        for(int idx = 0; idx < strs[0].size(); ++idx){
            char c = strs[0][idx];
            for(int i=1; i<strs.size(); ++i){
                string &s = strs[i];
                if(idx >= s.size() || c != s[idx])
                    return strs[0].substr(0, idx);
            }
        }
        return strs[0];
    }
};
