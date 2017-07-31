/*
Given a roman numeral, convert it to an integer.

Input is guaranteed to be within the range from 1 to 3999.
*/

class Solution {
public:
    Solution(){
        table['I'] = 1;
        table['V'] = 5;
        table['X'] = 10;
        table['L'] = 50;
        table['C'] = 100;
        table['D'] = 500;
        table['M'] = 1000;
    }
    int romanToInt(string s) {
        int res = 0;
        int curr;
        for(int i = 0; i < s.size(); ++i){
            curr = table[s[i]];
            if(i+1 < s.size() && curr < table[s[i+1]]){
                res -= curr;
            }else{
                res += curr;
            }
        }
        return res;
    }

private:
    unordered_map<char, int> table;
};
