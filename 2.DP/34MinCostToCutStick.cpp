/*
Given a wooden stick of length n units. The stick is labelled from 0 to n. For example, a stick of length 6 is labelled as follows:


Given an integer array cuts where cuts[i] denotes a position you should perform a cut at.

You should perform the cuts in order, you can change the order of the cuts as you wish.

The cost of one cut is the length of the stick to be cut, the total cost is the sum of costs of all cuts. When you cut a stick, it will be split into two smaller sticks (i.e. the sum of their lengths is the length of the stick before the cut). Please refer to the first example for a better explanation.

Return the minimum total cost of the cuts.

 

Example 1:


Input: n = 7, cuts = [1,3,4,5]
Output: 16
Explanation: Using cuts order = [1, 3, 4, 5] as in the input leads to the following scenario:

The first cut is done to a rod of length 7 so the cost is 7. The second cut is done to a rod of length 6 (i.e. the second part of the first cut), the third is done to a rod of length 4 and the last cut is to a rod of length 3. The total cost is 7 + 6 + 4 + 3 = 20.
Rearranging the cuts to be [3, 5, 1, 4] for example will lead to a scenario with total cost = 16 (as shown in the example photo 7 + 4 + 3 + 2 = 16).
Example 2:

Input: n = 9, cuts = [5,6,1,4,2]
Output: 22
Explanation: If you try the given cuts ordering the cost will be 25.
There are much ordering with total cost <= 25, for example, the order [4, 6, 5, 2, 1] has total cost = 22 which is the minimum possible.
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    int f(int i, int j, vector<int>& cuts, vector<vector<int>>& dp) {
        if (i > j) return 0; 
        if (dp[i][j] != -1) return dp[i][j]; 

        int mini = INT_MAX;
        for (int k = i; k <= j; k++) {
            // Calculate the cost of making the cut at position k and then solving for subproblems
            int cost = cuts[j + 1] - cuts[i - 1] + f(i, k - 1, cuts, dp) + f(k + 1, j, cuts, dp);
            mini = min(mini, cost);
        }
        return dp[i][j] = mini;
    }

    int tabulation(int c, int n, vector<int>& cuts){
        vector<vector<int>>dp(c + 2, vector<int>(c + 2, 0));

        for(int i = c; i >= 1; i--){
            for(int j = 1; j <= c; j++){
                if(i > j) continue;
                int mini = INT_MAX;
                for(int k = i; k <= j; k++){
                    //cout<<cuts[j + 1] << " " << cuts[i - 1] << " " << dp[i][k - 1] << " " << dp[k + 1][j] <<" \n";
                    int cost = cuts[j + 1] - cuts[i - 1] + dp[i][k - 1] + dp[k + 1][j];
                    mini = min(mini, cost);
                }
                dp[i][j] = mini;
            }
        }
        return dp[1][c];
    }

    int minCost(int n, vector<int>& cuts) {
        int c = cuts.size();
        vector<vector<int>> dp(c + 1, vector<int>(c + 1, -1));
        cuts.push_back(n); // Add the endpoint
        cuts.insert(cuts.begin(), 0); // Add the start point
        sort(cuts.begin(), cuts.end()); // Sort cuts including the boundary

        // return f(1, c, cuts, dp); // Solve for the full range excluding the artificial endpoints
        return tabulation(c, n, cuts);
    }
};

int main() {
    Solution sol;
    int n = 7;
    vector<int> cuts = {1, 3, 4, 5};
    cout << "Minimum total cost of cuts: " << sol.minCost(n, cuts) << endl; // Output: 16
    return 0;
}