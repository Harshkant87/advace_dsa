/*
Given a string s, partition s such that every substring of the partition is a palindrome.

Return the minimum cuts needed for a palindrome partitioning of s.

 

Example 1:

Input: s = "aab"
Output: 1
Explanation: The palindrome partitioning ["aa","b"] could be produced using 1 cut.
Example 2:

Input: s = "a"
Output: 0
Example 3:

Input: s = "ab"
Output: 1

*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    bool isPalindrome(string &s, int i, int j){
        while(i < j){
            if(s[i++] != s[j--]) return false;
        }
        return true;
    }

    int rec(string s, int i, vector<int>&dp){
        if(i == s.size()) return 0;

        if(dp[i] != -1) return dp[i];

        int minCost = INT_MAX;
        int cost = 0;
        for(int j = i; j < s.size(); j++){
            if(isPalindrome(s, i, j))
                cost = 1 + rec(s, j + 1, dp);
            minCost = min(minCost, cost);
        }
        return dp[i] = minCost;
    }

    int tabular(string s){
        int n = s.size();
        vector<int>dp(n + 1, 0);
        dp[n] = 0; //base case

        for(int i = n - 1; i >= 0; i--){
            int minCost = INT_MAX;
            int cost = 0;

            for(int j = i; j < n; j++){
                if(isPalindrome(s, i, j))
                    cost = 1 + dp[j + 1];
                minCost = min(minCost, cost);
            }
                dp[i] = minCost;
        }
        return dp[0] - 1;
    }

    int minCut(string s) {
        // vector<int>dp(s.size(), -1);
        // return rec(s, 0, dp) - 1;
        return tabular(s);
    }
};

int main() {
    Solution sol;
    string s = "aab";
    cout << "Minimum cuts needed for palindrome partitioning: " << sol.minCut(s) << endl; // Output: 1
    return 0;
}