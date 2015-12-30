/*
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
*/

// my solution
class Solution {
public:
    Solution(){
        mymap[')'] = '(';
        mymap[']'] = '[';
        mymap['}'] = '{';
    }

    bool isValid(string s) {
        stack<char> mystack;
        for(int i=0; i<s.size(); ++i){
            char c = s[i];
            if(c == '(' || c == '[' || c == '{'){
                mystack.push(c);
            }else if(mystack.size() && mystack.top() == mymap[c]){ // assume the string contains only parentheses chars;
                mystack.pop();
            }else{
                mystack.push(c); // if mystack is empty
                break;
            }
        }
        return mystack.empty();
    }
    
private:
    map<char, char> mymap;
};

// more concise solution
class Solution {
public:
    bool isValid(string s) {
        stack<char> mystack;
        for(char c : s){
            if(c == '(' || c == '[' || c == '{'){
                mystack.push(c);
            }else{
                if(mystack.empty()) return false;
                if(c == ')' && mystack.top() != '(') return false;
                if(c == ']' && mystack.top() != '[') return false;
                if(c == '}' && mystack.top() != '{') return false;
                // assume the string contains only parentheses
                mystack.pop();
            }
        }
        return mystack.empty();
    }
};
