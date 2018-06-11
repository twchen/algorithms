/*
Given an unsorted array nums, reorder it such that nums[0] < nums[1] > nums[2] < nums[3]....

Example 1:

Input: nums = [1, 5, 1, 1, 6, 4]
Output: One possible answer is [1, 4, 1, 5, 1, 6].
Example 2:

Input: nums = [1, 3, 2, 2, 3, 1]
Output: One possible answer is [2, 3, 1, 3, 1, 2].
Note:
You may assume all input has valid answer.

Follow Up:
Can you do it in O(n) time and/or in-place with O(1) extra space?
*/
/*
 0 1 2 3
 1 3 5 7
 L L L M
M S S S S
4 5 6 7 8
0 2 4 6 8
Let L, M, S be the elements greater than, equal to and smaller than the median respectively.
Idea: 
1. Order the elements such that L come first, followed by M, then S. LLLMMSSSS
  (This step is similar to the partition procedure in quicksort, where the pivot is the median.
  The only difference is that the elements equal to the median are required to placed in the middle.)
2. Put the list to the original array such that it is wigglely sorted.
  i.e., the first half is placed at the odd indices, and the second half is placed at the even indices.
3. Since we know the ith element will be placed at index (1 + 2 * i) % (n | 1), we can combine step 1 and 2
*/

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        auto midptr = nums.begin() + n / 2;
        nth_element(nums.begin(), midptr, nums.end());
        int mid = *midptr;
        int i = 0, left = 0, right = n - 1;
        auto vidx = [n](int i){ return (1 + 2 * i) % (n | 1); };
        while(i <= right){
            if(nums[vidx(i)] > mid){
                // it is safe to increment i because i >= left
                // if i == left, trivial
                // if i > left, the element nums[vidx(left)] must be equal to mid
                // all elements nums[vidx(left)], nums[vidx(left+1)], ..., nums[vidx(i-1)] are equal to mid.
                // so in both cases, it is safe to increment i.
                swap(nums[vidx(i++)], nums[vidx(left++)]);
            }else if(nums[vidx(i)] < mid){
                // we don't increment i because we don't know whether the original element at vidx(right)
                // is larger than, equal to or smaler than mid.
                swap(nums[vidx(i)], nums[vidx(right--)]);
            }else{
                ++i;
            }
        }
    }
};

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        auto midptr = nums.begin() + n / 2;
        nth_element(nums.begin(), midptr, nums.end());
        int mid = *midptr;
        int i = 0, left = 0, right = n - 1;
        auto A = [n, &nums](int i)->int&{ return nums[(1 + 2 * i) % (n | 1)]; };
        while(i <= right){
            if(A(i) > mid){
                swap(A(i++), A(left++));
            }else if(A(i) < mid){
                swap(A(i), A(right--));
            }else{
                ++i;
            }
        }
    }
};
