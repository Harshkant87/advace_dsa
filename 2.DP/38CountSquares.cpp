/*
Given a m * n matrix of ones and zeros, return how many square submatrices have all ones.

 

Example 1:

Input: matrix =
[
  [0,1,1,1],
  [1,1,1,1],
  [0,1,1,1]
]
Output: 15
Explanation: 
There are 10 squares of side 1.
There are 4 squares of side 2.
There is  1 square of side 3.
Total number of squares = 10 + 4 + 1 = 15.
Example 2:

Input: matrix = 
[
  [1,0,1],
  [1,1,0],
  [1,1,0]
]
Output: 7
Explanation: 
There are 6 squares of side 1.  
There is 1 square of side 2. 
Total number of squares = 6 + 1 = 7.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int m = matrix.size();            // Number of rows
        int n = matrix[0].size();         // Number of columns
        int count = 0;                    // To store the total number of square submatrices

        // DP matrix to store size of largest square ending at (i,j)
        vector<vector<int>> dp(m, vector<int>(n, 0));

        // Initialize the first column: each cell can only form a square of size 1 (if it is 1)
        for (int i = 0; i < m; i++)
            count += dp[i][0] = matrix[i][0];

        // Initialize the first row
        for (int j = 1; j < n; j++)
            count += dp[0][j] = matrix[0][j];

        // Fill the rest of the DP matrix
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                // If the cell is 1, calculate the size of the largest square ending at (i, j)
                if (matrix[i][j] == 1) {
                    // Take the minimum of the three neighbors and add 1
                    dp[i][j] = 1 + min(dp[i - 1][j - 1], 
                                      min(dp[i][j - 1], dp[i - 1][j]));
                    // Add to total count
                    count += dp[i][j];
                }
                // Else, dp[i][j] remains 0 (no square ends at this cell)
            }
        }

        return count;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> matrix = {
        {0, 1, 1, 1},
        {1, 1, 1, 1},
        {0, 1, 1, 1}
    };
    cout << "Total square submatrices with all ones: " << sol.countSquares(matrix) << endl; // Output: 15
    return 0;
}