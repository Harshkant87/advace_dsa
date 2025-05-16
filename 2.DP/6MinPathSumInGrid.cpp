/*
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right, which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.

 

Example 1:


Input: grid = [[1,3,1],[1,5,1],[4,2,1]]
Output: 7
Explanation: Because the path 1 → 3 → 1 → 1 → 1 minimizes the sum.
Example 2:

Input: grid = [[1,2,3],[4,5,6]]
Output: 12

*/

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    int minPathSumRec(int row, int col, vector<vector<int>>& grid, vector<vector<int>>& dp){
        if(row == 0 && col == 0) return grid[0][0];

        if(dp[row][col] != -1)
            return dp[row][col];

        int up = INT_MAX;
        int left = INT_MAX;

        if(row - 1 >= 0) up = grid[row][col] + minPathSumRec(row - 1, col, grid, dp);
        if(col - 1 >= 0) left = grid[row][col] + minPathSumRec(row, col - 1, grid, dp);

        return dp[row][col] = min(up, left);
    }

    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>>dp(m, vector<int>(n, -1));
        return minPathSumRec(m - 1, n - 1, grid, dp);
    }
};

int main() {
    Solution sol;
    vector<vector<int>> grid = {{1,3,1},{1,5,1},{4,2,1}};
    cout << "Minimum Path Sum: " << sol.minPathSum(grid) << endl; // Output: 7
    return 0;
}