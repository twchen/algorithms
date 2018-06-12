/*
Given a nested list of integers represented as a string, implement a parser to deserialize it.

Each element is either an integer, or a list -- whose elements may also be integers or other lists.

Note: You may assume that the string is well-formed:

String is non-empty.
String does not contain white spaces.
String contains only digits 0-9, [, - ,, ].
Example 1:

Given s = "324",

You should return a NestedInteger object which contains a single integer 324.
Example 2:

Given s = "[123,[456,[789]]]",

Return a NestedInteger object containing a nested list with 2 elements:

1. An integer containing value 123.
2. A nested list containing two elements:
    i.  An integer containing value 456.
    ii. A nested list with one element:
         a. An integer containing value 789.
*/

/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
public:
    NestedInteger deserialize(string s) {
        stack<NestedInteger *> st;
        int n = s.size();
        for(int i = 0; i < n; ){
            int j = i;
            while(j < n && s[j] != '[' && s[j] != ']' && s[j] != ',') ++j;
            if(j > i){
                int num = stoi(s.substr(i, j - i));
                st.push(new NestedInteger(num));
            }
            if(j == n) break;
            if(s[j] == '[') st.push(nullptr); // use nullptr to denote the start of a nested list
            else if(s[j] == ']'){
                stack<NestedInteger *> lst;
                while(st.size() && st.top()){
                    lst.push(st.top());
                    st.pop();
                }
                // nullptr
                if(st.size()) st.pop();
                auto node = new NestedInteger();
                while(lst.size()){
                    node->add(*lst.top());
                    lst.pop();
                }
                st.push(node);
            }
            i = j + 1;
        }
        return *st.top();
    }
};

class Solution {
public:
    NestedInteger deserialize(string s) {
        stack<NestedInteger *> st; // the non-closed nested lists (haven't seen a ']')
        NestedInteger dummy;
        st.push(&dummy); 
        int n = s.size();
        for(int i = 0; i < n; ){
            int j = i;
            while(j < n && s[j] != '[' && s[j] != ']' && s[j] != ',') ++j;
            if(j > i){
                int val = stoi(s.substr(i, j - i));
                st.top()->add(NestedInteger(val));
            }
            if(j == n) break;
            if(s[j] == '['){
                // open a new nested list
                st.top()->add(NestedInteger());
                auto p = &(st.top()->getList().back());
                st.push(p);
            }else if(s[j] == ']'){
                // close the current nested list
                st.pop();
            }
            i = j + 1;
        }
        return dummy.getList()[0];
    }
};
