/*
You are given a list of non-negative integers, a1, a2, ..., an, and a target, S. Now you have 2 symbols + and -. For each
integer, you should choose one from + and - as its new symbol.

Find out how many ways to assign symbols to make sum of integers equal to target S.

Example 1:
Input: nums is [1, 1, 1, 1, 1], S is 3. 
Output: 5
Explanation: 

-1+1+1+1+1 = 3
+1-1+1+1+1 = 3
+1+1-1+1+1 = 3
+1+1+1-1+1 = 3
+1+1+1+1-1 = 3

There are 5 ways to assign symbols to make the sum of nums be target 3.
Note:
The length of the given array is positive and will not exceed 20.
The sum of elements in the given array will not exceed 1000.
Your output answer is guaranteed to be fitted in a 32-bit integer.
*/


// 408ms
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        return findTargetSumWays(nums, nums.size() - 1, S);
    }
    
    int findTargetSumWays(vector<int> &nums, int i, int S){
        if(i < 0) return S == 0;
        return findTargetSumWays(nums, i - 1, S - nums[i]) + findTargetSumWays(nums, i - 1, S + nums[i]);
    }
};

// 397ms
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        map<int, int> hash;
        hash[0] = 1;
        for(int x : nums){
            if(x != 0){
                for(auto it = hash.rbegin(); it != hash.rend(); ++it){
                    hash[it->first + x] = it->second;
                    it->second = 0;
                }
            }
            for(auto it = hash.begin(); it != hash.end(); ++it){
                hash[it->first - 2 * x] += it->second;
            }
        }
        return hash[S];
    }
};

// dp 8ms ...
// credit: https://leetcode.com/problems/target-sum/discuss/97334/Java-(15-ms)-C++-(3-ms)-O(ns)-iterative-DP-solution-using-subset-sum-with-explanation
// P: elements with + operator
// N: elements with - operator or (nums \ P)
// objective: find number of subsets P, such that sum(P) - sum(N) = S
// <==> sum(P) - sum(N) + sum(P) + sum(Q) = S + sum(P) + sum(Q)
// <==> 2 * sum(P) = S + sum(nums)
// equivalent problem: find number of subsets P, such that sum(P) = (S + sum(nums)) / 2
// if sum(nums) < S or S + sum(nums) is odd, no such P.
// let N = nums.size(), target = (S + sum(nums)) / 2
// dp[n, t] = number of subsets of first n elements, whose elements sum to t.
// recursive formula: dp[n, t] = dp[n - 1, t] + dp[n - 1, t - nums[n]]
// dp[n - 1, t]: not use nums[n]
// dp[n - 1, t - nums[n]]: use nums[n], = 0 if t - nums[n] < 0
// objective: find dp[N, target]
// optimization: only keep track of dp[n, :]
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum < S || (S + sum) % 2) return 0;
        int target = (S + sum) / 2;
        vector<int> dp(target + 1, 0);
        dp[0] = 1;
        for(int n : nums)
            for(int i = target; i >= n; --i)
                dp[i] += dp[i - n];
        return dp[target];
    }
};
