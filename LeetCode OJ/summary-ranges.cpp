/*
Given a sorted integer array without duplicates, return the summary of its ranges.

For example, given [0,1,2,4,5,7], return ["0->2","4->5","7"].
*/

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> summary;
        int start = 0;
        for(int i = 0; i < nums.size(); ++i){
            while(i+1 < nums.size() && nums[i] + 1 == nums[i+1]){
                ++i;
            }
            if(i == start){
                summary.push_back(to_string(nums[i]));
            }else{
                summary.push_back(to_string(nums[start]) + "->" + to_string(nums[i]));
            }
            start = i+1;
        }
        return summary;
    }
};
