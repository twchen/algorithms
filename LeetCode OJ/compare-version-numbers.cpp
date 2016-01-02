/*
Compare two version numbers version1 and version2.
If version1 > version2 return 1, if version1 < version2 return -1, otherwise return 0.

You may assume that the version strings are non-empty and contain only digits and the . character.
The . character does not represent a decimal point and is used to separate number sequences.
For instance, 2.5 is not "two and a half" or "half way to version three", it is the fifth second-level revision of the second first-level revision.

Here is an example of version numbers ordering:

0.1 < 1.1 < 1.2 < 13.37
Credits:
*/

class Solution {
public:
    int compareVersion(string version1, string version2) {
        size_t i = 0, j = 0;
        for(; i < version1.size() || j < version2.size(); ++i, ++j){
            int v1 = mystoi(version1, i);
            int v2 = mystoi(version2, j);
            if(v1 != v2){
                return v1 > v2 ? 1 : -1;
            }
        }
        return 0;
    }
    
    int mystoi(const string &s, size_t &idx){
        int res = 0;
        for(; idx < s.size() && s[idx] != '.'; ++idx){
            res = res * 10 + (s[idx] - '0');
        }
        return res;
    }
};
