/*
You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

You may assume that you have an infinite number of each kind of coin.

 

Example 1:

Input: coins = [1,2,5], amount = 11
Output: 3
Explanation: 11 = 5 + 5 + 1
Example 2:

Input: coins = [2], amount = 3
Output: -1
Example 3:

Input: coins = [1], amount = 0
Output: 0
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // Memoization
    int rec(vector<int>& coins, int amount, int index, vector<vector<int>>dp){ 
        if(index == 0){
            if(amount % coins[index] == 0) return amount / coins[index];
            else return 1e8;
        }

        if(dp[index][amount] != -1) return dp[index][amount];

        int notTake = rec(coins, amount, index - 1, dp);
        int take = 1e8;
        if(amount >= coins[index])
            take = 1 + rec(coins, amount - coins[index], index, dp);
        return dp[index][amount] = min(take, notTake);
    }

    // Tabulation
    int coinChangeTabulation(vector<int>& coins, int amount) {
        vector<vector<int>>dp(coins.size(), vector<int>(amount + 1, 0));
        int n = coins.size();
        for(int T = 0; T <= amount; T++){
            if(T % coins[0] == 0) 
                dp[0][T] = T / coins[0];
            else
                dp[0][T] = 1e8;
        }

        for(int i = 1; i < n; i++){
            for(int T = 0; T <= amount; T++){

                int notTake = dp[i - 1][T];
                int take = 1e8;

                if(T >= coins[i])
                    take = 1 + dp[i][T - coins[i]];

                dp[i][T] = min(take, notTake);
            }
        }
        return dp[n - 1][amount] == 1e8 ? -1 : dp[n - 1][amount];           
        
    }

    // Space Optimization
        int coinChange(vector<int>& coins, int amount) {
        vector<int>prev(amount + 1, 0), curr(amount + 1, 0);
        int n = coins.size();
        for(int T = 0; T <= amount; T++){
            if(T % coins[0] == 0) 
                prev[T] = T / coins[0];
            else
                prev[T] = 1e8;
        }

        for(int i = 1; i < n; i++){
            for(int T = 0; T <= amount; T++){

                int notTake = prev[T];
                int take = 1e8;

                if(T >= coins[i])
                    take = 1 + curr[T - coins[i]];

                curr[T] = min(take, notTake);
            }
            prev = curr;
        }
        return prev[amount] == 1e8 ? -1 : prev[amount];           
        
    }
};

int main() {
    Solution sol;
    vector<int> coins = {1, 2, 5};
    int amount = 11;
    int result = sol.coinChange(coins, amount);
    cout << "Minimum number of coins: " << result << endl; // Output: 3
    return 0;
}