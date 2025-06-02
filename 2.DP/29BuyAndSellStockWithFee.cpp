/*
You are given an array prices where prices[i] is the price of a given stock on the ith day, and an integer fee representing a transaction fee.

Find the maximum profit you can achieve. You may complete as many transactions as you like, but you need to pay the transaction fee for each transaction.

Note:

You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).
The transaction fee is only charged once for each stock purchase and sale.
 

Example 1:

Input: prices = [1,3,2,8,4,9], fee = 2
Output: 8
Explanation: The maximum profit can be achieved by:
- Buying at prices[0] = 1
- Selling at prices[3] = 8
- Buying at prices[4] = 4
- Selling at prices[5] = 9
The total profit is ((8 - 1) - 2) + ((9 - 4) - 2) = 8.
Example 2:

Input: prices = [1,3,7,5,10,3], fee = 3
Output: 6

*/
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
        int rec(vector<int>& prices, int index, bool canBuy, int fees, vector<vector<int>>&dp){
        if(index == prices.size())
            return 0;

        if(dp[index][canBuy] != -1) return dp[index][canBuy];
        
        if(canBuy == true){ // If we can buy the stock
            // We can either buy the stock or not buy it
            int buyProfit = -prices[index] + rec(prices, index + 1, false, fees, dp); // Buy the stock
            int notBuyProfit = 0 + rec(prices, index + 1 ,true, fees, dp); // Do not buy the stock
            return dp[index][canBuy] = max(buyProfit, notBuyProfit); // Return the maximum of both options
        }
        else{
            // We can either sell the stock or not sell it
            int sellProfit = prices[index] - fees + rec(prices, index + 1, true, fees, dp); // Sell the stock and pay the fees as transaction is completed
            int notSellProfit = 0 + rec(prices, index + 1, false, fees, dp); // Do not sell the stock
            return dp[index][canBuy] = max(sellProfit, notSellProfit); // Return the maximum of both options
        }
            
    }

    int tabular(vector<int>& prices, int fees){
        int n = prices.size();
        vector<vector<int>>dp(n + 1, vector<int>(2, 0));

        for(int i = n - 1; i >= 0; i--){
            for(int j = 0; j < 2; j++){
                if(j == 1){ // If we can buy the stock
                    int buyProfit = -prices[i] + dp[i + 1][0]; // Buy the stock
                    int notBuyProfit = dp[i + 1][1]; // Do not buy the stock
                    dp[i][j] = max(buyProfit, notBuyProfit); // Return the maximum of both options
                }
                else{ // If we can sell the stock
                    int sellProfit = prices[i] - fees + dp[i + 1][1]; // Sell the stock and pay the fees as transaction is completed
                    int notSellProfit = dp[i + 1][0]; // Do not sell the stock
                    dp[i][j] = max(sellProfit, notSellProfit); // Return the maximum of both options
                }
            }
        }
        return dp[0][1]; // We start with the ability to buy
    }

    int tabularOptimized(vector<int>& prices, int fees) {
        int n = prices.size();
        vector<int>dp(2, 0); // Only need to keep track of the current and next state

        for(int i = n - 1; i >= 0; i--){
            vector<int>temp(2, 0); // Temporary storage for the current iteration
            for(int j = 0; j < 2; j++){
                if(j == 1){ // If we can buy the stock
                    int buyProfit = -prices[i] + dp[0]; // Buy the stock
                    int notBuyProfit = dp[1]; // Do not buy the stock
                    temp[j] = max(buyProfit, notBuyProfit); // Return the maximum of both options
                }
                else{ // If we can sell the stock
                    int sellProfit = prices[i] - fees + dp[1]; // Sell the stock and pay the fees as transaction is completed
                    int notSellProfit = dp[0]; // Do not sell the stock
                    temp[j] = max(sellProfit, notSellProfit); // Return the maximum of both options
                }
            }
            dp = temp; // Update dp to the current iteration's results
        }
        return dp[1]; // We start with the ability to buy
    }

    int maxProfit(vector<int>& prices, int fee) {
        // vector<vector<int>>dp(prices.size(), vector<int>(2, -1));
        // return rec(prices, 0, true, fee, dp);
        // return tabular(prices, fee);
        return tabularOptimized(prices, fee);
    }
};

int main() {
    Solution sol;
    vector<int> prices = {1, 3, 2, 8, 4, 9};
    int fee = 2;
    cout << "Maximum Profit: " << sol.maxProfit(prices, fee) << endl; // Output: 8
    return 0;
}

