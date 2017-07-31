/*
Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

For example,
"A man, a plan, a canal: Panama" is a palindrome.
"race a car" is not a palindrome.

Note:
Have you consider that the string might be empty? This is a good question to ask during an interview.

For the purpose of this problem, we define empty string as valid palindrome.
*/

class Solution {
public:
    bool isPalindrome(string s) {
        if(s.empty()){
            return true;
        }
        
        int i = 0;
        int j = s.size() - 1;
        for(; i < j; ++i, --j){
            while(i < j && !isValidChar(s[i])){
                ++i;
            }
            while(i < j && !isValidChar(s[j])){
                --j;
            }
            if(tolower(s[i]) != tolower(s[j])){
            //if(s[i] != s[j] && abs(s[i] - s[j]) != abs('A' - 'a')){ // wrong because abs('0', 'P') == abs('A', 'a')
                return false;
            }
        }
        return true;
    }
    
    bool isValidChar(char c){
        return (c >= '0' && c <= '9') || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
    }

    char tolower(char c){
    	if(c >= 'A' && c <= 'Z'){
    		c = c - ('A' - 'a');
    	}
    	return c;
    }
};

// use library functions
class Solution {
public:
    bool isPalindrome(string s) {
        if(s.empty()){
            return true;
        }
        int i = 0;
        int j = s.size() - 1;
        for(; i < j; ++i, --j){
            while(i < j && !isalnum(s[i])){ // isalnum(): check if character is alphanumeric
                ++i;
            }
            while(i < j && !isalnum(s[j])){
                --j;
            }
            if(tolower(s[i]) != tolower(s[j])){
                return false;
            }
        }
        return true;
    }
};
