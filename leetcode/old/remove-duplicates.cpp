/*
Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.

Do not allocate extra space for another array, you must do this in place with constant memory.

For example,
Given input array nums = [1,1,2],

Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively. It doesn't matter what you leave beyond the new length.
*/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int size = nums.size();
        if(size <= 1)
            return size;
        int n = 1;
        int curr = nums[0];
        for(int i=1; i<size; ++i){
            if(nums[i] != curr){
                curr = nums[i];
                nums[n++] = curr;
            }
        }
        return n;
    }
};

// simpler solution
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0;
        for(int n: nums)
            if(i < 1 || n != nums[i-1])
                nums[i++] = n;
        return i;
    }
};