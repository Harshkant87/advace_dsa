/*

Given a set of distinct positive integers nums, return the largest subset answer such that every pair (answer[i], answer[j]) of elements in this subset satisfies:

answer[i] % answer[j] == 0, or
answer[j] % answer[i] == 0
If there are multiple solutions, return any of them.

 

Example 1:

Input: nums = [1,2,3]
Output: [1,2]
Explanation: [1,3] is also accepted.
Example 2:

Input: nums = [1,2,4,8]
Output: [1,2,4,8]

*/
#include <iostream>
#include <vector>
#include <algorithm> // for sort

using namespace std;

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<int>dp(n, 1), prev(n, -1);
        vector<int>ans;
        int maxi = 0;


        for(int i = 0; i < n; i++){
            for(int j = 0; j < i; j++){
                if(nums[i] % nums[j] == 0){ // lis logic
                    if(dp[i] < 1 + dp[j])
                    dp[i] = 1 + dp[j], prev[i] = j;  // Update the previous index           
                }
            }
            if(dp[i] > dp[maxi]) maxi = i;
        }

        for(int i = maxi; i >= 0; i = prev[i])
            ans.push_back(nums[i]);
        
        return ans;

    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 3, 4, 6, 8, 12};
    vector<int> result = sol.largestDivisibleSubset(nums);
    
    cout << "Largest Divisible Subset: ";
    for(int num : result) {
        cout << num << " ";
    }
    cout << endl; // Output: [1, 2, 4, 8] or similar valid subset
    return 0;
}