/*
Given a string S, we can transform every letter individually to be lowercase or uppercase to create another string.
Return a list of all possible strings we could create.

Examples:
Input: S = "a1b2"
Output: ["a1b2", "a1B2", "A1b2", "A1B2"]

Input: S = "3z4"
Output: ["3z4", "3Z4"]

Input: S = "12345"
Output: ["12345"]
Note:

S will be a string with length at most 12.
S will consist only of letters or digits.
*/

class Solution {
public:
    vector<string> letterCasePermutation(string S) {
        static const int diff = 'A' - 'a';
        vector<string> ans;
        ans.push_back(S);
        int n = S.size();
        for(int i = 0; i < n; ++i){
            if('0' <= S[i] && S[i] <= '9')
                continue;
            char c;
            if('a' <= S[i] && S[i] <= 'z')
                c = S[i] + diff;
            else
                c = S[i] - diff;
            int size = ans.size();
            for(int j = 0; j < size; ++j){
                string s(ans[j]);
                s[i] = c;
                ans.push_back(s);
            }
        }
        return ans;
    }
};

// same idea, but more concise
// ref: https://leetcode.com/problems/letter-case-permutation/discuss/115671/Java-9-lines-iterative-code-using-backtracking.
class Solution {
public:
    vector<string> letterCasePermutation(string S) {
        vector<string> ans;
        ans.push_back(S);
        for(int i = 0; i < S.size(); ++i){
            if('0' <= S[i] && S[i] <= '9')
                continue;
            for(int j = 0, sz = ans.size(); j < sz; ++j){
                string s(ans[j]);
                s[i] ^= (1 << 5); // because abs(uppercase - lowercase) = 32
                ans.push_back(s);
            }
        }
        return ans;
    }
};

// DFS
// ref: https://leetcode.com/problems/letter-case-permutation/discuss/115508/Java-solution-using-recursion
class Solution {
public:
    vector<string> letterCasePermutation(string S) {
        vector<string> ans;
        dfs(S, 0, ans);
        return ans;
    }
    
private:
    void dfs(string &S, int i, vector<string> &ans){
        if(i == S.size())
            ans.push_back(S);
        else{
            dfs(S, i + 1, ans);
            if(S[i] < '0' || S[i] > '9'){
                S[i] ^= (1 << 5);
                dfs(S, i + 1, ans);
                S[i] ^= (1 << 5);
            }
        }
    }
};
