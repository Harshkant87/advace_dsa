/*
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

 

Example 1:

Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.
Example 2:

Input: nums = [2,7,9,3,1]
Output: 12
Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
Total amount you can rob = 2 + 9 + 1 = 12.

*/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    vector<int>dp;
    void dpInit(int size){
        dp.clear();
        dp.resize(size + 1, -1);
    }
public:
    int robRec(vector<int>& nums, int index){
        if(index >= nums.size())
            return 0;

        if(dp[index] != -1)
            return dp[index];

        int pick = nums[index] + robRec(nums, index + 2);
        int notPick = robRec(nums, index + 1);

        return dp[index] = max(pick, notPick);
    }

    int rob(vector<int>& nums) {
        dpInit(nums.size());
        return robRec(nums, 0);
    }
};

int main() {
    Solution solution;
    vector<int> nums = {2, 7, 9, 3, 1}; // Example input
    cout << "Maximum amount of money you can rob: " << solution.rob(nums) << endl;

    vector<int> nums2 = {1, 2, 3}; // Example input
    cout << "Maximum amount of money you can rob: " << solution.rob(nums2) << endl;
    return 0;
}