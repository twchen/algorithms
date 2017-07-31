/*
A message containing letters from A-Z is being encoded to numbers using the following mapping:

'A' -> 1
'B' -> 2
...
'Z' -> 26
Given an encoded message containing digits, determine the total number of ways to decode it.

For example,
Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).

The number of ways decoding "12" is 2.
 */

class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        if(n == 0 || s[0] == '0') return 0;
        vector<int> m(n+1, 0); // m[i]: the number of ways to decode the first i chars
        m[0] = 1;
        m[1] = 1;
        for(int i=2; i<=n; ++i){
            char c = s[i-1];
            if(c == '0'){
                if(s[i-2] == '1' || s[i-2] == '2') m[i] = m[i-2];
                else return 0; // illegal string
            }else if('1' <= c && c <= '6'){
                m[i] = m[i-1];
                if(s[i-2] == '1' || s[i-2] == '2') m[i] += m[i-2];
            }else{
                m[i] = m[i-1];
                if(s[i-2] == '1') m[i] += m[i-2];
            }
        }
        return m[n];
    }
};
