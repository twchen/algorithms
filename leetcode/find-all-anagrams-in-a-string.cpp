/*
Given a string s and a non-empty string p, find all the start indices of p's anagrams in s.

Strings consists of lowercase English letters only and the length of both strings s and p will not be larger than 20,100.

The order of output does not matter.

Example 1:

Input:
s: "cbaebabacd" p: "abc"

Output:
[0, 6]

Explanation:
The substring with start index = 0 is "cba", which is an anagram of "abc".
The substring with start index = 6 is "bac", which is an anagram of "abc".
Example 2:

Input:
s: "abab" p: "ab"

Output:
[0, 1, 2]

Explanation:
The substring with start index = 0 is "ab", which is an anagram of "ab".
The substring with start index = 1 is "ba", which is an anagram of "ab".
The substring with start index = 2 is "ab", which is an anagram of "ab".
*/

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> indices;
        
        int left = 0, right = 0;
        // current substring s.substr(left, right - left)
        
        vector<int> hash(26, 0);
        // hash[c - 'a']: number of c in p - number of c in s.substr(left, right - left)
        for(char c: p){
            ++hash[c - 'a'];
        }
        
        int count = p.size();
        // count: number of characters in p but not in s.substr(left, right - left)
        // count also equals to the sum of positive values in hash
        
        while(right < s.size()){
            if(hash[s[right] - 'a'] > 0) --count;
            --hash[s[right] - 'a'];
            
            ++right;
            
            if(right - left == p.size()){
                if(count == 0) indices.push_back(left);
                
                if(hash[s[left] - 'a'] >= 0) ++count;
                ++hash[s[left] - 'a'];
                
                ++left;
            }
        }
        return indices;
        
        // original solution
        /*
        int n1 = s.size();
        int n2 = p.size();
        vector<int> indices;
        if(n1 < n2) return indices;
        vector<int> m(26, 0);
        for(char c: p) ++m[c - 'a']; // m[c -'a']: number of c in p - number of c in the current substring of s
        int diff = n2; // number of characters in p but not in the current substring of s
        // the sum of all positive values in m
        for(int i = 0; i < n2; ++i){
            --m[s[i] - 'a'];
            if(m[s[i] - 'a'] >= 0) --diff;
        }
        if(diff == 0) indices.push_back(0);
        for(int i = n2; i < n1; ++i){
            ++m[s[i-n2] - 'a'];
            if(m[s[i-n2] - 'a'] > 0) ++diff;
            --m[s[i] - 'a'];
            if(m[s[i] - 'a'] >= 0) --diff;
            if(diff == 0) indices.push_back(i-n2+1);
        }
        return indices;
        */
    }
};
