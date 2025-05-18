/*
You are given an integer array nums and an integer target.

You want to build an expression out of nums by adding one of the symbols '+' and '-' before each integer in nums and then concatenate all the integers.

For example, if nums = [2, 1], you can add a '+' before 2 and a '-' before 1 and concatenate them to build the expression "+2-1".
Return the number of different expressions that you can build, which evaluates to target.

 

Example 1:

Input: nums = [1,1,1,1,1], target = 3
Output: 5
Explanation: There are 5 ways to assign symbols to make the sum of nums be target 3.
-1 + 1 + 1 + 1 + 1 = 3
+1 - 1 + 1 + 1 + 1 = 3
+1 + 1 - 1 + 1 + 1 = 3
+1 + 1 + 1 - 1 + 1 = 3
+1 + 1 + 1 + 1 - 1 = 3
Example 2:

Input: nums = [1], target = 1
Output: 1

*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

class Solution {
public:
    int findSumRec(vector<int>& nums, int target, int index, unordered_map<string, int>&dp){

        if(index < 0 && target == 0) // going deep
            return 1;
        if(index < 0)
            return 0;

        string key = to_string(index) + "#" + to_string(target);
        if(dp.find(key) != dp.end()) return dp[key];

        int sub = findSumRec(nums, target - nums[index], index - 1, dp);
        int add = findSumRec(nums, target + nums[index], index - 1, dp);

        return dp[key] = add + sub;
        
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        unordered_map<string, int>dp;
        return findSumRec(nums, target, nums.size() - 1, dp);
    }

     int count(vector<int>& nums, int s) {
        //int dp[s + 1] = { 0 };
     vector<int>dp(s+1,0);
        dp[0] = 1;
        for (int n : nums)
            for (int i = s; i >= n; i--)
                dp[i] += dp[i - n];
        return dp[s];
    }
    
    int findTargetSumWaysOptimizedTabulation(vector<int>& nums, int S) {
        int sum=0;
        for(auto x:nums)
        sum+=x;
        
         //int s1 = (S+sum)/2;

        
       return sum < S || (S + sum) & 1 ? 0 : count(nums, (S + sum)/2);
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 1, 1, 1, 1};
    int target = 3;
    cout << "Number of ways to reach target: " << sol.findTargetSumWays(nums, target) << endl;
    cout << "Number of ways to reach target using optimized tabulation: " << sol.findTargetSumWaysOptimizedTabulation(nums, target) << endl;
    return 0;
}