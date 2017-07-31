/*
Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target.
Return the sum of the three integers. You may assume that each input would have exactly one solution.

    For example, given array S = {-1 2 1 -4}, and target = 1.

    The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
 */

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int closest = (target >= 0 ? numeric_limits<int>::max() : numeric_limits<int>::min());
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for(int i = 0; i + 2 < n; ++i){
            int left = i + 1;
            int right = n - 1;
            while(left < right){
                int sum = nums[i] + nums[left] + nums[right];
                if(sum < target) ++left;
                else if(sum > target) --right;
                else return target;
                if(abs(sum - target) < abs(closest - target)) closest = sum;
            }
        }
        return closest;
    }
};
