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


// method 1
// references:
// https://leetcode.com/problems/median-of-two-sorted-arrays/discuss/2481/Share-my-O(log(min(mn))-solution-with-explanation
// https://leetcode.com/problems/median-of-two-sorted-arrays/solution/
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        if(n > m) return findMedianSortedArrays(nums2, nums1);
        int l = 0;
        int r = n;
        while(l <= r){
            int i = (l + r) / 2;
            int j = (m + n) / 2 - i;
            if(i > 0 && nums1[i-1] > nums2[j]){
                r = i - 1;
            }else if(i < n && nums2[j-1] > nums1[i]){
                l = i + 1;
            }else{
                int l_max, r_min;

                if(i == n) r_min = nums2[j];
                else if(j == m) r_min = nums1[i]; // in fact, i == 0
                else r_min = min(nums1[i], nums2[j]);

                if((n + m) % 2) return r_min;

                // m + n is even, not both of m and n are empty, so m + n >= 2
                if(i == 0) l_max = nums2[j-1];
                else if(j == 0) l_max = nums1[i-1]; // i != 0 and j == 0, so m == n
                else l_max = max(nums1[i-1], nums2[j-1]);

                return (l_max + r_min) / 2.0;
            }
        }
        return 0;
    }
};

// method 2
// reference: https://leetcode.com/problems/median-of-two-sorted-arrays/discuss/2496/Concise-JAVA-solution-based-on-Binary-Search
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        int k = (m + n + 1) / 2;
        double median = findKth(nums1, nums2, 0, 0, k);
        if((m + n) % 2)
            return median;
        else
            return (median + findKth(nums1, nums2, 0, 0, k+1)) / 2;
    }
    
    double findKth(vector<int>& nums1, vector<int>& nums2, int start1, int start2, int k){
        if(start1 >= nums1.size()) return nums2[start2 + k - 1];
        if(start2 >= nums2.size()) return nums1[start1 + k - 1];
        if(k == 1) return min(nums1[start1], nums2[start2]);
        
        int v1 = numeric_limits<int>::max();
        int v2 = numeric_limits<int>::max();
        if(start1 + k/2 - 1 < nums1.size()) v1 = nums1[start1 + k/2 - 1];
        if(start2 + k/2 - 1 < nums2.size()) v2 = nums2[start2 + k/2 - 1];
        if(v1 < v2)
            return findKth(nums1, nums2, start1 + k/2, start2, k - k/2);
        else
            return findKth(nums1, nums2, start1, start2 + k/2, k - k/2);
    }
};
