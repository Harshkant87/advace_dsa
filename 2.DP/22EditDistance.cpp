/*
Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.

You have the following three operations permitted on a word:

Insert a character
Delete a character
Replace a character
 

Example 1:

Input: word1 = "horse", word2 = "ros"
Output: 3
Explanation: 
horse -> rorse (replace 'h' with 'r')
rorse -> rose (remove 'r')
rose -> ros (remove 'e')
Example 2:

Input: word1 = "intention", word2 = "execution"
Output: 5
Explanation: 
intention -> inention (remove 't')
inention -> enention (replace 'i' with 'e')
enention -> exention (replace 'n' with 'x')
exention -> exection (replace 'n' with 'c')
exection -> execution (insert 'u')
*/

#include <iostream>
#include <vector>
#include <string>
#include <climits>
using namespace std;

class Solution {
public:
    int rec(string word1, string word2, int i, int j, vector<vector<int>>&dp){
        if(i < 0) return j + 1;
        if(j < 0) return i + 1;

        if(dp[i][j] != -1) return dp[i][j];

        if(word1[i] == word2[j])
            return dp[i][j] = 0 + rec(word1, word2, i - 1, j - 1, dp); // No operation needed if characters match
        // If characters don't match, we consider the three operations: insert, delete, replace
        // Insert: we can insert word2[j] at position i+1 in word1
        // Delete: we can delete word1[i]
        // Replace: we can replace word1[i] with word2[j]
        // We take the minimum of these three operations and add 1 for the operation performed
        
        return dp[i][j] = 1 + min(rec(word1, word2, i - 1, j - 1, dp), min(rec(word1, word2, i - 1, j, dp), rec(word1, word2, i, j - 1, dp)));
    }

    int tabular(string word1, string word2){
       int m = word1.size();
        int n = word2.size();
        vector<vector<int>>dp(m + 1, vector<int>(n + 1, 0));

        for(int i = 0; i <= m; i++){
            for(int j = 0; j <= n; j++){
                if(i == 0){
                    dp[i][j] = j;
                    continue;
                }  
                if(j == 0){
                    dp[i][j] = i;
                    continue;
                }

                if(word1[i - 1] == word2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1];
                else
                    dp[i][j] = 1 + min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1]));
                
            }
        }
        return dp[m][n];
    }

    int tabularOptimized(string word1, string word2){
        int m = word1.size();
        int n = word2.size();
       // vector<vector<int>>dp(m + 1, vector<int>(n + 1, 0));
       vector<int>prev(n + 1, 0), curr(n + 1, 0);

        for(int i = 0; i <= m; i++){
            for(int j = 0; j <= n; j++){
                if(i == 0){
                    curr[j] = j;
                    continue;
                }  
                if(j == 0){
                    curr[j] = i;
                    continue;
                }

                if(word1[i - 1] == word2[j - 1])
                    curr[j] = prev[j - 1];
                else
                    curr[j] = 1 + min(prev[j - 1], min(prev[j], curr[j - 1]));
                
            }
            prev = curr;
        }
        return curr[n];
    }

    int minDistance(string word1, string word2) {
        // int m = word1.size();
        // int n = word2.size();
        // vector<vector<int>>dp(m , vector<int>(n , -1));
        // return rec(word1, word2, m - 1, n - 1, dp);
        // return tabular(word1, word2);
        return tabularOptimized(word1, word2);
    }
};

int main() {
    Solution sol;
    string word1 = "horse";
    string word2 = "ros";
    cout << "Minimum operations to convert '" << word1 << "' to '" << word2 << "': " << sol.minDistance(word1, word2) << endl;
    return 0;
}