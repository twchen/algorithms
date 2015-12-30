/*
Given two strings s and t, determine if they are isomorphic.

Two strings are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character but a character may map to itself.

For example,
Given "egg", "add", return true.

Given "foo", "bar", return false.

Given "paper", "title", return true.

Note:
You may assume both s and t have the same length.
*/

// very smart solution
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int map[256] = {0}, rmap[256] = {0};
        for(int i=0; i<s.size(); ++i){
            if(map[s[i]] != rmap[t[i]]){
                // if s[i] and t[i] are not mapped, map[s[i]] == map[t[i]] == 0
                // if either s[i] or t[i] is mapped, they must be equal, s[i] --> i + 1 <-- t[i]
                return false;
            }
            map[s[i]] = i + 1;
            rmap[t[i]] = i + 1;
            // s[i] --> i + 1 <-- t[i], so s[i] is mapped to t[i]
            // not neccessarily i + 1, as long as each mapping has a distinct value and the value should be different from the initialized value
            // so i + 1 can be changed to 2*i + 1, i*i + 2 ...
        }
        return true;
    }
};

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char, char> mymap;
        set<char> myset;
        for(int i=0; i<s.size(); ++i){
            if(mymap.insert(pair<char, char>(s[i], t[i])).second){ // new mapping
                if(myset.insert(t[i]).second == false) // check if t[i] is already mapped. (same char cannot be mapped by two different chars)
                    return false;
            }else if(mymap[s[i]] != t[i]){
                return false;
            }
        }
        return true;
    }
};
