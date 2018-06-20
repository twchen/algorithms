/*
We have two special characters. The first character can be represented by one bit 0.
The second character can be represented by two bits (10 or 11).

Now given a string represented by several bits. Return whether the last character must be a
one-bit character or not. The given string will always end with a zero.

Example 1:
Input: 
bits = [1, 0, 0]
Output: True
Explanation: 
The only way to decode it is two-bit character and one-bit character.
So the last character is one-bit character.

Example 2:
Input: 
bits = [1, 1, 1, 0]
Output: False
Explanation: 
The only way to decode it is two-bit character and two-bit character.
So the last character is NOT one-bit character.

Note:
1 <= len(bits) <= 1000.
bits[i] is always 0 or 1.
*/

class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int n = bits.size();
        if(n < 2) return true;
        vector<bool> dp(n + 1);
        dp[0] = true;
        dp[1] = bits[0] == 0;
        for(int i = 1; i < n; ++i){
            if(bits[i] == 0)
                dp[i + 1] = dp[i] || bits[i - 1] == 1 && dp[i - 1];
            else
                dp[i + 1] = bits[i - 1] == 1 && dp[i - 1];
        }
        return dp[n - 1];
    }
};

class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int i = 0;
        int n = bits.size();
        while(i < n - 1){
            if(bits[i] == 1) i += 2;
            else ++i;
        }
        return i == n - 1;
    }
};

// optimal solution
// credit: https://leetcode.com/problems/1-bit-and-2-bit-characters/discuss/108967/JAVA-check-only-the-end-of-array
/*
split the bits to two parts
xxxxx01...10 -> xxxxx0 and 1...10
the last bit of the first part is the second last 0
so the second part is a sequence of 1s and the last 0
we claim that the first part (if any) is always valid
   (we can prove by induction, let n be the length of the first part
      when n = 1, the first part is "0", valid.
      suppose when n = k, the first part is valid,
      when n = k+1,
        if the second last bit is 0, then the first part is xxxx0 + 0, valid by induction hypothesis
        if the second last bit is 1, let m be the number of sequential 1s before the last 0,
          the bits before the sequential 1s are valid by induction hypothesis,
          for the m sequential 1s and the last 0:
            if m is odd, the first (m - 1) 1s can be paired, the last 1 and the last 0 can be paired
            if m is even, the first m 1s can be paired, the last 0 is alone.
            so the m sequential 1s and the last 0 are also valid
        so when n = k+1, also valid
   )
so the last bit is a one bit iff the second part has even number of 1s.
*/
class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int ones = 0;
        for(int i = bits.size() - 2; i >= 0 && bits[i] != 0; --i)
            ++ones;
        return ones % 2 == 0;
    }
};
