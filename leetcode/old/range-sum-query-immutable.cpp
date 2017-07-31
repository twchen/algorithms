/*
Given an integer array nums, find the sum of the elements between indices i and j (i ≤ j), inclusive.

Example:
Given nums = [-2, 0, 3, -5, 2, -1]

sumRange(0, 2) -> 1
sumRange(2, 5) -> -1
sumRange(0, 5) -> -3
Note:
You may assume that the array does not change.
There are many calls to sumRange function.
*/


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.sumRange(1, 2);

// AC version
class NumArray {
public:
    NumArray(vector<int> &nums){
        sumtable.resize(nums.size());
        int sum = 0;
        for(int i=0; i<nums.size(); ++i){
            sum += nums[i];
            sumtable[i] = sum;
        }
    }
    
    int sumRange(int i, int j) {
        return i <= 0 ? sumtable[j] : (sumtable[j] - sumtable[i-1]);
    }
private:
    vector<int> sumtable;
};

// not accepted version 2
class NumArray {
public:
    NumArray(vector<int> &nums): mynums(nums) {
    }
    
    int sumRange(int i, int j) {
        // assume 0 <= i <= j < mynums.size()
        if(j - i < 10){
            int sum = 0;
            for(; i<=j; ++i)
                sum += mynums[i];
            return sum;
        }
        int u = (i + j) / 2;
        return sumRange(i, u) + sumRange(u+1, j);
    }
private:
    vector<int> &mynums;
};

// brute force, not accepted version 1
class NumArray {
public:
    NumArray(vector<int> &nums): mynums(nums) {
    }
    
    int sumRange(int i, int j) {
        if(i < 0 || j >= mynums.size())
            return 0;
        int sum = 0;
        for(; i<=j; ++i)
            sum += mynums[i];
        return sum;
    }
private:
    vector<int> &mynums;
};
