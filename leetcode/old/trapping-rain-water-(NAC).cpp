/*
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.

For example, 
Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.
 */

class Solution {
public:
    int trap(vector<int>& height) {
        int amount = 0;
        int level = 0;
        int n = height.size();
        while(true){
            int idx = 0;
            // find the first number above the current level
            while(idx < n && height[idx] <= level) ++idx;
            if(idx == n) return amount;
            for(int i=idx+1; i < n; ++i){
                if(height[i] > level){
                    amount += (i - idx - 1);
                    idx = i;
                }
            }
            ++level;
        }
        return amount;
    }
};
