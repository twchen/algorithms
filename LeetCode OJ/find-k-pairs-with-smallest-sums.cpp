/*
You are given two integer arrays nums1 and nums2 sorted in ascending order and an integer k.

Define a pair (u,v) which consists of one element from the first array and one element from the second array.

Find the k pairs (u1,v1),(u2,v2) ...(uk,vk) with the smallest sums.

Example 1:
Given nums1 = [1,7,11], nums2 = [2,4,6],  k = 3

Return: [1,2],[1,4],[1,6]

The first 3 pairs are returned from the sequence:
[1,2],[1,4],[1,6],[7,2],[7,4],[11,2],[7,6],[11,4],[11,6]
Example 2:
Given nums1 = [1,1,2], nums2 = [1,2,3],  k = 2

Return: [1,1],[1,1]

The first 2 pairs are returned from the sequence:
[1,1],[1,1],[1,2],[2,1],[1,2],[2,2],[1,3],[1,3],[2,3]
Example 3:
Given nums1 = [1,2], nums2 = [3],  k = 3 

Return: [1,3],[2,3]

All possible pairs are returned from the sequence:
[1,3],[2,3]
 */

class Solution {
public:
    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        pairs.clear();
        vector<pair<int, int>> res;
        if(k <= 0 || nums1.size() == 0 || nums2.size() == 0) return res;
        insert(0, 0, nums1, nums2);
        while(k--){
            auto p = pairs.front();
            pairs.pop_front();
            res.push_back(pair<int, int>(nums1[p.first], nums2[p.second]));
            if(p.first + 1 == nums1.size() && p.second + 1 == nums2.size()) break;
            if(p.first + 1 < nums1.size()) insert(p.first + 1, p.second, nums1, nums2);
            if(p.second + 1 < nums2.size()) insert(p.first, p.second + 1, nums1, nums2);
        }
        return res;
    }

    void insert(int i, int j, const vector<int> &nums1, const vector<int> &nums2){
        auto it = pairs.begin();
        for(; it != pairs.end(); ++it){
            auto p = *it;
            if(nums1[i] + nums2[j] < nums1[p.first] + nums2[p.second]) break;
            else if(i == p.first && j == p.second) return;
        }
        pairs.insert(it, pair<int, int>(i, j));
    }
private:
    list<pair<int, int>> pairs;
};

// If we get a current minimum at (i, j) (indices), we need to push (i+1, j), (i, j+1) into heap
// E.g. if we get a minimum at (2, 3), we will push (3, 3) and (2, 4), but the problem is that
// (3, 3) is pushed again when we are at (3, 2).
// To avoid pushing (3, 3) twice, when we are at (2, 3), we can just push (2, 4), and we push (3, 3) when we are at (3, 2)
// This is okay because when we are at (2, 3), there are 3 possible cases for (3, 2)
// Case 1: (3, 2) has been already poped from the heap, then (3, 3) must have been pushed. It can be the next minimum
// Case 2: (3, 2) is still in the heap. Case 3: (3, 2) is not yet pushed into the heap.
// In both cases, (3, 3) cannot be the next minimum because (3, 2) is guaranteed to be no greater than (3, 3),
// so we can push (3, 3) into the heap after we have poped (3, 2)
// Therefore, when we are at (i, j), we can just push (i, j+1), and (i+1, j) will be pushed when we see (i+1, j-1).
// The only exception to this is, when j=0, there is no (i+1, j-1) anymore, so we need to push both (i, j+1) and (i+1, j) when j=0;
class Solution {
public:
    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        pairs.clear();
        vector<pair<int, int>> res;
        if(k <= 0 || nums1.size() == 0 || nums2.size() == 0) return res;
        insert(0, 0, nums1, nums2);
        while(k-- && !pairs.empty()){
            auto p = pairs.front();
            pairs.pop_front();
            res.push_back(pair<int, int>(nums1[p.first], nums2[p.second]));
            if(p.second == 0 && p.first + 1 < nums1.size())
                insert(p.first + 1, p.second, nums1, nums2);
            if(p.second + 1 < nums2.size())
                insert(p.first, p.second + 1, nums1, nums2);
        }
        return res;
    }

    void insert(int i, int j, const vector<int> &nums1, const vector<int> &nums2){
        auto it = pairs.begin();
        for(; it != pairs.end(); ++it){
            auto p = *it;
            if(nums1[i] + nums2[j] < nums1[p.first] + nums2[p.second]) break;
        }
        pairs.insert(it, pair<int, int>(i, j));
    }
private:
    list<pair<int, int>> pairs;
};

// same idea but using STL
class Solution {
public:
    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int, int>> res;
        if(nums1.empty() || nums2.empty() || k <= 0) return res;
        auto comp = [&nums1, &nums2](pair<int, int> a, pair<int, int> b)->bool{
            return nums1[a.first] + nums2[a.second] > nums1[b.first] + nums2[b.second];
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> heap(comp);
        heap.emplace(0, 0);
        while(k-- && !heap.empty()){
            auto p = heap.top();
            res.emplace_back(nums1[p.first], nums2[p.second]);
            heap.pop();
            if(p.first + 1 < nums1.size())
                heap.emplace(p.first + 1, p.second);
            if(p.first == 0 && p.second + 1 < nums2.size())
                heap.emplace(p.first, p.second + 1);
        }
        return res;
    }
};
