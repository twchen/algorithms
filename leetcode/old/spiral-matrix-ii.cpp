/*
Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.

For example,
Given n = 3,

You should return the following matrix:
[
 [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]
]
*/

class Solution {
public:
    Solution(){
        // 0 right, 1 down, 2 left, 3 up
        xs = { 1, 0, -1, 0 };
        ys = { 0, 1, 0, -1 };
    }
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n, 0));
        int x = 0, y = 0;
        int dir = 0;
        for(int i=1; i<n*n; ++i){
            matrix[y][x] = i;
            bool success = false;
            do{
                int new_x = x + xs[dir], new_y = y + ys[dir];
                if(0 <= new_x && new_x < n && 0 <= new_y && new_y < n && matrix[new_y][new_x] == 0){
                    success = true;
                    x = new_x;
                    y = new_y;
                }else{
                    dir = (dir + 1) % 4;
                }
            }while(!success);
        }
        if(n > 0) matrix[y][x] = n * n;
        return matrix;
    }

private:
    vector<int> xs, ys;
};
