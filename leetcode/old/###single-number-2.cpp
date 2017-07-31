/*
Given an array of integers, every element appears three times except for one. Find that single one.

Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
*/

// credit: https://leetcode.com/discuss/6632/challenge-me-thx
/*
The code seems tricky and hard to understand at first glance. However, if you consider the problem in Boolean algebra form, everything becomes clear.

What we need to do is to store the number of '1's of every bit. Since each of the 32 bits follow the same rules, we just need to consider 1 bit. We know a number appears 3 times at most, so we need 2 bits to store that. Now we have 4 state, 00, 01, 10 and 11, but we only need 3 of them.

In this solution, 00, 01 and 10 are chosen. Let 'ones' represents the first bit, 'twos' represents the second bit. Then we need to set rules for 'ones' and 'twos' so that they act as we hopes. The complete loop is 00->10->01->00(0->1->2->3/0).

For 'ones', we can get 'ones = ones ^ A[i]; if (twos == 1) then ones = 0', that can be tansformed to 'ones = (ones ^ A[i]) & ~twos'.

Similarly, for 'twos', we can get 'twos = twos ^ A[i]; if (ones* == 1) then twos = 0' and 'twos = (twos ^ A[i]) & ~ones'. Notice that 'ones*' is the value of 'ones' after calculation, that is why twos is calculated later.
*/


// zhe ge cai shi TMD zhen diao
// consider only one bit
// truth table
// bit1 bit0 num    new_bit1 new_bit0
//  0    0    0         0       0
//  0    0    1         0       1
//  0    1    0         0       1
//  0    1    1         1       0
//  1    0    0         1       0
//  1    0    1         0       0
//  1    1    0         X       X
//  1    1    1         X       X
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int bit1 = 0;
        int bit0 = 0;
        for(int num : nums){
            bit0 = (bit0 ^ num) & ~bit1;
            bit1 = (bit1 ^ num) & ~bit0;
        }
        return bit0;
    }
};
