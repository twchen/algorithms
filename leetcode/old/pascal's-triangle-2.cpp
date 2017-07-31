/*
Given an index k, return the kth row of the Pascal's triangle.

For example, given k = 3,
Return [1,3,3,1].

Note:
Could you optimize your algorithm to use only O(k) extra space?
*/

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        if(rowIndex < 0)
            return vector<int>();
        vector<int> ret(rowIndex + 1);
        int prev, curr;
        for(int i=0; i <= rowIndex; ++i){
            prev = 0;
            for(int j=0; j<i; ++j){
                curr = ret[j];
                ret[j] = prev + curr;
                prev = curr;
            }
            ret[i] = 1;
        }
        return ret;
    }
};
