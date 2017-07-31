/*
There are two sorted arrays nums1 and nums2 of size m and n respectively.

Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

Example 1:
nums1 = [1, 3]
nums2 = [2]

The median is 2.0
Example 2:
nums1 = [1, 2]
nums2 = [3, 4]

The median is (2 + 3)/2 = 2.5
*/

/*
There are two sorted arrays nums1 and nums2 of size m and n respectively.

Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

Example 1:
nums1 = [1, 3]
nums2 = [2]

The median is 2.0
Example 2:
nums1 = [1, 2]
nums2 = [3, 4]

The median is (2 + 3)/2 = 2.5
*/

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        if(m > n) return findMedianSortedArrays(nums2, nums1); // make sure nums1 is the shorter one
        
        if(n == 0) return 0.0; // two empty arrays

        int from = 0, end = m;
        int i , j;
        while(from <= end){
            i = (from + end) / 2; // left of short vector has i elements
            j = (m + n) / 2 - i; // left of long vector has j elements
            if(i > 0 && nums1[i-1] > nums2[j]){ // i too large
                end = i - 1;
            } else if(i < m && nums2[j-1] > nums1[i]){ // i too small
                from = i + 1;
            } else {
                break;
            }
        }

        int left_max = (i == 0 ? nums2[j-1] : (j == 0 ? nums1[i-1] : max(nums1[i-1], nums2[j-1])));
        int right_min = (i == m ? nums2[j] : (j == n ? nums1[i] : min(nums1[i], nums2[j])));
        if((m + n) % 2 == 1){
            return static_cast<double>(right_min);
        } else {
            return (left_max + right_min) / 2.0;
        }
    }
};
