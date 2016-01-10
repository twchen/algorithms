/*
Given an integer, write a function to determine if it is a power of three.

Follow up:
Could you do it without using any loop / recursion?
*/

class Solution {
public:
    // best solution
    // 132ms
    bool isPowerOfThree(int n) {
        static const int MAX_POWER_OF_THREE = pow(3, int(log(INT_MAX) / log(3)));
        return n > 0 && MAX_POWER_OF_THREE % n == 0;
    }
    /*
    // 180ms
    bool isPowerOfThree(int n){
        if(n <= 0) return false;
        double d = log10(n) / log10(3);
        return int(d) == d;
    }
    */
    /*
    // iterative
    // 132ms
    bool isPowerOfThree(int n){
        if(n > 1){
            while(n % 3 == 0){
                n /= 3;
            }
        }
        return n == 1;
    }
    */
    /*
    // recursive
    // 136ms
    bool isPowerOfThree(int n){
        return n > 0 && (n == 1 || (n % 3 == 0 && isPowerOfThree(n / 3)));
    }
    */
};
