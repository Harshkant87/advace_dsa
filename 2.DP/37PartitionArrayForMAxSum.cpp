/*
Given an integer array arr, partition the array into (contiguous) subarrays of length at most k. After partitioning, each subarray has their values changed to become the maximum value of that subarray.

Return the largest sum of the given array after partitioning. Test cases are generated so that the answer fits in a 32-bit integer.

 

Example 1:

Input: arr = [1,15,7,9,2,5,10], k = 3
Output: 84
Explanation: arr becomes [15,15,15,9,10,10,10]
Example 2:

Input: arr = [1,4,1,5,7,3,6,1,9,9,3], k = 4
Output: 83
Example 3:

Input: arr = [1], k = 1
Output: 1
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    int findMax(vector<int>& arr, int start, int end){
        int maxNum = INT_MIN;
        for(int i = start; i <= end && i < arr.size(); i++)
            maxNum = max(maxNum, arr[i]);
        
        return maxNum;
    }
    int rec(int i, vector<int>& arr, int k, vector<int>&dp){
        if(i == arr.size()) return 0;
        if(dp[i] != -1) return dp[i];

        int maxSum = INT_MIN;
        int range = min(static_cast<int>(arr.size()), i + k);
        for(int j = i; j < range; j++){
            int maxNum = findMax(arr, i, j);
            int totalSum = maxNum * (j - i + 1) + rec(j + 1, arr, k, dp);

            maxSum = max(maxSum, totalSum);
        }
        return dp[i] = maxSum;
    }

    int tabular(vector<int>& arr, int k){
        int n = arr.size();
        vector<int>dp(n + 1, 0);
        
        for(int i = n - 1; i >= 0; i--){

            int maxSum = INT_MIN;
            int range = min(static_cast<int>(arr.size()), i + k);
            for(int j = i; j < range; j++){
                int maxNum = findMax(arr, i, j);
                int totalSum = maxNum * (j - i + 1) + dp[j + 1];

                maxSum = max(maxSum, totalSum);
            }
             dp[i] = maxSum;
        }
        return dp[0];
    }

    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        // vector<int>dp(arr.size(), -1);
        // return rec(0, arr, k, dp);
        return tabular(arr, k);
    }
};

int main() {
    Solution sol;
    vector<int> arr = {1, 15, 7, 9, 2, 5, 10};
    int k = 3;
    cout << "Largest sum after partitioning: " << sol.maxSumAfterPartitioning(arr, k) << endl; // Output: 84
    return 0;
}