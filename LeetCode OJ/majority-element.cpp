/*
Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.

You may assume that the array is non-empty and the majority element always exist in the array.
*/

/*
Moore’s Voting Algorithm
detailed explanation: http://www.codinghelmet.com/?path=exercises/majority-element
see also: http://www.geeksforgeeks.org/majority-element/
*/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = nums[0];
        int counter = 1;
        for(int i=1; i<nums.size(); ++i){
            if(candidate == nums[i])
                ++counter;
            else
                --counter;
            if(counter == 0){
                candidate = nums[i];
                counter = 1;
            }
        }
        /*
        // check whether the candidate is indeed a majority element
        int n = 0;
        for(int i=0; i<nums.size(); ++i){
            if(nums[i] == candidate)
                ++n;
        }
        if(n > nums.size() / 2)
            return candidate;
        else
            // majority element does not exist
        */
        // since the majority element always exists, no need to confirm
        return candidate;
    }
};
