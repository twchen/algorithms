/*
Given a string, sort it in decreasing order based on the frequency of characters.

Example 1:

Input:
"tree"

Output:
"eert"

Explanation:
'e' appears twice while 'r' and 't' both appear once.
So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.
Example 2:

Input:
"cccaaa"

Output:
"cccaaa"

Explanation:
Both 'c' and 'a' appear three times, so "aaaccc" is also a valid answer.
Note that "cacaca" is incorrect, as the same characters must be together.
Example 3:

Input:
"Aabb"

Output:
"bbAa"

Explanation:
"bbaA" is also a valid answer, but "Aabb" is incorrect.
Note that 'A' and 'a' are treated as two different characters.
*/

class Solution {
public:
    string frequencySort(string s) {
        vector<int> freqs(256, 0);
        for(auto c : s){
            ++freqs[c];
        }
        vector<pair<int, int>> heap(256); // elements in heap: (char, frequency of char)
        for(int i = 0; i < 256; ++i){
            heap[i] = make_pair(i, freqs[i]);
        }
        auto comp = [](pair<int, int> &a, pair<int, int> &b){
            return a.second < b.second; 
        };
        make_heap(heap.begin(), heap.end(), comp);
        int i = 0;
        while(true){
            auto p = heap.front();
            if(p.second <= 0) break;
            pop_heap(heap.begin(), heap.end(), comp);
            heap.pop_back();
            for(int j = i; j < i + p.second; ++j){
                s[j] = p.first; 
            }
            i += p.second;
        }
        return s;
    }
};

class Solution {
public:
    string frequencySort(string s) {
        vector<int> freqs(256, 0);
        for(auto c : s){
            ++freqs[c];
        }
        vector<int> indices(256);
        iota(indices.begin(), indices.end(), 0); // fill indices from 0 to 255
        auto comp = [&freqs](int a, int b){
            return freqs[a] > freqs[b];
        };
        sort(indices.begin(), indices.end(), comp); // effectively achieving argsort
        int i = 0;
        for(int idx : indices){
            if(freqs[idx] <= 0) break;
            for(int j = i; j < i + freqs[idx]; ++j)
                s[j] = idx;
            i += freqs[idx];
        }
        return s;
    }
};

class Solution {
public:
    string frequencySort(string s) {
        vector<int> freqs(256, 0);
        for(auto c : s){
            ++freqs[c];
        }
        vector<int> indices;
        // keep only indices with frequencies > 0
        for(int i = 0; i < 256; ++i)
            if(freqs[i] > 0)
                indices.push_back(i);
        auto comp = [&freqs](int a, int b){
            return freqs[a] > freqs[b];
        };
        sort(indices.begin(), indices.end(), comp);
        int i = 0;
        for(int idx : indices){
            for(int j = i; j < i + freqs[idx]; ++j)
                s[j] = idx;
            i += freqs[idx];
        }
        return s;
    }
};
