/*
Given two strings text1 and text2, return the length of their longest common subsequence. If there is no common subsequence, return 0.

A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.

For example, "ace" is a subsequence of "abcde".
A common subsequence of two strings is a subsequence that is common to both strings.

 

Example 1:

Input: text1 = "abcde", text2 = "ace" 
Output: 3  
Explanation: The longest common subsequence is "ace" and its length is 3.
Example 2:

Input: text1 = "abc", text2 = "abc"
Output: 3
Explanation: The longest common subsequence is "abc" and its length is 3.
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int lcsRec(string text1, string text2, int index1, int index2, vector<vector<int>>&dp){
        if(index1 < 0 || index2 < 0) return 0;

        if(dp[index1][index2] != -1) return dp[index1][index2];

        if(text1[index1] == text2[index2])
            return dp[index1][index2] = 1 + lcsRec(text1, text2, index1 - 1, index2 - 1, dp);
        
        return dp[index1][index2] = max(lcsRec(text1, text2, index1 - 1, index2, dp),
                                        lcsRec(text1, text2,  index1, index2 - 1, dp));
    }

    int lcsTab(string text1, string text2, int n1, int n2){
        vector<vector<int>>dp(n1 + 1, vector<int>(n2 + 1, 0));

        for(int i = 1; i <= n1; i++){
            for(int j = 1; j <= n2; j++){
            if(text1[i - 1] == text2[j - 1])
                dp[i][j] = 1 + dp[i - 1][ j - 1];
            else
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        return dp[n1][n2];
    }

    int lcsTabOptimised(string text1, string text2, int n1, int n2){
        vector<int>prev(n2 + 1, 0), curr(n2 + 1, 0);

        for(int i = 1; i <= n1; i++){
            for(int j = 1; j <= n2; j++){
            if(text1[i - 1] == text2[j - 1])
                curr[j] = 1 + prev[j - 1];
            else
                curr[j] = max(prev[j], curr[j - 1]);
            }
            prev = curr;
        }
        return prev[n2];
    }

    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.size();
        int n2 = text2.size();

        // vector<vector<int>>dp(n1, vector<int>(n2, -1));

        // return lcsRec(text1, text2, n1 - 1, n2 - 1, dp);
        return lcsTabOptimised(text1, text2, n1, n2);
    }
};

int main(){
    Solution s;
    string text1 = "abcde";
    string text2 = "ace";
    cout << s.lcsTab(text1, text2, text1.size(), text2.size()) << endl; // Output: 3
    cout << s.lcsTabOptimised(text1, text2, text1.size(), text2.size()) << endl; // Output: 3
    //cout << s.lcsRec(text1, text2, text1.size() - 1, text2.size() - 1, vector<vector<int>>(text1.size(), vector<int>(text2.size(), -1))) << endl; // Output: 3
    return 0;
}