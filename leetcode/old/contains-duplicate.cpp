/*
Given an array of integers, find if the array contains any duplicates. Your function should return true if any value appears at least twice in the array, and it should return false if every element is distinct.
*/

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> myset;
        vector<int>::iterator it;
        for(it = nums.begin(); it != nums.end(); ++it){
            if(myset.insert(*it).second == false)
                return true;
        }
        return false;
    }
};
