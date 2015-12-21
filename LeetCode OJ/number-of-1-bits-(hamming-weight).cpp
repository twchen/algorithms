/*
Write a function that takes an unsigned integer and returns the number of ’1' bits it has (also known as the Hamming weight).

For example, the 32-bit integer ’11' has binary representation 00000000000000000000000000001011, so the function should return 3.
*/

class Solution {
public:
    /*
    int hammingWeight(uint32_t n) {
        int i = 0;
        do{
            i += (n % 2);
        }while(n /= 2);
        return i;
    }
    */
    int hammingWeight(uint32_t n) {
        int count = 0;
        for(; n > 0; ++count){
            n &= (n - 1);
        }
        return count;
    }
};
