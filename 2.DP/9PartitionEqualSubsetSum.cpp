/*
Given an integer array nums, return true if you can partition the array into two subsets such that the sum of the elements in both subsets is equal or false otherwise.

 

Example 1:

Input: nums = [1,5,11,5]
Output: true
Explanation: The array can be partitioned as [1, 5, 5] and [11].
Example 2:

Input: nums = [1,2,3,5]
Output: false
Explanation: The array cannot be partitioned into equal sum subsets

*/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool findTargetSum(vector<int>& nums, int target, int index, vector<vector<int>>&dp){
        if(target == 0) return true;
        if(target < 0 || index < 0) return false;

        if(dp[index][target] != -1) return dp[index][target];

        bool take = findTargetSum(nums, target - nums[index], index - 1, dp);
        bool notTake = findTargetSum(nums, target, index - 1, dp);

        return dp[index][target] = take || notTake;
    }

    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int num: nums)
            sum += num;
        
        if(sum % 2) return false; // If sum is odd, we cannot partition it into two equal subsets
        vector<vector<int>>dp(nums.size(), vector<int>((sum / 2) + 1, -1));
        return findTargetSum(nums, sum / 2, nums.size() - 1, dp);
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 5, 11, 5};
    cout << "Can partition: " << (sol.canPartition(nums) ? "true" : "false") << endl; // Output: true
    return 0;
}