/*
Given an array of integers and an integer k, you need to find the total number of continuous subarrays
whose sum equals to k.

Example 1:
Input:nums = [1,1,1], k = 2
Output: 2
Note:
The length of the array is in range [1, 20,000].
The range of numbers in the array is [-1000, 1000] and the range of the integer k is [-1e7, 1e7].
*/

// O(n^2) time, O(n) space
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> sums(n + 1);
        int sum = 0;
        for(int i = 0; i < n; ++i){
            sum += nums[i];
            sums[i + 1] = sum;
        }
        int count = 0;
        for(int i = 0; i < n; ++i)
            for(int j = i; j < n; ++j)
                if(sums[j + 1] - sums[i] == k)
                    ++count;
        return count;
    }
};

// O(n) time, O(n) space
// credit: https://leetcode.com/problems/subarray-sum-equals-k/discuss/102106/Java-Solution-PreSum-+-HashMap
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> presum;
        presum[0] = 1;
        int sum = 0; // sum of first i numbers in nums
        int count = 0;
        for(int i = 0; i < n; ++i){
            sum += nums[i];
            // presum[key]: number of subarrays of nums[0..j], where j < i and sum(nums[0..j]) == key
            auto it = presum.find(sum - k);
            if(it != presum.end())
                count += it->second;
            ++presum[sum];
        }
        return count;
    }
};
