/*
Given a triangle array, return the minimum path sum from top to bottom.

For each step, you may move to an adjacent number of the row below. More formally, if you are on index i on the current row, you may move to either index i or index i + 1 on the next row.

 

Example 1:

Input: triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]
Output: 11
Explanation: The triangle looks like:
   2
  3 4
 6 5 7
4 1 8 3
The minimum path sum from top to bottom is 2 + 3 + 5 + 1 = 11 (underlined above).
Example 2:

Input: triangle = [[-10]]
Output: -10

*/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int recMinTotal(vector<vector<int>>& triangle, int row, int col, vector<vector<int>>&dp){
        if(row == triangle.size() - 1) return triangle[row][col];

        if(dp[row][col] != -1)
            return dp[row][col];

        int down = triangle[row][col] + recMinTotal(triangle, row + 1, col, dp);
        int diag = triangle[row][col] + recMinTotal(triangle, row + 1, col + 1, dp);

        return dp[row][col] = min(down, diag);
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>>dp(triangle.size(), vector<int>(triangle.size(), -1));
        return recMinTotal(triangle, 0, 0, dp);
    }
};

int main() {
    Solution sol;
    vector<vector<int>> triangle = {{2},{3,4},{6,5,7},{4,1,8,3}};
    cout << "Minimum Path Sum: " << sol.minimumTotal(triangle) << endl; // Output: 11
    return 0;
}