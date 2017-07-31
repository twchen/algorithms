/*
Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note: The solution set must not contain duplicate triplets.

For example, given array S = [-1, 0, 1, 2, -1, -4],

A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]
*/

// idea: suppose a <= b <= c, fix a and b first, then check whether c = -a-b exists in nums
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        if(nums.size() < 3 || nums.front() > 0 || nums.back() < 0) return res;
        int a = nums.front() - 1; // previous first number
        for(int i = 0; i < nums.size() - 2; ++i){
            if(nums[i] == a) continue;
            if(nums[i] + nums[i+1] > 0) break;
            int b = nums[i+1] - 1; // previous second number
            int k = nums.size() - 1; // nums[k] third number
            for(int j = i+1; j < nums.size() - 1 && j < k; ++j){
                if(nums[j] == b) continue;
                while(j < k && nums[i] + nums[j] + nums[k] > 0) --k;
                if(j < k && nums[i] + nums[j] + nums[k] == 0)
                    res.push_back({nums[i], nums[j], nums[k]});
                b = nums[j];
            }
            a = nums[i];
        }
        return res;
    }
};

// easier to understand solution
// credit: https://discuss.leetcode.com/topic/8107/share-my-ac-c-solution-around-50ms-o-n-n-with-explanation-and-comments
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        if(nums.size() < 3 || nums.front() > 0 || nums.back() < 0) return res;
        // note that i < nums.size() - 2 will cause infinite loop problem if nums.size() < 2
        // because the return type of nums.size() is size_type, equivalent to unsigned integral
        // overflow will happen if nums.size() - 2 < 0
        for(int i = 0; i + 2 < nums.size(); ++i){
            int target = -nums[i]; // a = nums[i], target = 0 - a
            int left = i + 1; // b = nums[left]
            int right = nums.size() - 1; // c = nums[right]
            while(left < right){
                if(nums[left] + nums[right] < target) ++left;
                else if(nums[left] + nums[right] > target) --right;
                else{
                    res.push_back({nums[i], nums[left], nums[right]});
                    int prev_b = nums[left];
                    int prev_c = nums[right];
                    while(left < right && nums[left] == prev_b) ++left;
                    while(left < right && nums[right] == prev_c) --right;
                }
            }
            while(i + 3 < nums.size() && nums[i] == nums[i + 1]) ++i;
        }
        return res;
    }
};

// improved version (taken the idea from https://discuss.leetcode.com/topic/28641/my-16ms-c-code)
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        if(n < 3 || nums.front() > 0 || nums.back() < 0) return res;
        for(int i = 0; i + 2 < n; ++i){
            int target = -nums[i]; // a = nums[i], target = 0 - a
            int left = i + 1; // b = nums[left]
            int right = n - 1; // c = nums[right]
            while(left < right){
                if(nums[left] + nums[right] < target) ++left;
                else if(nums[left] + nums[right] > target) --right;
                else{
                    res.push_back({nums[i], nums[left], nums[right]});
                    do { ++left; } while(left < right && nums[left] == nums[left - 1]);
                    do { --right; } while(left < right && nums[right] == nums[right + 1]);
                }
            }
            while(i + 3 < n && nums[i] == nums[i + 1]) ++i;
        }
        return res;
    }
};
