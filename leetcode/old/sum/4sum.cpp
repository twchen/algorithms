/*
Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.

Note: The solution set must not contain duplicate quadruplets.

For example, given array S = [1, 0, -1, 0, -2, 2], and target = 0.

A solution set is:
[
  [-1,  0, 0, 1],
  [-2, -1, 1, 2],
  [-2,  0, 0, 2]
]
*/

// use the same method of solving the three sum problem
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); ++i){
            int diff1 = target - nums[i];
            for(int j = i + 1; j < nums.size(); ++j){
                int diff2 = diff1 - nums[j];
                int k = j + 1, l = nums.size() - 1;
                while(k < l){
                    int sum = nums[k] + nums[l];
                    if(sum < diff2) ++k;
                    else if(sum > diff2) --l;
                    else{
                        res.push_back({nums[i], nums[j], nums[k], nums[l]});
                        int prev_c = nums[k];
                        int prev_d = nums[l];
                        while(k < l && nums[k] == prev_c) ++k;
                        while(k < l && nums[l] == prev_c) --l;
                    }
                }
                while(j + 1 < nums.size() && nums[j] == nums[j + 1]) ++j;
            }
            while(i + 1 < nums.size() && nums[i] == nums[i + 1]) ++i;
        }
        return res;
    }
};

// use early pruning and less temp variables
// speed improved from 66ms to 13ms
// credit: https://discuss.leetcode.com/topic/28641/my-16ms-c-code
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> res;
        if(n < 4) return res;
        sort(nums.begin(), nums.end());
        for(int i = 0; i + 3 < n; ++i){
            int diff1 = target - nums[i];
            // early pruning
            if(nums[i+1] + nums[i+2] + nums[i+3] > diff1) break;
            if(nums[n-3] + nums[n-2] + nums[n-1] < diff1) continue;
            for(int j = i + 1; j + 2 < n; ++j){
                int diff2 = diff1 - nums[j];
                // early pruning
                if(nums[j+1] + nums[j+2] > diff2) break;
                if(nums[n-2] + nums[n-1] < diff2) continue;
                int k = j + 1, l = n - 1;
                while(k < l){
                    int sum = nums[k] + nums[l];
                    if(sum < diff2) ++k;
                    else if(sum > diff2) --l;
                    else{
                        res.push_back({nums[i], nums[j], nums[k], nums[l]});
                        // less temp variables
                        do{ ++k; } while(k < l && nums[k] == nums[k - 1]);
                        do{ --l; } while(k < l && nums[l] == nums[l + 1]);
                    }
                }
                while(j + 1 < n && nums[j] == nums[j + 1]) ++j;
            }
            while(i + 1 < n && nums[i] == nums[i + 1]) ++i;
        }
        return res;
    }
};
