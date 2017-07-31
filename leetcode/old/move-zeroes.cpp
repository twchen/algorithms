/*
Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.

For example, given nums = [0, 1, 0, 3, 12], after calling your function, nums should be [1, 3, 12, 0, 0].

Note:
You must do this in-place without making a copy of the array.
Minimize the total number of operations.
*/

// my solution
class Solution {
public:
	void moveZeroes(vector<int>& nums) {
		int i = 0;
		int pos = 0;
		int size = nums.size();
		// find the first zero
		while(i < size && nums[i] != 0){
			++i;
			++pos;
		}
		// special case, no zeroes
		if(i == size)
			return;
		for(; i<size; ++i){
			if(nums[i] != 0){
				nums[pos] = nums[i];
				++pos;
			}
		}
		// fill zeroes;
		for(; pos<size; ++pos){
			nums[pos] = 0;
		}
	}
};

/*
// better solution
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
    	// j: current position to place non-zero numbers
        for (int i = 0, j = 0; i < nums.size(); ++i) {
            if (nums[i]) {
                swap(nums[i], nums[j++]);
            }
        }
    }
};
*/
