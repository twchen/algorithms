/*
Given numRows, generate the first numRows of Pascal's triangle.

For example, given numRows = 5,
Return

[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]
*/

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if(numRows < 1)
            return vector<vector<int>>();
        vector<vector<int>> p(numRows);
        p[0] = {1};
        for(int i=1; i<numRows; ++i){
            p[i].resize(i+1);
            p[i][0] = p[i][i] = 1;
            for(int j=1; j<i; ++j)
                p[i][j] = p[i-1][j-1] + p[i-1][j];
        }
        return p;
    }
};
