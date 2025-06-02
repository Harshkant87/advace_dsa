/*
You are given an array prices where prices[i] is the price of a given stock on the ith day.

Find the maximum profit you can achieve. You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times) with the following restrictions:

After you sell your stock, you cannot buy stock on the next day (i.e., cooldown one day).
Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

 

Example 1:

Input: prices = [1,2,3,0,2]
Output: 3
Explanation: transactions = [buy, sell, cooldown, buy, sell]
Example 2:

Input: prices = [1]
Output: 0
*/

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
        int rec(vector<int>& prices, int index, bool canBuy, vector<vector<int>>&dp){
        if(index >= prices.size())
            return 0;

        if(dp[index][canBuy] != -1) return dp[index][canBuy];
        
        if(canBuy == true){ // If we can buy the stock
            // We can either buy the stock or not buy it
            int buyProfit = -prices[index] + rec(prices, index + 1, false, dp); // Buy the stock
            int notBuyProfit = 0 + rec(prices, index + 1 ,true, dp); // Do not buy the stock
            return dp[index][canBuy] = max(buyProfit, notBuyProfit); // Return the maximum of both options
        }
        else{
            // We can either sell the stock or not sell it
            int sellProfit = prices[index] + rec(prices, index + 2, true, dp); // Sell the stock and cooldown for a day
            int notSellProfit = 0 + rec(prices, index + 1, false, dp); // Do not sell the stock
            return dp[index][canBuy] = max(sellProfit, notSellProfit); // Return the maximum of both options
        }
            
    }

    int tabular(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>>dp(n + 2, vector<int>(2, 0));

        for(int i = n - 1; i >= 0; i--) {
            for(int j = 0; j < 2; j++) {
                if(j == 0) { // If we can sell
                    int sellProfit = prices[i] + dp[i + 2][1]; // Sell and cooldown for a day
                    int notSellProfit = dp[i + 1][0]; // Do not sell
                    dp[i][j] = max(sellProfit, notSellProfit);
                } else { // If we can buy
                    int buyProfit = -prices[i] + dp[i + 1][0]; // Buy the stock
                    int notBuyProfit = dp[i + 1][1]; // Do not buy
                    dp[i][j] = max(buyProfit, notBuyProfit);
                }
            }
        }
        return dp[0][1];
    }

    int maxProfit(vector<int>& prices) {
        // vector<vector<int>>dp(prices.size(), vector<int>(2, -1));
        // return rec(prices, 0, true, dp);
        return tabular(prices);
    }
};

int main() {
    Solution sol;
    vector<int> prices = {1, 2, 3, 0, 2};
    cout << "Maximum Profit: " << sol.maxProfit(prices) << endl; // Output: 3
    return 0;
}

