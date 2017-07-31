/*
You are climbing a stair case. It takes n steps to reach to the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
*/

class Solution {
public:
    int climbStairs(int n) {
        int prev = 1;
        int curr = 1;
        int result = 1;
        while(--n){
            result = prev + curr;
            prev = curr;
            curr = result;
        }
        return result;
    }
};
