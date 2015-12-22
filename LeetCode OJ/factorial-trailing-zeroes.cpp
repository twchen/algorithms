/*
Given an integer n, return the number of trailing zeroes in n!.

Note: Your solution should be in logarithmic time complexity.
*/

class Solution {
public:
    int trailingZeroes(int n) {
        int num = 0;
        /*
        int d = 5;
        while(n >= d){
            num += n / d;
            d *= 5;
        }
        */
        while(n){
            n /= 5;
            num += n;
        }
        return num;
    }
};
