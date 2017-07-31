/*
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security system connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.
*/

class Solution {
public:
    int rob(vector<int>& nums) {
        int size = nums.size();
        if(size == 0)
            return 0;
        vector<int> m(size+1); // m[i]: maximum amount given first i houses
        m[0] = 0;
        m[1] = nums[0];
        for(int i=2; i<size+1; ++i)
            m[i] = max(m[i-1], m[i-2] + nums[i-1]); // dynamic programming recursive formula
        return m[size];
    }
};
