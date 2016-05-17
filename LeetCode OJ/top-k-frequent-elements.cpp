/*
Given a non-empty array of integers, return the k most frequent elements.

For example,
Given [1,1,1,2,2,3] and k = 2, return [1,2].

Note: 
You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
Your algorithm's time complexity must be better than O(n log n), where n is the array's size.
*/

class Solution {
public:
    typedef pair<int, int> Pair;
    struct CmpByValue {
        bool operator()(const Pair &lhs, const Pair &rhs){
            return rhs.second < lhs.second;
        }
    };
    bool static cmpByValue(const Pair &lhs, const Pair &rhs){
        return rhs.second < lhs.second;
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> mymap;
        for(auto n: nums){
            ++mymap[n];
        }
        vector<Pair> myvec(mymap.begin(), mymap.end());
        //sort(myvec.begin(), myvec.end(), CmpByValue());
        sort(myvec.begin(), myvec.end(), cmpByValue);
        vector<int> res(k, 0);
        for(int i = 0; i < k; ++i){
            res[i] = myvec[i].first;
        }
        return res;
    }
};
