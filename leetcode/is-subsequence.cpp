/*
Given a string s and a string t, check if s is subsequence of t.

You may assume that there is only lower case English letters in both s and t. t is potentially a very long
(length ~= 500,000) string, and s is a short string (<=100).

A subsequence of a string is a new string which is formed from the original string by deleting some (can be none)
of the characters without disturbing the relative positions of the remaining characters. (ie, "ace" is a subsequence
of "abcde" while "aec" is not).

Example 1:
s = "abc", t = "ahbgdc"

Return true.

Example 2:
s = "axc", t = "ahbgdc"

Return false.

Follow up:
If there are lots of incoming S, say S1, S2, ... , Sk where k >= 1B, and you want to check one by one to see if T has
its subsequence. In this scenario, how would you change your code?
*/

// recursive
class Solution {
public:
    bool isSubsequence(string s, string t) {
        return isSubsequence(s, t, s.size() - 1, t.size() - 1);
    }
    
    bool isSubsequence(string &s, string &t, int i, int j){
        if(i < 0 || j < 0) return i <= j;
        if(s[i] == t[j]) return isSubsequence(s, t, i - 1, j - 1);
        else return isSubsequence(s, t, i, j - 1);
    }
};

// iterative
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n = s.size();
        int m = t.size();
        int i = 0;
        for(int j = 0; i < n && n - i <= m - j; ++i){
            while(j < m && s[i] != t[j]) ++j;
            if(j == m) return false;
            ++j;
        }
        return i == n;
    }
};

// iterative
// credit: https://leetcode.com/problems/is-subsequence/discuss/87402/C++-4-lines-simple-solution
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n = s.size();
        int m = t.size();
        int i = 0;
        for(int j = 0; j < m && i < n; ++j){
            if(t[j] == s[i]) ++i;
        }
        return i == n;
    }
};

// solution for follow-up question
// credit: https://leetcode.com/problems/is-subsequence/discuss/87264/Easy-to-understand-binary-search-solution
// let n = average length of s, m = length of t, k = # of s
// space complexity: O(m)
// time complexity: O(m + k * n * log(m)), compared with O(k * m) of previous solutions
class Solution {
public:
    bool isSubsequence(string s, string t) {
        // key: character
        // value: the indices of key in t, sorted in ascending order
        vector<vector<int>> hash(26);
        for(int i = 0; i < t.size(); ++i){
            hash[t[i] - 'a'].push_back(i); // s and t contain only lowercase letters
        }
        int j = 0; // current index in t
        for(auto c : s){
            int i = binarySearch(hash[c - 'a'], j);
            if(i < 0) return false;
            j = i + 1;
        }
        return true;
    }

    // indices: a list of indices for certain character
    // return the first index that is >= lower
    int binarySearch(vector<int> &indices, int lower){
        int left = 0;
        int right = indices.size() - 1;
        while(left <= right){
            int mid = (left + right) / 2;
            if(indices[mid] < lower)
                left = mid + 1;
            else if(indices[mid] > lower)
                right = mid - 1;
            else
                return indices[mid];
        }
        return left == indices.size() ? -1 : indices[left];
    }
};
