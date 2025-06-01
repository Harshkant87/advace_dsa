/*
Given two strings str1 and str2, return the shortest string that has both str1 and str2 as subsequences. If there are multiple valid strings, return any of them.

A string s is a subsequence of string t if deleting some number of characters from t (possibly 0) results in the string s.

 

Example 1:

Input: str1 = "abac", str2 = "cab"
Output: "cabac"
Explanation: 
str1 = "abac" is a subsequence of "cabac" because we can delete the first "c".
str2 = "cab" is a subsequence of "cabac" because we can delete the last "ac".
The answer provided is the shortest such string that satisfies these properties.

*/

#include <iostream>
#include <vector>
#include <string>
#include <climits>
#include <algorithm> 
using namespace std;

class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int n=str1.size(),m=str2.size();
       int dp[n+1][m+1];
        int i=0,j=0;
        for(i=0;i<=n;i++)
        {
            for(j=0;j<=m;j++)
            {   
                if(i==0 || j==0)
                    dp[i][j]=0;
                
                else if(str1[i-1]==str2[j-1])
                    dp[i][j]=1+dp[i-1][j-1];
                else
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        string ans;
        i=n;j=m;
        while(i>0 && j>0)
        {
            if(str1[i-1]==str2[j-1])
            {
                ans.push_back(str1[i-1]);
                i--;j--;
            }
            
            else
            {
               
                  if(dp[i][j-1]<dp[i-1][j])
                {
                    ans.push_back(str1[i-1]);
                    i--;
                }
                 else
                {
                    ans.push_back(str2[j-1]);
                    j--;
                }
                
            }
        }
        while(i>0)
        {
                   ans.push_back(str1[i-1]);
                    i--;        
        }
        
        while(j>0)
        {
                   ans.push_back(str2[j-1]);
                    j--;        
        }
        
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};

int main() {
    Solution sol;
    string str1 = "abac";
    string str2 = "cab";
    string result = sol.shortestCommonSupersequence(str1, str2);
    cout << "Shortest Common Supersequence: " << result << endl; // Output: "cabac"
    return 0;
}