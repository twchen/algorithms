/*
Given a collection of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

Each number in C may only be used once in the combination.

Note:
All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.
For example, given candidate set [10, 1, 2, 7, 6, 1, 5] and target 8, 
A solution set is: 
[
  [1, 7],
  [1, 2, 5],
  [2, 6],
  [1, 1, 6]
]
*/

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> acc;
        sort(candidates.begin(), candidates.end());
        vector<int> cands, times; // times: frequency of candidates
        // a dummy candidate
        cands.push_back(0);
        times.push_back(0); 
        for(int c: candidates){
            if(c != cands.back()){
                cands.push_back(c);
                times.push_back(1);
            }else{
                ++(times.back());
            }
        }
        helper(cands, times, 1, acc, target, res);
        return res;
    }

    void helper(const vector<int> &cands, vector<int> &times, int i, vector<int> &acc, int diff, vector<vector<int>> &res){
        if(diff == 0) res.push_back(acc);
        else if(diff > 0 && i < cands.size()){
            if(cands[i] < diff) helper(cands, times, i+1, acc, diff, res); // use cands[i] zero times
            if(times[i] > 0){
                acc.push_back(cands[i]);
                --times[i];
                helper(cands, times, i, acc, diff - cands[i], res); // use cands[i] at least once
                ++times[i]; // restore frequency vector
                acc.pop_back(); // restore acc
            }
        }
    }
};

// without using frequency vector
// credit: https://discuss.leetcode.com/topic/14654/accepted-16ms-c-solution-use-backtracking-easy-understand
class Solution {
public:
    vector<vector<int> > combinationSum2(vector<int> &candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int> > res;
        vector<int> combination;
        combinationSum2(candidates, target, res, combination, 0);
        return res;
    }
private:
    void combinationSum2(vector<int> &candidates, int target, vector<vector<int> > &res, vector<int> &combination, int begin) {
        if  (!target) {
            res.push_back(combination);
            return;
        }
        for (int i = begin; i != candidates.size() && target >= candidates[i]; ++i)
            if (i == begin || candidates[i] != candidates[i - 1]) {
                combination.push_back(candidates[i]);
                // combinations having candidates[i] as the smallest number
                // since each candidate can use once only, need to increase begin by 1, i.e. i+1
                combinationSum2(candidates, target - candidates[i], res, combination, i + 1);
                combination.pop_back(); // restore 'combination'
            }
    }
};
