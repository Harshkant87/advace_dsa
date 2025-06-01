/*
Given a string s. In one step you can insert any character at any index of the string.

Return the minimum number of steps to make s palindrome.

A Palindrome String is one that reads the same backward as well as forward.

 

Example 1:

Input: s = "zzazz"
Output: 0
Explanation: The string "zzazz" is already palindrome we do not need any insertions.
Example 2:

Input: s = "mbadm"
Output: 2
Explanation: String can be "mbdadbm" or "mdbabdm".
Example 3:

Input: s = "leetcode"
Output: 5
Explanation: Inserting 5 characters the string becomes "leetcodocteel".

*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int lcs(string s1, string s2, int i1 ,int i2, vector<vector<int>>&dp){
        if(i1 < 0 || i2 < 0) return 0;

        if(dp[i1][i2] != -1) return dp[i1][i2];

        if(s1[i1] == s2[i2]) return dp[i1][i2] = 1 + lcs(s1, s2, i1 - 1, i2 - 1, dp);

        return dp[i1][i2] = max(lcs(s1, s2, i1 - 1, i2, dp), lcs(s1, s2, i1, i2 - 1, dp));

    }

    int lcsTab(string s1, string s2){
        int n = s1.size();
        vector<vector<int>>dp(n + 1, vector<int>(n + 1, -1));

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(s1[i - 1] == s2[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        return dp[n][n];
    }

    int minInsertions(string s) {
        string s1 = s;
        reverse(s1.begin(), s1.end());
        int n = s.size();
        // vector<vector<int>>dp(n + 1, vector<int>(n + 1, -1));
        //return n - lcs(s, s1, n - 1, n - 1, dp);
        return n - 1 - lcsTab(s, s1);
    }
};

int main() {
    Solution sol;
    string s = "mbadm";
    cout << "Minimum insertions to make palindrome: " << sol.minInsertions(s) << endl;
    return 0;
}