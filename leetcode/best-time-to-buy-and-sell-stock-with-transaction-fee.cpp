/*
Your are given an array of integers prices, for which the i-th element is the price of a given stock on day i;
and a non-negative integer fee representing a transaction fee.

You may complete as many transactions as you like, but you need to pay the transaction fee for each transaction.
You may not buy more than 1 share of a stock at a time (ie. you must sell the stock share before you buy again.)

Return the maximum profit you can make.

Example 1:
Input: prices = [1, 3, 2, 8, 4, 9], fee = 2
Output: 8
Explanation: The maximum profit can be achieved by:
Buying at prices[0] = 1
Selling at prices[3] = 8
Buying at prices[4] = 4
Selling at prices[5] = 9
The total profit is ((8 - 1) - 2) + ((9 - 4) - 2) = 8.
Note:

0 < prices.length <= 50000.
0 < prices[i] < 50000.
0 <= fee < 50000.
*/

// O(n) time, O(n) extra space
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<int> yes(n); // yes[i]: max profit at the end of day i with stock
        vector<int> no(n); // no[i]: max profix at the end of day i without holding stock
        yes[0] = -prices[0];
        no[0] = 0;
        for(int i = 1; i < n; ++i){
            no[i] = max(yes[i - 1] + prices[i] - fee, no[i - 1]);
            yes[i] = max(no[i - 1] - prices[i], yes[i - 1]);
        }
        return no[n - 1];
    }
};

// O(n) time, O(1) extra space
class Solution {
public:
    int maxProfit(vector<int> &prices, int fee) {
        int n = prices.size();
        int with_stock = -prices[0];
        int without_stock = 0;
        for(int i = 1; i < n; ++i){
            // (1) no[i] = max(yes[i - 1] + prices[i] - fee, no[i - 1]);
            without_stock = max(with_stock + prices[i] - fee, without_stock);
            
            // (2) yes[i] = max(no[i - 1] - prices[i], yes[i - 1]);
            // (2) can be replaced by: yes[i] = max(no[i] - prices[i], yes[i - 1]);
            // because
            //    1. if yes[i - 1] + prices[i] - fee <= no[i - 1], then no[i] = no[i - 1]. Trivial
            //    2. otherwise, no[i] = yes[i - 1] + prices[i] - fee
            //           then no[i - 1] - prices[i] < no[i] - prices = yes[i - 1] - fee <= yes[i - 1]
            //           then yes[i] = yes[i - 1];
            with_stock = max(without_stock - prices[i], with_stock);
        }
        return without_stock;
    }
};

