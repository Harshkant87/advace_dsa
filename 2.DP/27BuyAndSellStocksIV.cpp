/*
You are given an integer array prices where prices[i] is the price of a given stock on the ith day, and an integer k.

Find the maximum profit you can achieve. You may complete at most k transactions: i.e. you may buy at most k times and sell at most k times.

Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

 

Example 1:

Input: k = 2, prices = [2,4,1]
Output: 2
Explanation: Buy on day 1 (price = 2) and sell on day 2 (price = 4), profit = 4-2 = 2.
Example 2:

Input: k = 2, prices = [3,2,6,5,0,3]
Output: 7
Explanation: Buy on day 2 (price = 2) and sell on day 3 (price = 6), profit = 6-2 = 4. Then buy on day 5 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
*/

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int rec(vector<int>& prices, int index, bool canBuy, int transactions, vector<vector<vector<int>>>&dp){
        if(index == prices.size() || transactions == 0) // If we have processed all days or no transactions left
            return 0;

        if(dp[index][canBuy][transactions] != -1) return dp[index][canBuy][transactions];
        
        if(canBuy == true){ 
            int buyProfit = -prices[index] + rec(prices, index + 1, false, transactions, dp); // Buy the stock and the transaction count remains the same unchanged
            int notBuyProfit = 0 + rec(prices, index + 1 ,true, transactions, dp); 
            return dp[index][canBuy][transactions] = max(buyProfit, notBuyProfit); 
        }
        else{
            
            int sellProfit = prices[index] + rec(prices, index + 1, true, transactions - 1, dp); // Sell the stock and reduce the transaction count
            int notSellProfit = 0 + rec(prices, index + 1, false, transactions, dp); 
            return dp[index][canBuy][transactions] = max(sellProfit, notSellProfit); 
        }
            
    }

    int tabular(vector<int> &prices, int k){
        int n = prices.size();
        vector<vector<vector<int>>>dp(prices.size() + 1, vector<vector<int>>(2, vector<int>(k + 1, 0)));

        for(int i = n - 1; i >= 0; i--){
            for(int j = 0; j < 2; j++){
                for(int t = k; t > 0; t--){
                if(j == 0){
                    int sellProfit = prices[i] + dp[i + 1][1][t - 1];
                    int notSellProfit = dp[i + 1][0][t];
                    dp[i][j][t] = max(sellProfit, notSellProfit);
                }
                else{
                    int buyProfit = -prices[i] + dp[i + 1][0][t];
                    int notBuyProfit = dp[i + 1][1][t];
                    dp[i][j][t] = max(buyProfit, notBuyProfit);
                }
                }
               
            }
        }
        return dp[0][1][k];
    }

    int maxProfit(int k, vector<int>& prices) {
        // vector<vector<vector<int>>>dp(prices.size(), vector<vector<int>>(2, vector<int>(k + 1, -1)));
        // return rec(prices, 0, 1, k, dp);
        return tabular(prices, k);
    }
};

int main() {
    Solution sol;
    int k = 2;
    vector<int> prices = {3, 2, 6, 5, 0, 3};
    cout << "Maximum Profit: " << sol.maxProfit(k, prices) << endl; // Output: 7
    return 0;
}