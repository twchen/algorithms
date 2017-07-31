/*
Given an integer array with all positive numbers and no duplicates, find the number of possible combinations that add up to a positive integer target.

Example:

nums = [1, 2, 3]
target = 4

The possible combination ways are:
(1, 1, 1, 1)
(1, 1, 2)
(1, 2, 1)
(1, 3)
(2, 1, 1)
(2, 2)
(3, 1)

Note that different sequences are counted as different combinations.

Therefore the output is 7.
Follow up:
What if negative numbers are allowed in the given array?
How does it change the problem?
What limitation we need to add to the question to allow negative numbers?
*/

// time limit exceeded
// running time: O(N), where N is the number os combinations
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        if(target == 0) return 1;
        if(target < 0) return 0;
        int count = 0;
        for(int i=0; i<nums.size(); ++i){
            count += combinationSum4(nums, target - nums[i]);
        }
        return count;
    }
};

class Solution {
public:
    int combinationSum4(vector<int> &nums, int target){
        sort(nums.begin(), nums.end());
        vector<int> coms(target+1, 0);
        // coms[i]: number of combinations that sum up to i
        coms[0] = 1;
        for(int i=1; i<=target; ++i){
            for(int j=0; j < nums.size() && nums[j] <= i; ++j){
                coms[i] += coms[i - nums[j]]; // number of combinations that sum up to i and start with nums[j]
            }
        }
        return coms.back();
    }
};

// answers to follow up
// limitation: there is no combinations that sum up to 0
