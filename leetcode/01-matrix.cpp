/*
Given a matrix consists of 0 and 1, find the distance of the nearest 0 for each cell.

The distance between two adjacent cells is 1.
Example 1: 
Input:

0 0 0
0 1 0
0 0 0
Output:
0 0 0
0 1 0
0 0 0
Example 2: 
Input:

0 0 0
0 1 0
1 1 1
Output:
0 0 0
0 1 0
1 2 1
Note:
The number of elements of the given matrix will not exceed 10,000.
There are at least one 0 in the given matrix.
The cells are adjacent in only four directions: up, down, left and right.
*/

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        queue<pair<int, int>> frontier;
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(matrix[i][j] == 0){
                    dist[i][j] = 0;
                    frontier.emplace(i, j);
                }
            }
        }
        int d = 1;
        while(frontier.size()){
            int size = frontier.size();
            for(int k = 0; k < size; ++k){
                auto p = frontier.front();
                int i = p.first;
                int j = p.second;
                frontier.pop();
                if(i > 0 && dist[i - 1][j] == INT_MAX){
                    frontier.emplace(i - 1, j);
                    dist[i - 1][j] = d;
                }
                if(i + 1 < m && dist[i + 1][j] == INT_MAX){
                    frontier.emplace(i + 1, j);
                    dist[i + 1][j] = d;
                }
                if(j > 0 && dist[i][j - 1] == INT_MAX){
                    frontier.emplace(i, j - 1);
                    dist[i][j - 1] = d;
                }
                if(j + 1 < n && dist[i][j + 1] == INT_MAX){
                    frontier.emplace(i, j + 1);
                    dist[i][j + 1] = d;
                }
            }
            ++d;
        }
        return dist;
    }
};

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, m + n));
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(matrix[i][j] == 0) dp[i][j] = 0;
                else{
                    if(i > 0) dp[i][j] = dp[i - 1][j] + 1;
                    if(j > 0 && dp[i][j] > dp[i][j - 1] + 1) dp[i][j] = dp[i][j - 1] + 1;
                }
            }
        }
        for(int i = m - 1; i >= 0; --i){
            for(int j = n - 1; j >= 0; --j){
                if(i + 1 < m && dp[i][j] > dp[i + 1][j] + 1) dp[i][j] = dp[i + 1][j] + 1;
                if(j + 1 < n && dp[i][j] > dp[i][j + 1] + 1) dp[i][j] = dp[i][j + 1] + 1;
            }
        }
        return dp;
    }
};
