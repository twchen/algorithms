/*
Follow up for "Remove Duplicates":
What if duplicates are allowed at most twice?

For example,
Given sorted array nums = [1,1,1,2,2,3],

Your function should return length = 5, with the first five elements of nums being 1, 1, 2, 2 and 3. It doesn't matter what you leave beyond the new length.
 */
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int size = nums.size();
        if(size < 2) return size;
        int n = 1, prev = nums[0];
        bool duplicated = false;
        for(int i=1; i<size; ++i){
            int cur = nums[i];
            if(cur != prev){
                nums[n++] = prev = cur;
                duplicated = false;
            }else if(!duplicated){
                nums[n++] = cur;
                duplicated = true;
            }
        }
        return n;
    }
};

// simpler solution, can be easily generalized to "at-most-k-duplicates" case
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0;
        for(int n: nums)
            if(i < 2 || n != nums[i-2])
                nums[i++] = n;
        return i;
    }
};
