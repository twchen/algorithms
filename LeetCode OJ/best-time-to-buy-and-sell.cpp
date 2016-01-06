/*
Say you have an array for which the ith element is the price of a given stock on day i.

If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit.
*/

// simplest solution
// credit: https://leetcode.com/discuss/18159/sharing-my-simple-and-clear-c-solution
class Solution {
public:
    int maxProfit(vector<int> &prices){
        int minPrice = INT_MAX;
        int maxPro = 0;
        for(int i = 0; i < prices.size(); ++i){
            // maxPro: maximum profit from day 0 to day i;
            // minPrice: minimum price from day 0 to day i-1;
            maxPro = max(maxPro, prices[i] - minPrice);
            minPrice = min(minPrice, prices[i]); // minimum price from day 0 to day i;
        }
        return maxPro;
    }
};

// my solutions
class Solution {
public:
    // use only one extra array
    int maxProfit(vector<int> &prices){
        int n = prices.size();
        if(n <= 1) return 0;
        vector<int> maxPrice(n); // maxPrice[i]: max price among prices[i+1], prices[i+2], ...
        maxPrice[n-1] = 0;
        for(int i = n-2; i >= 0; --i)
            maxPrice[i] = max(prices[i+1], maxPrice[i+1]);
        int minPrice = INT_MAX;
        int profit = 0;
        for(int i = 0; i < n; ++i){
            minPrice = min(minPrice, prices[i]);
            profit = max(profit, maxPrice[i] - minPrice);
        }
        return profit;
    }
};

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n <= 1) return 0;
        vector<int> maxt(n);
        vector<int> mint(n);
        mint[0] = prices[0];
        maxt[n-1] = prices[n-1];
        for(int i=1; i<n; ++i){
            mint[i] = min(mint[i-1], prices[i]);
            maxt[n-1-i] = max(maxt[n-i], prices[n-1-i]);
        }
        int profit = 0;
        for(int i=0; i<n-1; ++i){
            profit = max(profit, maxt[i+1] - mint[i]);
        }
        return profit;
    }
};
