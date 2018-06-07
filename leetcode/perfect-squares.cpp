/*
Given a positive integer n, find the least number of perfect square numbers
(for example, 1, 4, 9, 16, ...) which sum to n.

For example, given n = 12, return 3 because 12 = 4 + 4 + 4; given n = 13, return 2 because 13 = 4 + 9.
*/

// reference: https://leetcode.com/problems/perfect-squares/discuss/71488/Summary-of-4-different-solutions-(BFS-DP-static-DP-and-mathematics)

// method 1: dynamic programming
// reference: 
// with static: 9ms
// without static: 99ms
class Solution {
public:
    int numSquares(int n) {
        static vector<int> squares; // squares[i] = i * i
        static vector<int> num_squares({0}); // num_squares[i] = least # of perfect square numbers that sum to i
        for(int i = squares.size(); i * i <= n; ++i){
            squares.push_back(i * i);
        }
        for(int i = num_squares.size(); i <= n; ++i){
            int num = numeric_limits<int>::max();
            for(int j = 1; j < squares.size() && squares[j] <= i; ++j){
                num = min(num, num_squares[i - squares[j]] + 1);
            }
            num_squares.push_back(num);
        }
        return num_squares[n];
    }
};

// method 2: breath first search
// 12ms
class Solution {
public:
    int numSquares(int n) {
        vector<int> dist(n + 1);
        queue<int> q;
        q.push(0);
        while(!q.empty()){
            int size = q.size();
            for(int i = 0; i < size; ++i){
                int m = q.front(); q.pop();
                for(int j = 1; m + j * j <= n; ++j){
                    if(m + j * j == n) return dist[m] + 1;
                    if(dist[m + j * j] == 0){ // m + j * j not visited before
                        dist[m + j * j] = dist[m] + 1;
                        q.push(m + j * j);
                    }
                }
            }
        }
        return 0;
    }
};

// method 3: Lagrange's four-square theorem
// 5ms
class Solution {
public:
    int numSquares(int n) {
        // According to "Lagrange's four-square theorem"
        // each natural number can be expressed as the sum of the squares of 4 non-negative numbers
        
        // the result is 4 iff n is in the form of 4^k(8*m + 7)
        // please refer to "Legendre's three-square theorem"
        
        // while n % 4 == 0
        while((n & 3) == 0){
            n >>= 2;
        }
        // if n % 8 == 7
        if((n & 7) == 7){
            return 4;
        }
        
        // check if the result is 1 or 2
        for(int a = 0; a * a <= n; ++a){
            int b = sqrt(n - a * a);
            if(a * a + b * b == n){
                return a == 0 ? 1 : 2;
                // return !!a + !!b;
            }
        }
        
        // the only possibility left
        return 3;
    }
};
