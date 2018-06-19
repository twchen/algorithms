/*
Given an array nums, we call (i, j) an important reverse pair if i < j and nums[i] > 2*nums[j].

You need to return the number of important reverse pairs in the given array.

Example1:

Input: [1,3,2,3,1]
Output: 2
Example2:

Input: [2,4,3,5,1]
Output: 3
Note:
The length of the given array will not exceed 50,000.
All the numbers in the input array are in the range of 32-bit integer.
*/

class Solution {
public:
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        temp.resize(n);
        return countAndSort(nums, 0, n - 1);
    }

private:
    int countAndSort(vector<int> &nums, int first, int last){
        if(first >= last) return 0;
        int mid = (first + last) / 2;

        // count and sort subarrays
        int count = countAndSort(nums, first, mid) + countAndSort(nums, mid + 1, last);
        // count
        for(int i = first, j = mid + 1; i <= mid && j <= last; ){
            if(nums[i] > 2L * nums[j]){
                count += (mid - i + 1);
                ++j;
            }else{
                ++i;
            }
        }
        // merge
        for(int k = first, i = first, j = mid + 1; k <= last; ++k){
            if(i > mid || (j <= last && nums[i] > nums[j])) temp[k] = nums[j++];
            else temp[k] = nums[i++];
        }
        // copy
        for(int k = first; k <= last; ++k){
            nums[k] = temp[k];
        }
        return count;
    }

    vector<int> temp;
};

// more efficient implementation
// combine merge and copy
class Solution {
public:
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        vector<int> nums2(nums.begin(), nums.end());
        return countAndSort(nums, nums2, 0, n - 1);
    }
    
    // mergesort nums into nums2
    // before: nums[i] == nums2[i] for i in [first, last]
    // after: nums[first..mid], nums[mid+1..last], num2[first..last] are sorted
    int countAndSort(vector<int> &nums, vector<int> &nums2, int first, int last){
        if(first >= last) return 0;
        int mid = (first + last) / 2;
        // sort subarray
        int count = countAndSort(nums2, nums, first, mid) + countAndSort(nums2, nums, mid + 1, last);
        // count
        for(int i = first, j = mid + 1; i <= mid && j <= last; ){
            if(nums[i] > 2L * (long)nums[j]){
                count += (mid - i + 1);
                ++j;
            }else{
                ++i;
            }
        }
        // merge
        for(int k = first, i = first, j = mid + 1; k <= last; ++k){
            if(i > mid || (j <= last && nums[i] > nums[j])) nums2[k] = nums[j++];
            else nums2[k] = nums[i++];
        }
        return count;
    }
};