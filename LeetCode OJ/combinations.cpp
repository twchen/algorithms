/*
Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

For example,
If n = 4 and k = 2, a solution is:

[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]
*/

// recursive
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> cur;
        combinations(n, k, cur, res);
        return res;
    }
    
    // choose k numbers from 1, 2, ..., n, given that numbers in cur must be included
    // possible combinations are pushed to res
    // n, k are non-negative numbers
    void combinations(int n, int k, vector<int> &cur, vector<vector<int>> &res){
        if(k == 0){
            res.push_back(cur);
            return;
        }
        if(n < k) return;
        // k >= 1, n >= k >= 1
        cur.push_back(n);
        combinations(n-1, k-1, cur, res); // choose n
        cur.pop_back();
        combinations(n-1, k, cur, res); // do not choose n
    }
};

// iterative
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> v1, v2;
        auto prev = &v1, cur = &v2;
        if(k <= 0) return v1;
        for(int i=1; i <= n-k+1; ++i){
            vector<int> v = { i };
            prev->push_back(v);
        }
        while(--k){
            cur->clear();
            for(int i=0; i < prev->size(); ++i){
                vector<int> &v = (*prev)[i];
                for(int j=v.back()+1; j <= n-k+1; ++j){
                    v.push_back(j);
                    cur->push_back(v);
                    v.pop_back();
                }
            }
            swap(prev, cur);
        }
        return (*prev);
    }
};
