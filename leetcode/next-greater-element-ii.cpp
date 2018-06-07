/*
Given a circular array (the next element of the last element is the first element of the array), print the Next Greater Number for every element. The Next Greater Number of a number x is the first greater number to its traversing-order next in the array, which means you could search circularly to find its next greater number. If it doesn't exist, output -1 for this number.

Example 1:
Input: [1,2,1]
Output: [2,-1,2]
Explanation: The first 1's next greater number is 2; 
The number 2 can't find next greater number; 
The second 1's next greater number needs to search circularly, which is also 2.
Note: The length of given array won't exceed 10000.
*/

// 105ms
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        // can change deque to stack by storing the index of the first largest value
        deque<int> indices;
        int n = nums.size();
        vector<int> res(n, -1);
        if(n == 0) return res;
        for(int i = 0; i < n; ++i){
            while(!indices.empty() && nums[indices.back()] < nums[i]){
                res[indices.back()] = nums[i];
                indices.pop_back();
            }
            indices.push_back(i);
        }
        // consider the case [6, 7, 7, 5, 4]
        int max_idx = indices.front();
        if(nums[max_idx] == nums[indices.back()])
            return res;
        for(int i = 0; i <= max_idx; ++i){
            while(!indices.empty() && nums[indices.back()] < nums[i]){
                res[indices.back()] = nums[i];
                indices.pop_back();
            }
        }
        return res;
    }
};

// simpler solution
// but not faster because of two passes for all cases
// 119ms
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, -1);
        if(n == 0) return res;
        stack<int> indices;
        for(int i = 0; i < 2 * n; ++i){
            while(!indices.empty() && nums[indices.top()] < nums[i % n]){
                res[indices.top()] = nums[i % n];
                indices.pop();
            }
            if(i < n) indices.push(i);
        }
        return res;
    }
};
