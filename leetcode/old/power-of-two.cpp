/*
Given an integer, write a function to determine if it is a power of two.
*/

class Solution {
public:
    bool isPowerOfTwo(int n) {
        /*
        // trivial solution
        if(n < 1)
            return false;

        // recursive
        if(n == 1)
            return true;
        return (n % 2 == 0) && isPowerOfTwo(n >> 1);

        // iterative
        while(n != 1){
            if(n % 2)
                return false;
            n >>= 1;
        }
        return true;
        */
        // n is a power of 2 iff n has only one bit 1
        return n > 0 && (n & (n - 1)) == 0;
    }
};
