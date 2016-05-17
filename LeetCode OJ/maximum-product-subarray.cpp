/*
Find the contiguous subarray within an array (containing at least one number) which has the largest product.

For example, given the array [2,3,-2,4],
the contiguous subarray [2,3] has the largest product = 6.
*/

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int max_pro = nums[0];
        int min_pro = nums[0];
        int curr_max = max_pro;
        for(int i = 1; i < nums.size(); ++i){
            if(nums[i] < 0) swap(max_pro, min_pro);
            max_pro = max(max_pro * nums[i], nums[i]);
            min_pro = min(min_pro * nums[i], nums[i]);
            curr_max = max(max_pro, curr_max);
        }
        return curr_max;
    }
};

// brute-force
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int max = nums[0];
        for(int i = 0; i < nums.size(); ++i){
            int prod = 1;
            for(int j = i; j < nums.size() && nums[j] != 0; ++j){
                prod *= nums[j];
                if(max < prod) max = prod;
            }
        }
        return max;
    }
};
