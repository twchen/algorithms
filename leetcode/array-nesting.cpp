/*
A zero-indexed array A of length N contains all integers from 0 to N-1. Find and return the longest length of set S,
where S[i] = {A[i], A[A[i]], A[A[A[i]]], ... } subjected to the rule below.

Suppose the first element in S starts with the selection of element A[i] of index = i, the next element in S should
be A[A[i]], and then A[A[A[i]]]… By that analogy, we stop adding right before a duplicate element occurs in S.

Example 1:
Input: A = [5,4,0,3,1,6,2]
Output: 4
Explanation: 
A[0] = 5, A[1] = 4, A[2] = 0, A[3] = 3, A[4] = 1, A[5] = 6, A[6] = 2.

One of the longest S[K]:
S[0] = {A[0], A[5], A[6], A[2]} = {5, 6, 2, 0}
Note:
N is an integer within the range [1, 20,000].
The elements of A are all distinct.
Each element of A is an integer within the range [0, N-1].
*/

class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int max_len = 0;
        unordered_set<int> s(nums.begin(), nums.end()); // stores unvisited indices
        while(!s.empty()){
            auto it = s.begin();
            int len = 0;
            do{
                s.erase(it);
                it = s.find(nums[*it]);
                ++len;
            }while(it != s.end());
            if(max_len < len)
                max_len = len;
        }
        return max_len;
    }
};

class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int n = nums.size();
        int max_len = 0;
        vector<bool> visited(n, false);
        for(int i = 0; i < n; ++i){
            if(visited[i]) continue;
            int len = 0;
            int j = i;
            do{
                ++len;
                visited[j] = true;
                j = nums[j];
            }while(!visited[j]);
            if(max_len < len)
                max_len = len;
        }
        return max_len;
    }
};

// O(n) time and O(1) extra space
// the input remains the same
// idea: subtract nums[i] by n when visiting i,
// so only visit i when nums[i] >= 0
// after visiting i, restore nums[i] by adding n to it. 
class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int n = nums.size();
        int max_len = 0;
        for(int i = 0; i < nums.size(); ++i){
            int idx = i, len = 0;
            while(nums[idx] >= 0){
                ++len;
                nums[idx] -= n;
                idx = nums[idx] + n;
            }
            if(max_len < len)
                max_len = len;
            nums[i] += n;
        }
        return max_len;
    }
};

// when the function finishes, nums become [0, 1, ..., n-1]
// an interesting solution, but not more efficient
class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int max_len = 0;
        for(int i = 0; i < nums.size(); ++i){
            int len = 1;
            while(nums[i] != i){
                swap(nums[i], nums[nums[i]]);
                ++len;
            }
            if(len > max_len)
                max_len = len;
        }
        return max_len;
    }
};
