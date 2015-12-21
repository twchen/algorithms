/*
Given two strings s and t, write a function to determine if t is an anagram of s.

For example,
s = "anagram", t = "nagaram", return true.
s = "rat", t = "car", return false.

Note:
You may assume the string contains only lowercase alphabets.

Follow up:
What if the inputs contain unicode characters? How would you adapt your solution to such case?
*/

class Solution {
public:
    /*
    // simple solution
    bool isAnagram(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s == t;
    }
    */
    bool isAnagram(string s, string t){
        if(s.size() != t.size())
            return false;
        int mymap[26] = {0}; // "If an explicit array size is specified, but an shorter initiliazation list is specified, the unspecified elements are set to zero. "
        for(int i=0; i<s.size(); ++i)
            mymap[s[i] - 'a']++;
        for(int i=0; i<t.size(); ++i)
            if(--mymap[t[i] - 'a'] < 0) // if t is not an anagram of s, t must have some chars that s does not have or t has more;
                return false;
        return true;
    }
};
