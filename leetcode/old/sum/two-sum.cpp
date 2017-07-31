/*
Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution.

Example:
Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
 */

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mymap;
        int first = -1, second = -1;
        for(int i=0; i<nums.size(); ++i){
            int diff = target - nums[i];
            if(mymap.find(diff) != mymap.end()){
                first = i;
                second = mymap[diff];
                break;
            }
            mymap[nums[i]] = i;
        }
        return vector<int>{first, second};
    }
};
