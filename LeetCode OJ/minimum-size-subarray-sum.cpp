/*
Given an array of n positive integers and a positive integer s, find the minimal length of a subarray of which the sum ≥ s. If there isn't one, return 0 instead.

For example, given the array [2,3,1,2,4,3] and s = 7,
the subarray [4,3] has the minimal length under the problem constraint.

click to show more practice.

More practice:
If you have figured out the O(n) solution, try coding another solution of which the time complexity is O(n log n).
 */

// O(n^2) solution
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int n = nums.size();
        vector<int> sums(nums);
        for(int len=1; len <= n; ++len){
            for(int i=0; i <= n-len; ++i){
                if(s <= sums[i]) return len;
                sums[i] += nums[i+len];
            }
        }
        return 0;
    }
};
