/*
Write a function that takes a string as input and reverse only the vowels of a string.

Example 1:
Given s = "hello", return "holle".

Example 2:
Given s = "leetcode", return "leotcede".
*/

// my solution
class Solution {
public:
    bool isVowel(char c){
        return c == 'a' || c == 'A'
            || c == 'o' || c == 'O'
            || c == 'e' || c == 'E'
            || c == 'i' || c == 'I'
            || c == 'u' || c == 'U';
    }

    string reverseVowels(string s) {
        int left = 0, right = s.size() - 1;
        while(left < right){
            while(!isVowel(s[left])) ++left;
            while(!isVowel(s[right])) --right;
            if(left < right){
                swap(s[left], s[right]);
            }
            ++left;
            --right;
        }
        return s;
    }
};

// a better solution
// credit: https://leetcode.com/discuss/99351/c-12ms-two-pointers-easy-to-understand
class Solution {
public:
    string reverseVowels(string s) {
        int left = 0, right = s.size() - 1;
        string vowels = "aoeiuAOEIU";
        while(left < right){
            while(vowels.find(s[left]) == string::npos && left < right) ++left;
            while(vowels.find(s[right]) == string::npos && left < right) --right;
            if(left < right) swap(s[left++], s[right--]);
        }
        return s;
    }
};