/*
Given a digit string, return all possible letter combinations that the number could represent.

The mapping of digit to letters is just like on the telephone buttons.

Input:Digit string "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
*/

class Solution {
public:
    Solution(){
        mymap = { "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
    }
    vector<string> letterCombinations(string digits) {
        vector<string> v1, v2;
        auto prev = &v1, cur = &v2;
        if(!digits.empty()) prev->push_back("");
        for(auto d: digits){
            cur->clear();
            for(auto s: (*prev)){
                for(auto c: mymap[d - '2']){
                    cur->push_back(s + c);
                }
            }
            swap(prev, cur);
        }
        return (*prev);
    }

private:
    vector<string> mymap;
};
