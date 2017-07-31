/*
Given a string s, partition s such that every substring of the partition is a palindrome.

Return all possible palindrome partitioning of s.

For example, given s = "aab",
Return

[
  ["aa","b"],
  ["a","a","b"]
]
*/

class Solution {
public:
    bool isPalindrome(const string &s, int start, int end) {
        for(; start < end; ++start, --end){
            if(s[start] != s[end])
                return false;
        }
        return true;
    }

    vector<vector<string>> partition(string s) {
        auto res = vector<vector<string>>();
        auto path = vector<string>();
        partitionHelper(s, 0, path, res);
        return res;
    }
    
    // path will not change before and after calling partitionHelper
    void partitionHelper(const string &s, int start, vector<string> &path, vector<vector<string>> &res) {
        if(start == s.size()){
            res.push_back(path);
            return;
        }
        
        for(int i = start; i < s.size(); ++i){
            if(isPalindrome(s, start, i)){
                path.push_back(s.substr(start, i - start + 1));
                partitionHelper(s, i+1, path, res);
                path.pop_back(); // restore path
            }
        }
    }
};
