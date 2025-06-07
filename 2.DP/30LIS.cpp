/*
Given an integer array nums, return the length of the longest strictly increasing subsequence.

 

Example 1:

Input: nums = [10,9,2,5,3,7,101,18]
Output: 4
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.
Example 2:

Input: nums = [0,1,0,3,2,3]
Output: 4
Example 3:

Input: nums = [7,7,7,7,7,7,7]
Output: 1

*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    int rec(vector<int>& nums, int index, int prevIndex, vector<vector<int>>&dp){
        if(index == nums.size() + 1) return 0;

        if(dp[index][prevIndex] != -1) return dp[index][prevIndex];

        int notTake = 0 + rec(nums, index + 1, prevIndex, dp); // Not taking the current element
        // Taking the current element if it is greater than the previous element

        int take = -1e8;
        if(prevIndex == 0 || nums[index - 1] > nums[prevIndex - 1])
            take = 1 + rec(nums, index + 1, index, dp);
        
        return dp[index][prevIndex] = max(take, notTake);
    }

    int tabular(vector<int>& nums){
        int n = nums.size();
        vector<vector<int>>dp(n + 1, vector<int>(n + 1, 0));

        for(int i = n - 1; i >= 0; i--){
            for(int j = i - 1; j >= 0; j--){
                int notTake = 0 + dp[i + 1][j];
                int take = -1e8;

                if(j == 0 || nums[i + 1] > nums[j + 1])
                    take = 1 + dp[i + 1][i];
                
                dp[i][j] = max(take, notTake);
                cout<<dp[i][j] <<" ";
            }
            cout<<endl;
        }

        return dp[1][0];
    }

    int tabularOptimized(vector<int>& nums){
        int n = nums.size();
        vector<int>curr(n + 1, 0), next(n + 1, 0);

        for(int i = n - 1; i >= 0; i--){
            for(int j = i - 1; j >= -1; j--){
                int notTake = 0 + next[j + 1];
                int take = -1e8;

                if(j == -1 || nums[i] > nums[j])
                    take = 1 + next[i + 1];
                
                curr[j + 1] = max(take, notTake);
            }
            next = curr;
        }
        return next[0];
    }

    int iterativeLIS(vector<int>& nums){
        int n = nums.size();
        vector<int>dp(n, 1);
        int lis = 1;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < i; j++){
                if(nums[i] > nums[j]) // If the current element is greater than the previous element
                    dp[i] = max(dp[i], 1 + dp[j]), lis = max(lis, dp[i]);
            }
        }
        return lis;
    }

    int lisBS(vector<int> &nums){
        int n = nums.size();
        vector<int>temp;
        temp.push_back(nums[0]);

        for(int i = 1; i < n; i++){
            if(nums[i] > temp.back()) // If the current element is greater than the last element in temp
                temp.push_back(nums[i]);
            else{ // If the current element is not greater, find the position to replace
                // Find the first element in temp that is greater than or equal to nums[i]
                int index = lower_bound(temp.begin(), temp.end(), nums[i]) - temp.begin();
                temp[index] = nums[i];
            }
        }
        return temp.size();
    }

    int lengthOfLIS(vector<int>& nums) {
        // int n = nums.size();
        // vector<vector<int>>dp(n + 1, vector<int>(n + 1, -1));
        // return rec(nums, 1, 0, dp);
        //return tabular(nums);
        //return tabularOptimized(nums);
        //return iterativeLIS(nums);
        return lisBS(nums);
    }
};

int main() {
    Solution sol;
    vector<int> nums = {10,9,2,5,3,7,101,18};
    cout << "Length of Longest Increasing Subsequence: " << sol.lengthOfLIS(nums) << endl; // Output: 4
    return 0;
}