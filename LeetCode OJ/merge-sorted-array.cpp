/*
Merge Sorted Array:

Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.

Note:
You may assume that nums1 has enough space (size that is greater or equal to m + n) to hold additional elements from nums2. The number of elements initialized in nums1 and nums2 are m and n respectively.
*/

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m + n - 1;
        while(m && n)
            if(nums1[m-1] < nums2[n-1])
                nums1[i--] = nums2[--n];
            else
                nums1[i--] = nums1[--m];
        if(!m)
            while(n)
                nums1[i--] = nums2[--n];
    }
};
