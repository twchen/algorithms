/*
Find all possible combinations of k numbers that add up to a number n, given that only numbers from 1 to 9 can be used and each combination should be a unique set of numbers.


Example 1:

Input: k = 3, n = 7

Output:

[[1,2,4]]

Example 2:

Input: k = 3, n = 9

Output:

[[1,2,6], [1,3,5], [2,3,4]]
*/

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> cur;
        combinationSum3(1, k, n, cur, res);
        return res;
    }
    
    void combinationSum3(int begin, int k, int n, vector<int> &cur, vector<vector<int>> &res){
        if(n == 0 && k == 0) res.push_back(cur);
        else if(k > 0){
            for(int i=begin; i<10; ++i){
                cur.push_back(i);
                combinationSum3(i+1, k-1, n-i, cur, res);
                cur.pop_back();
            }
        }
    }
};
