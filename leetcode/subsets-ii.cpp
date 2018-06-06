/*
Given a collection of integers that might contain duplicates, nums, return all possible subsets.

Note: The solution set must not contain duplicate subsets.

For example,
If nums = [1,2,2], a solution is:

[
  [2],
  [1],
  [1,2,2],
  [2,2],
  [1,2],
  []
]

 */

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        unordered_map<int, int> m;
        for(int n : nums){
            ++m[n];
        }
        vector<vector<int>> subsets = {{}};
        for(auto it = m.begin(); it != m.end(); ++it){
            int size = subsets.size();
            vector<int> v;
            for(int i = 0; i < it->second; ++i){
                v.push_back(it->first);
                for(int j = 0; j < size; ++j){
                    vector<int> w(subsets[j]);
                    w.insert(w.end(), v.begin(), v.end());
                    subsets.push_back(std::move(w));
                }
            }
        }
        return subsets;
    }
};
