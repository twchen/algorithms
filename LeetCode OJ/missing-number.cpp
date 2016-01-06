/*
Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, find the one that is missing from the array.

For example,
Given nums = [0, 1, 3] return 2.

Note:
Your algorithm should run in linear runtime complexity. Could you implement it using only constant extra space complexity?
*/

// credits: https://leetcode.com/discuss/53802/c-solution-using-bit-manipulation
class Solution {
public:
    // XOR (all numbers in nums array and 0, 1, ..., n)
    // each number in 0 ~ n appears twice except the missing number, so the result is the missing number, similar to the "single number" problem
    int missingNumber(vector<int> &nums){
        int n = nums.size();
        int res = n;
        for(int i = 0; i < n; ++i){
            res ^= i;
            res ^= nums[i];
        }
        return res;
    }
    /*
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int x = 0;
        int y = 0;
        for(int i = 0; i < n; ++i){
            x ^= i;
            y ^= nums[i];
        }
        return x ^ n ^ y;
    }
    */
};

// my solution
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        // x: result of XOR(0, 1, ..., n)
        // y: result of XOR(all numbers in nums)
        // and missing_number ^ y = x
        // so missing_number = (missing_number ^ y) ^ y = x ^ y
        int n = nums.size();
        int x = n;
        int y = 0;
        for(int i = 0; i < n; ++i){
            x ^= i;
            y ^= nums[i];
        }
        return x ^ y;
    }
};
