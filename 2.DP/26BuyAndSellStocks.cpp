/*
You are given an array prices where prices[i] is the price of a given stock on the ith day.

Find the maximum profit you can achieve. You may complete at most two transactions.

Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

 

Example 1:

Input: prices = [3,3,5,0,0,3,1,4]
Output: 6
Explanation: Buy on day 4 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
Then buy on day 7 (price = 1) and sell on day 8 (price = 4), profit = 4-1 = 3.
Example 2:

Input: prices = [1,2,3,4,5]
Output: 4
Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
Note that you cannot buy on day 1, buy on day 2 and sell them later, as you are engaging multiple transactions at the same time. You must sell before buying again.
Example 3:

Input: prices = [7,6,4,3,1]
Output: 0
Explanation: In this case, no transaction is done, i.e. max profit = 0.
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

    int tabular(vector<int> &prices){
        int n = prices.size();
        vector<vector<vector<int>>>dp(prices.size() + 1, vector<vector<int>>(2, vector<int>(3, 0)));

        for(int i = n - 1; i >= 0; i--){
            for(int j = 0; j < 2; j++){
                for(int k = 2; k > 0; k--){
                if(j == 0){
                    int sellProfit = prices[i] + dp[i + 1][1][k - 1];
                    int notSellProfit = dp[i + 1][0][k];
                    dp[i][j][k] = max(sellProfit, notSellProfit);
                }
                else{
                    int buyProfit = -prices[i] + dp[i + 1][0][k];
                    int notBuyProfit = dp[i + 1][1][k];
                    dp[i][j][k] = max(buyProfit, notBuyProfit);
                }
                }
               
            }
        }
        return dp[0][1][2];
    }

    int maxProfit(vector<int>& prices) {
        // vector<vector<vector<int>>>dp(prices.size(), vector<vector<int>>(2, vector<int>(3, -1)));
        // return rec(prices, 0, 1, 2, dp);
        return tabular(prices);
    }
};

int main() {
    Solution sol;
    vector<int> prices = {3, 3, 5, 0, 0, 3, 1, 4};
    cout << "Maximum Profit: " << sol.maxProfit(prices) << endl; // Output: 6
    return 0;
}