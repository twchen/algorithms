/*
We are playing the Guess Game. The game is as follows:

I pick a number from 1 to n. You have to guess which number I picked.

Every time you guess wrong, I'll tell you whether the number I picked is higher or lower.

However, when you guess a particular number x, and you guess wrong, you pay $x. You win the game when you guess the number I picked.

Example:

n = 10, I pick 8.

First round:  You guess 5, I tell you that it's higher. You pay $5.
Second round: You guess 7, I tell you that it's higher. You pay $7.
Third round:  You guess 9, I tell you that it's lower. You pay $9.

Game over. 8 is the number I picked.

You end up paying $5 + $7 + $9 = $21.
Given a particular n ≥ 1, find out how much money you need to have to guarantee a win.
*/

// trivial dynamic programming solution
// dp(i, j): minimum money that can guarantee a win when the range is [i, j]
// recursive formula: dp[i, j] = min( k + max( dp[i, k-1], dp[k+1, j] ) ) for k in [i+1, j-1]
// basis cases: dp[i, i] = 0, dp[i, i+1] = i
// the implementation is slightly different because indices start from 0.
// time complexity: O(n^3), space complexity: O(n^2)
class Solution {
public:
    int getMoneyAmount(int n) {
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for(int i = 0; i + 1 < n; ++i){
            dp[i][i + 1] = i + 1;
        }
        for(int step = 2; step < n; ++step){
            for(int i = 0; i + step < n; ++i){
                int min_money = numeric_limits<int>::max();
                for(int j = i + 1; j < i + step; ++j){
                    int money = j + 1 + max(dp[i][j - 1], dp[j + 1][i + step]);
                    if(money < min_money){
                        min_money = money;
                    }
                }
                dp[i][i + step] = min_money;
            }
        }
        return dp[0][n - 1];
    }
};

// non-trivial solution
// https://artofproblemsolving.com/community/c296841h1273742
