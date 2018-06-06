/*
Given a non-empty list of words, return the k most frequent elements.

Your answer should be sorted by frequency from highest to lowest. If two words have the same frequency, then the word with the lower alphabetical order comes first.

Example 1:
Input: ["i", "love", "leetcode", "i", "love", "coding"], k = 2
Output: ["i", "love"]
Explanation: "i" and "love" are the two most frequent words.
    Note that "i" comes before "love" due to a lower alphabetical order.
Example 2:
Input: ["the", "day", "is", "sunny", "the", "the", "the", "sunny", "is", "is"], k = 4
Output: ["the", "is", "sunny", "day"]
Explanation: "the", "is", "sunny" and "day" are the four most frequent words,
    with the number of occurrence being 4, 3, 2 and 1 respectively.
Note:
You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
Input words contain only lowercase letters.
Follow up:
Try to solve it in O(n log k) time and O(n) extra space.
*/

// suppose n = # of words, and maximum length of words is constant
// running time O(n log n), space O(n)
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> hash;
        // time: O(n)
        for(string &w : words){
            ++hash[w];
        }
        // time: O(n)
        vector<pair<string, int>> tuples(hash.begin(), hash.end());
        // time: O(n log n)
        // one algorithm to make it O(n log k)
        // sort the first k tuples (O(k log k))
        // for tuple k+1 to tuple n:
        //     use binary search to find the right place to insert the new tuple
        // O(n log k)
        // then the first k tuples are the k most frequent elements
        sort(tuples.begin(), tuples.end(), [](pair<string, int> a, pair<string, int> b){
            return a.second > b.second || (a.second == b.second && a.first < b.first);
        });
        vector<string> res;
        // time: O(k)
        for(int i = 0; i < k; ++i){
            res.push_back(tuples[i].first);
        }
        return res;
    }
};

// running time O(n + k log n) (better than O(n log k)), space O(n)
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> freqs;
        for(string &w : words){
            ++freqs[w];
        }
        auto comp = [](pair<string, int> a, pair<string, int> b){
            return (a.second < b.second) || (a.second == b.second && a.first > b.first);
        };
        typedef priority_queue< pair<string, int>, vector<pair<string, int>>, decltype(comp) > MaxHeap;
        // build heap O(n)
        auto heap = MaxHeap(freqs.begin(), freqs.end(), comp);
        
        // k extract max operations
        // time: O(k log n)
        vector<string> res;
        for(int i = 0; i < k; ++i){
            const string &w = heap.top().first;
            res.push_back(w);
            heap.pop();
        }
        return res;
    }
};
