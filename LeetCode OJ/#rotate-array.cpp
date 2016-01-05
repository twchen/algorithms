/*
Rotate an array of n elements to the right by k steps.

For example, with n = 7 and k = 3, the array [1,2,3,4,5,6,7] is rotated to [5,6,7,1,2,3,4].

Note:
Try to come up as many solutions as you can, there are at least 3 different ways to solve this problem.
*/

// credit: https://leetcode.com/discuss/27387/summary-of-c-solutions

// space complexity: O(n)
class Solution {
public:
	// method 1: Make an extra copy and then rotate.
	void rotate(vector<int>& nums, int k) {
        vector<int> v(size);
        for(int i=0; i<size; ++i){
            v[(i + k) % size] = nums[i];
        }
        nums = v;
    }
};

// space complexity: O(1)
class Solution {
public:
    // method 2: Start from one element and keep rotating until we have rotated n different elements.
    void rotate(vector<int> &nums, int k){
        int n = nums.size();
        if(n <= 1 || k % n == 0) return;
        int start = 0, curr = 0, next;
        int val = nums[0];
        for(int i = 0; i < n; ++i){
            next = (curr + k) % n;
            swap(val, nums[next]);
            curr = next;
            if(next == start){
                ++start;
                curr = start;
                val = nums[curr];
            }
        }
    }
};

class Solution {
public:
    // method 3: Reverse the first n - k elements, the last k elements, and then all the n elements.
    void rotate(vector<int> &nums, int k){
        int n = nums.size();
        k %= n;
        reverse(nums, 0, n-k-1);
        reverse(nums, n-k, n-1);
        reverse(nums, 0, n-1);
    }
    
    void reverse(vector<int> &nums, int start, int end){
        while(start < end){
            swap(nums[start++], nums[end--]);
        }
    }
};

class Solution {
public:
    // method 4: Swap the last k elements with the first k elements.
    void rotate(vector<int> &nums, int k){
        int n = nums.size();
        int size = n, start = 0;
        for(; k = k % size; size -= k, start += k){
        	// Swap the last k elements with the first k elements. 
            // The last k elements will be in the correct positions
            // but we need to rotate the remaining (n - k) elements 
            // to the right by k steps.
            for(int i = 0; i < k; ++i){
                swap(nums[start + i], nums[n - k + i]);
            }
        }
    }
};

class Solution {
public:
    // method 5: very similar to method 4
    // Swap nums[n - 2*k,...,n - k - 1] with nums[n - k,...,n - 1].
    void rotate(vector<int> &nums, int k){
        int n = nums.size();
        for(; k = k % n; n -= k){
        	// nums[n - 2*k,...,n - k - 1] are in their correct positions now.
            // Need to rotate the elements of nums[0,...,n - k - 1] to the right 
            // by k % n steps
            for(int i = 0; i < k; ++i){
                int left = positive_mod(n - 2*k + i, n);
                int right = positive_mod(n - k + i, n);
                swap(nums[left], nums[right]);
            }
        }
    }

    int positive_mod(int i, int n){
        return (i % n + n) % n;
    }
};
