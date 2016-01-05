/*
Given an array of integers, every element appears twice except for one. Find that single one.

Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
*/

// why so diao
// credit: https://leetcode.com/discuss/68218/c-implementation-using-xor
class Solution {
public:
    int singleNumber(vector<int>& nums) {
    	// XOR (^) is both commutative and associative 
        // The numbers which appear twice will be cancelled
        // Only the number that appear twice survive
        // X ^ 0 = X
        int result = 0;
        for(int num : nums){
            result ^= num;
        }
        return result;
    }
};
