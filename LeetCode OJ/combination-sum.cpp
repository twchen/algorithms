/*
Given a set of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

The same repeated number may be chosen from C unlimited number of times.

Note:
All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.
For example, given candidate set [2, 3, 6, 7] and target 7, 
A solution set is: 
[
  [7],
  [2, 2, 3]
]
*/

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> acc;
        helper(candidates, 0, acc, target, res);
        return res;
    }
    
    void helper(const vector<int> &cands, int i, vector<int> &acc, int diff, vector<vector<int>> &res){
        if(diff == 0) res.push_back(acc);
        else if(diff > 0 && i < cands.size()){
            helper(cands, i+1, acc, diff, res); // use cands[i] zero times
            acc.push_back(cands[i]);
            helper(cands, i, acc, diff - cands[i], res); // use cands[i] at least once
            acc.pop_back(); // restore acc
        }
    }
};

// credit: https://discuss.leetcode.com/topic/14654/accepted-16ms-c-solution-use-backtracking-easy-understand
class Solution {
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int> > res;
        vector<int> combination;
        combinationSum(candidates, target, res, combination, 0);
        return res;
    }
private:
    void combinationSum(vector<int> &candidates, int target, vector<vector<int> > &res, vector<int> &combination, int begin) {
        if  (target == 0) {
            res.push_back(combination);
            return;
        }
        for (int i = begin; i != candidates.size() && target >= candidates[i]; ++i) {
            combination.push_back(candidates[i]);
            // combinations with candidates[i] being the smallest number
            combinationSum(candidates, target - candidates[i], res, combination, i);
            combination.pop_back();
        }
    }
};
