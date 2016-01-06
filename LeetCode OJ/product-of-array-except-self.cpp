/*
Given an array of n integers where n > 1, nums, return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].

Solve it without division and in O(n).

For example, given [1,2,3,4], return [24,12,8,6].

Follow up:
Could you solve it with constant space complexity? (Note: The output array does not count as extra space for the purpose of space complexity analysis.)
*/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n);
        res[n-1] = 1; // res[i]: the product of nums[i+1], nums[i+2], ...
        for(int i = n-2; i >= 0; --i)
            res[i] = res[i+1] * nums[i+1];
        int p = 1;
        for(int i = 0; i < n; ++i){
            res[i] = p * res[i];
            p *= nums[i];
        }
        return res;
    }
};

// one for loop solution, still two passes
class Solution {
public:
    vector<int> productExceptSelf(vector<int> &nums){
        int n = nums.size();
        vector<int> res(n, 1);
        int fromBegin = 1;
        int fromEnd = 1;
        for(int i = 0; i < n; ++i){
            res[i] *= fromBegin;
            fromBegin *= nums[i];
            res[n-1-i] *= fromEnd;
            fromEnd *= nums[n-1-i];
        }
        return res;
    }
};
