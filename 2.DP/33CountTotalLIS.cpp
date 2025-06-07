/*
Given an integer array nums, return the number of longest increasing subsequences.

Notice that the sequence has to be strictly increasing.

 

Example 1:

Input: nums = [1,3,5,4,7]
Output: 2
Explanation: The two longest increasing subsequences are [1, 3, 4, 7] and [1, 3, 5, 7].
Example 2:

Input: nums = [2,2,2,2,2]
Output: 5
Explanation: The length of the longest increasing subsequence is 1, and there are 5 increasing subsequences of length 1, so output 5.

*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();

        // To count the total number of Longest Increasing Subsequences (LIS)
        int count = 0;

        // dp[i] stores the length of the LIS ending at index i
        // Initialize with 1 since every single number is an LIS of length 1
        vector<int> dp(n, 1);

        // subsCount[i] stores the number of LIS ending at index i
        // Initially, there is one LIS of length 1 at each position
        vector<int> subsCount(n, 1);

        // Variable to store the overall maximum length of LIS found so far
        int maxLen = 0;

        // Outer loop: iterate through each element as the current ending element of LIS
        for(int i = 0; i < n; i++) {
            // Inner loop: check all previous elements to potentially extend an LIS
            for(int j = 0; j < i; j++) {
                // If nums[i] can extend the increasing subsequence ending at nums[j]
                if(nums[i] > nums[j]) {
                    // Case 1: Found a longer subsequence ending at i
                    if(dp[i] < 1 + dp[j]) {
                        dp[i] = 1 + dp[j];            // Update LIS length
                        subsCount[i] = subsCount[j];  // Inherit count from j
                    }
                    // Case 2: Found another subsequence of the same length
                    else if(dp[i] == 1 + dp[j]) {
                        subsCount[i] += subsCount[j]; // Add number of ways from j
                    }
                }
            }

            // Update the overall maxLen
            if(maxLen < dp[i]) {
                maxLen = dp[i];
            }
        }

        // Count all subsequences that have the maximum length
        for(int i = 0; i < n; i++) {
            if(dp[i] == maxLen)
                count += subsCount[i];
        }

        return count;  // Return total number of LIS
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 3, 5, 4, 7};
    cout << "Number of Longest Increasing Subsequences: " << sol.findNumberOfLIS(nums) << endl; // Output: 2
    return 0;
}