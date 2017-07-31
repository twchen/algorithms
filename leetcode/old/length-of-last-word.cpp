/*
Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.

If the last word does not exist, return 0.

Note: A word is defined as a character sequence consists of non-space characters only.

For example, 
Given s = "Hello World",
return 5.
*/

// I like my solution
class Solution {
public:
    int lengthOfLastWord(string s) {
        int i = s.size();
        int len = 0;
        while(i--){
            if(s[i] != ' ')
                ++len;
            else if(len > 0)
                break;
        }
        return len;
    }
};
