/*
You are given an integer array prices where prices[i] is the price of a given stock on the ith day.

On each day, you may decide to buy and/or sell the stock. You can only hold at most one share of the stock at any time. However, you can buy it then immediately sell it on the same day.

Find and return the maximum profit you can achieve.

 

Example 1:

Input: prices = [7,1,5,3,6,4]
Output: 7
Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = 5-1 = 4.
Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 = 3.
Total profit is 4 + 3 = 7.
Example 2:

Input: prices = [1,2,3,4,5]
Output: 4
Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
Total profit is 4.
Example 3:

Input: prices = [7,6,4,3,1]
Output: 0
Explanation: There is no way to make a positive profit, so we never buy the stock to achieve the maximum profit of 0.

*/
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int rec(vector<int>& prices, int index, bool canBuy, vector<vector<int>>&dp){
        if(index == prices.size())
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
            int sellProfit = prices[index] + rec(prices, index + 1, true, dp); // Sell the stock
            int notSellProfit = 0 + rec(prices, index + 1, false, dp); // Do not sell the stock
            return dp[index][canBuy] = max(sellProfit, notSellProfit); // Return the maximum of both options
        }
            
    }

    int tabular(vector<int>& prices){
        int n = prices.size();
        vector<vector<int>>dp(n + 1, vector<int>(2, 0));

        for(int i = n - 1; i >= 0; i--){
            for(int j = 0; j < 2; j++){
                if(j == 0){
                    int sellProfit = prices[i] + dp[i + 1][1];
                    int notSellProfit = dp[i + 1][0];
                    dp[i][j] = max(sellProfit, notSellProfit);
                }
                else{
                    int buyProfit = -prices[i] + dp[i + 1][0];
                    int notBuyProfit = dp[i + 1][1];
                    dp[i][j] = max(buyProfit, notBuyProfit);
                }
            }
        }
        return dp[0][1];
    }

    int tabularOptimized(vector<int>& prices){
        int n = prices.size();
        vector<int>curr(2, 0), next(2, 0);

        for(int i = n - 1; i >= 0; i--){
            for(int j = 0; j < 2; j++){
                if(j == 0){
                    int sellProfit = prices[i] + next[1];
                    int notSellProfit = next[0];
                    curr[j] = max(sellProfit, notSellProfit);
                }
                else{
                    int buyProfit = -prices[i] + next[0];
                    int notBuyProfit = next[1];
                    curr[j] = max(buyProfit, notBuyProfit);
                }
            }
            next = curr;
        }
        return next[1];
    }

    int maxProfit(vector<int>& prices) {
        // vector<vector<int>>dp(prices.size(), vector<int>(2, -1));
        // return rec(prices, 0, true, dp);
        //return tabular(prices);
        return tabularOptimized(prices);
    }
};

int main() {
    Solution sol;
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    cout << "Maximum Profit: " << sol.maxProfit(prices) << endl; // Output: 7
    return 0;
}