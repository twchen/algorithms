/*
Reverse bits of a given 32 bits unsigned integer.

For example, given input 43261596 (represented in binary as 00000010100101000001111010011100), return 964176192 (represented in binary as 00111001011110000010100101000000).

Follow up:
If this function is called many times, how would you optimize it?

Related problem: Reverse Integer, https://leetcode.com/problems/reverse-integer/
*/

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        static int table[16] = {0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15};
        uint32_t rev = 0;
        for(int i=0; i<8; ++i){
            rev = rev << 4 | table[n & 0xf];
            n >>= 4;
        }
        return rev;
    }
};
