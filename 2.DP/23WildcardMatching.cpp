/*
Given an input string (s) and a pattern (p), implement wildcard pattern matching with support for '?' and '*' where:

'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).
The matching should cover the entire input string (not partial).

 

Example 1:

Input: s = "aa", p = "a"
Output: false
Explanation: "a" does not match the entire string "aa".
Example 2:

Input: s = "aa", p = "*"
Output: true
Explanation: '*' matches any sequence.
Example 3:

*/
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool rec(string s, string p, int i, int j, vector<vector<int>>&dp){
        if(i < 0 && j < 0) return true; // Both string and pattern are fully matched
        if(j < 0 && i >= 0) return false; // Pattern is exhausted but string is not, so no match
        if(i < 0 && j >= 0){ // String is exhausted but pattern is not
            for(int k = 0; k <= j; k++)
                if(p[k] != '*') return false; // If any character in pattern is not '*', it cannot match
            return true; // All remaining characters in pattern are '*', so it matches
        }

        if(dp[i][j] != -1) return dp[i][j];

        if(s[i] == p[j] || p[j] == '?') 
            return dp[i][j] = rec(s, p, i - 1, j - 1, dp); // Characters match or '?' matches any character
        else if(p[j] == '*') // main wildcard case
            // '*' can match zero or more characters, so we can either ignore '*' (move left in pattern) or match one character (move up in string)
            return dp[i][j] = rec(s, p, i, j - 1, dp) || rec(s, p, i - 1, j, dp); // '*' can match zero characters (move left in pattern) or one character (move up in string)
        else
            return dp[i][j] = false; // Characters do not match and it's not a wildcard
    }

    bool tabular(string s, string p){
        int m = s.size();
        int n = p.size();
        vector<vector<int>>dp(m + 1, vector<int>(n + 1, 0));

        for(int i = 0; i <= m; i++){
            for(int j = 0; j <= n; j++){
                if(i == 0 && j == 0){
                    dp[i][j] = true;
                    continue;
                }

                if(i > 0 && j == 0){
                    dp[i][j] = false;
                    continue;
                }

                if(i == 0 && j > 0){
                    bool flag = true;
                    for(int k = 0; k < j; k++){
                        if(p[k] != '*'){
                            flag = false;
                        } 
                    }
                    dp[i][j] = flag;
                    continue;
                }

                if(s[i - 1] == p[j - 1] || p[j - 1] == '?') 
                     dp[i][j] = dp[i - 1][j - 1];
                else if(p[j - 1] == '*')
                     dp[i][j] = dp[i][j - 1] || dp[i - 1][j];
                else
                     dp[i][j] = false;
            }
        }
        return dp[m][n];
        
    }

    bool tabularOptimized(string s, string p){
        int m = s.size();
        int n = p.size();
        vector<bool>prev(n + 1, false), curr(n + 1, false);

        for(int i = 0; i <= m; i++){
            for(int j = 0; j <= n; j++){
                if(i == 0 && j == 0){
                    curr[j] = true;
                    continue;
                }

                if(i > 0 && j == 0){
                    curr[j] = false;
                    continue;
                }

                if(i == 0 && j > 0){
                    bool flag = true;
                    for(int k = 0; k < j; k++){
                        if(p[k] != '*'){
                            flag = false;
                        } 
                    }
                    curr[j] = flag;
                    continue;
                }

                if(s[i - 1] == p[j - 1] || p[j - 1] == '?') 
                     curr[j] = prev[j - 1];
                else if(p[j - 1] == '*')
                     curr[j] = curr[j - 1] || prev[j];
                else
                     curr[j] = false;
            }
            prev = curr;
        }
        return prev[n];
        
    }

    bool isMatch(string s, string p) {
        // int m = s.size();
        // int n = p.size();
        // vector<vector<int>>dp(m, vector<int>(n, -1));
        // return rec(s, p, m - 1, n - 1, dp);
        // return tabular(s, p);
        return tabularOptimized(s, p);
    }
};

int main() {
    Solution sol;
    string s = "aa";
    string p = "a";
    cout << boolalpha << sol.isMatch(s, p) << endl; // Output: false

    s = "aa";
    p = "*";
    cout << boolalpha << sol.isMatch(s, p) << endl; // Output: true

    s = "cb";
    p = "?a";
    cout << boolalpha << sol.isMatch(s, p) << endl; // Output: false

    s = "adceb";
    p = "*a*b";
    cout << boolalpha << sol.isMatch(s, p) << endl; // Output: true

    s = "acdcb";
    p = "a*c?b";
    cout << boolalpha << sol.isMatch(s, p) << endl; // Output: false

    return 0;
}