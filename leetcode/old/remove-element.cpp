/*
Given an array and a value, remove all instances of that value in place and return the new length.

The order of elements can be changed. It doesn't matter what you leave beyond the new length.
*/

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int size = nums.size();
        int num = 0;
        for(int i=0; i<size-num;){
            if(nums[i] == val){
                ++num;
                swap(nums[i], nums[size - num]);
            }
            else{
                ++i;
            }
        }
        return size - num;
    }
};
