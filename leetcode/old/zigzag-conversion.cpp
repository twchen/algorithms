/*
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"
Write the code that will take a string and make this conversion given a number of rows:

string convert(string text, int nRows);
convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".
*/

// solution 1. 20ms
class Solution {
public:
    string convert(string s, int numRows) {
        if(s.empty() || numRows <= 1){
            return s;
        }
        string ret;
        for(int i=0; i<numRows; ++i){
            int m = i;
            int n;
            int period;
            if(m == 0 || m == numRows - 1){
                period = 4 * (numRows - 1);
                n = m + 2 * (numRows - 1);
            }else{
                period = 2 * (numRows - 1);
                n = period - m;
            }
            for(; n < s.size(); m += period, n += period){
                ret += s[m];
                ret += s[n];
            }
            if(m < s.size()){
                ret += s[m];
            }
        }
        return ret;
    }
};

// solution 2. 28ms
class Solution {
public:
    string convert(string s, int numRows) {
        if(s.empty() || numRows <= 1){
            return s;
        }
        vector<string> v(numRows);
        int mod = 2 * (numRows - 1);
        /*
        vector<int> index(mod);
        for(int i = 0; i < mod; ++i){
            index[i] = numRows - 1 - abs(numRows - 1 - i);
        }
        */
        for(int i = 0; i < s.size(); ++i){
            v[numRows - 1 - abs(numRows - 1 - i % mod)] += s[i];
            //v[index[i % mod]] += s[i];
        }
        string ret;
        for(auto str : v){
            ret += str;
        }
        return ret;
    }
};
