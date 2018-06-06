/*
Given a digit string, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below.



Input:Digit string "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
Note:
Although the above answer is in lexicographical order, your answer could be in any order you want.
 */

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if(digits.size() > 0) res.push_back("");
        for(char c : digits){
            int idx = c - '2';
            const string &chars = keypad[idx];
            int num_chars = chars.size();
            int prev_size = res.size();
            for(int i = 0; i < num_chars - 1; ++i){
                for(int j = 0; j < prev_size; ++j){
                    res.push_back(res[j]);
                }
            }
            for(int i = 0; i < num_chars; ++i){
                for(int j = 0; j < prev_size; ++j){
                    res[i * prev_size + j].push_back(chars[i]);
                }
            }
        }
        return res;
    }

private:
    static const vector<string> keypad;
};

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        int size = digits.size();
        if(size == 0) return vector<string>();
        return helper(digits, digits.size());
    }

private:
    vector<string> helper(const string &digits, int last){
        vector<string> res;
        if(last == 0) res.push_back("");
        else{
            const vector<string> &prev_res = helper(digits, last - 1);
            for(const char c : keypad[digits[last - 1] - '2']){
                for(const string &w : prev_res){
                    res.push_back(std::move(w + c));
                }
            }
        }
        return res;
    }

    static const vector<string> keypad;
};

const vector<string> Solution::keypad = {
        "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
};

// note the line res.swap(temp) and local static variable
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        static const vector<string> keypad = { "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
        vector<string> res;
        if(digits.empty()) return res;
        res.push_back("");
        for(auto d : digits){
            vector<string> temp;
            for(auto c : keypad[d - '2']){
                for(string &s : res){
                    temp.push_back(std::move(s + c));
                }
            }
            res.swap(temp);
        }
        return res;
    }
};
