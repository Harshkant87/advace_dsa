/*
Given two strings s and t, return the number of distinct subsequences of s which equals t.

The test cases are generated so that the answer fits on a 32-bit signed integer.

 

Example 1:

Input: s = "rabbbit", t = "rabbit"
Output: 3
Explanation:
As shown below, there are 3 ways you can generate "rabbit" from s.
rabbbit
rabbbit
rabbbit

*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int rec(string s, string t, int i, int j, vector<vector<int>>&dp){
        if(j == 0) return 1;

        if(i == 0) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        if(s[i - 1] == t[j - 1])
            return dp[i][j] = rec(s, t, i - 1, j - 1, dp) + rec(s, t, i - 1, j, dp); // Include the current character or not
        else
            return dp[i][j] = rec(s, t, i - 1, j, dp);
    }

    int tabular(string s, string t){
        int MOD = 1e9+7;
        int m = s.size();
        int n = t.size();
        vector<vector<long long>>dp(m + 1, vector<long long>(n + 1, 0));

        for(int i = 0; i <= m; i++)
            dp[i][0] = 1;

        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                if(s[i - 1] == t[j - 1])
                    dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % MOD;
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }
        return dp[m][n];
    }

    int numDistinct(string s, string t) {
        // int m = s.size();
        // int n = t.size();
        // vector<vector<int>>dp(m + 1, vector<int>(n + 1, - 1));
        // return rec(s, t, m, n, dp);
        return tabular(s, t);
    }
};

int main(){
    Solution sol;
    string s = "rabbbit";
    string t = "rabbit";
    cout << sol.numDistinct(s, t) << endl; // Output: 3
    return 0;
}