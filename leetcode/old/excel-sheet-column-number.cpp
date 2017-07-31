/*
Related to question Excel Sheet Column Title: https://leetcode.com/problems/excel-sheet-column-title/

Given a column title as appear in an Excel sheet, return its corresponding column number.

For example:

    A -> 1
    B -> 2
    C -> 3
    ...
    Z -> 26
    AA -> 27
    AB -> 28
*/

class Solution {
public:
    int titleToNumber(string s) {
        int ret = 0;
        int base = 1;
        for(auto it = s.rbegin(); it != s.rend(); ++it){
            ret += ((*it) - 'A' + 1) * base;
            base *= 26;
        }
        return ret;
    }
};
