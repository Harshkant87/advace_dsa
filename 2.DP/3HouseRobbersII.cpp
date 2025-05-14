/*
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed. All houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, adjacent houses have a security system connected, and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

 

Example 1:

Input: nums = [2,3,2]
Output: 3
Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money = 2), because they are adjacent houses.
Example 2:

Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.

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
        if(nums.size() == 0) return 0;
        if(nums.size() == 1) return nums[0];

        //because array is circular
        vector<int>excludeFirst(nums.begin() + 1, nums.end());
        vector<int>excludeLast(nums.begin(), nums.end() - 1);

        dpInit(excludeFirst.size());
        int excludeFirstAns = robRec(excludeFirst, 0);

        dpInit(excludeLast.size());
        int excludeLastAns = robRec(excludeLast, 0);
        //cout<<excludeFirstAns << " " << excludeLastAns<<endl;

        return max(excludeFirstAns, excludeLastAns);

    }
};

int main() {
    Solution solution;
    vector<int> nums = {2, 3, 2}; // Example input
    cout << "Maximum amount of money you can rob: " << solution.rob(nums) << endl;

    vector<int> nums2 = {1, 2, 3, 1}; // Example input
    cout << "Maximum amount of money you can rob: " << solution.rob(nums2) << endl;

    return 0;
}