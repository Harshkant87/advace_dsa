/*
Given a string s, find the longest palindromic subsequence's length in s.

A subsequence is a sequence that can be derived from another sequence by deleting some or no elements without changing the order of the remaining elements.

 

Example 1:

Input: s = "bbbab"
Output: 4
Explanation: One possible longest palindromic subsequence is "bbbb".
Example 2:

Input: s = "cbbd"
Output: 2
Explanation: One possible longest palindromic subsequence is "bb".

*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int lpsRec(string s1, string s2, int index1, int index2, vector<vector<int>>&dp){
        if(index1 < 0 || index2 < 0) return 0;
        
        if(dp[index1][index2] != -1)
            return dp[index1][index2];

        if(s1[index1] == s2[index2])
            return dp[index1][index2] = 1 + lpsRec(s1, s2, index1 - 1, index2 - 1, dp);
        
        return dp[index1][index2] = max(lpsRec(s1, s2, index1 - 1, index2, dp), lpsRec(s1, s2, index1, index2 - 1, dp));
    }

    int lpsTab(string s){
        string s2 = s;
        reverse(s2.begin(), s2.end());
        int n = s.size();
        vector<vector<int>>dp(s.size() + 1, vector<int>(s.size() + 1, 0));

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(s[i - 1] == s2[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        return dp[n][n];
    }

    int lpsTabOpt(string s){
        string s2 = s;
        reverse(s2.begin(), s2.end());
        int n = s.size();
        vector<int>prev(n + 1, 0), curr(n + 1, 0);

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(s[i - 1] == s2[j - 1])
                    curr[j] = 1 + prev[j - 1];
                else
                    curr[j] = max(prev[j], curr[j - 1]);
            }
            prev = curr;
        }
        return prev[n];
    }

    int longestPalindromeSubseq(string s) {
        string s2 = s;
        reverse(s2.begin(), s2.end());
        vector<vector<int>>dp(s.size(), vector<int>(s.size(), -1));
        //return lpsRec(s, s2, s.size() - 1, s.size() - 1, dp);
        //return lpsTab(s);
        return lpsTabOpt(s);
    }
};

int main() {
    Solution sol;
    string s = "bbbab";
    cout << "The Length of Longest Palindromic Subsequence is " << sol.longestPalindromeSubseq(s) << endl;

    s = "cbbd";
    cout << "The Length of Longest Palindromic Subsequence is " << sol.longestPalindromeSubseq(s) << endl;

    return 0;
}