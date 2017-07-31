/*
Given an integer, convert it to a roman numeral.

Input is guaranteed to be within the range from 1 to 3999.
*/

// 28ms
class Solution {
public:
    string intToRoman(int num) {
        static vector<vector<string>> = {
            {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"}, // 0, 1, 2, ..., 9
            {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"}, // 0, 10, 20, ..., 90
            {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"}, // 0, 100, 200, ..., 900
            {"", "M", "MM", "MMM"} // 0, 1000, 2000, 3000
        };
        string res;
        for(int i = 0; num; ++i){
            res = table[i][num % 10] + res;
            num /= 10;
        }
        return res;
    }
};
