/*
Implement strStr().

Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
*/

// TODO: KMP algorithm

// more concise and elegant soluton
// brute force
class Solution {
public:
    int strStr(string haystack, string needle) {
        for(int i = 0; i <= (int)(haystack.size() - needle.size()); ++i){
            int j = 0;
            while(j < needle.size() && haystack[i+j] == needle[j])
                ++j;
            if(j == needle.size())
                return i;
        }
        return -1;
    }
};

// my solution
class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.empty()){
            return 0;
        }
        int diff = haystack.size() - needle.size();
        // if haystack.size() < needle.size(), overflow occurs, because size_t is unsigned
        //for(int i = 0; i <= haystack.size() - needle.size(); ++i){
        for(int i = 0; i <= diff; ++i){
            if(haystack[i] == needle[0]){
                int j = 1;
                for(; j < needle.size(); ++j){
                    if(haystack[i+j] != needle[j]){
                        break;
                    }
                }
                if(j == needle.size()){
                    return i;
                }
            }
        }
        return -1;
    }
};
