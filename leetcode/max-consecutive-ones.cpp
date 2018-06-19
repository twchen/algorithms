/*
Given a binary array, find the maximum number of consecutive 1s in this array.

Example 1:
Input: [1,1,0,1,1,1]
Output: 3
Explanation: The first two digits or the last three digits are consecutive 1s.
    The maximum number of consecutive 1s is 3.
Note:

The input array will only contain 0 and 1.
The length of input array is a positive integer and will not exceed 10,000
 */

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int len = 0;
        int n = nums.size();
        for(int i = 0; i < n; ++i){
            if(nums[i] == 0) continue;
            int j = i + 1;
            while(j < n && nums[j] == 1) ++j;
            if(len < j - i) len = j - i;
            i = j;
        }
        return len;
    }
};
