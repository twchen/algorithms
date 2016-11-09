/*
You are given coins of different denominations and a total amount of money amount. Write a function to compute the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

Example 1:
coins = [1, 2, 5], amount = 11
return 3 (11 = 5 + 5 + 1)

Example 2:
coins = [2], amount = 3
return -1.

Note:
You may assume that you have an infinite number of each kind of coin.
 */

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(coins.empty()) return -1;
        sort(coins.begin(), coins.end());
        vector<int> m(amount+1, INT_MAX); // m[i]: the number of ways to make up an amount of money i;
        for(int i=0; i<coins[0]; ++i){
            m[i] = 0;
        }
        for(int i=1; i<= amount; ++i){
            for(int j=0; j<coins.size() && coins[j] <= i; ++j){
                int numWays = m[i - coins[j]];
                if(m[i] > numWays) m[i] = numWays;
            }
            m[i] += 1;
        }
        return m[amount] == 0 ? -1 : m[amount];
    }
};
