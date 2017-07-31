/*
Given an array of integers and an integer k, find out whether there are two distinct indices i and j in the array such that nums[i] = nums[j] and the difference between i and j is at most k.
*/

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        set<int> myset;
        for(int i=0; i<nums.size(); ++i){
            if(myset.insert(nums[i]).second == false){
                return true;
            }
            if(i >= k){
                myset.erase(nums[i-k]);
            }
        }
        return false;
    }
};
