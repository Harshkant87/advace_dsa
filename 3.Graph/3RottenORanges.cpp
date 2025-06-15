/*
You are given an m x n grid where each cell can have one of three values:

0 representing an empty cell,
1 representing a fresh orange, or
2 representing a rotten orange.
Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.

 

Example 1:


Input: grid = [[2,1,1],[1,1,0],[0,1,1]]
Output: 4
Example 2:

Input: grid = [[2,1,1],[0,1,1],[1,0,1]]
Output: -1
Explanation: The orange in the bottom left corner (row 2, column 0) is never rotten, because rotting only happens 4-directionally.
Example 3:

Input: grid = [[0,2]]
Output: 0
Explanation: Since there are already no fresh oranges at minute 0, the answer is just 0.
*/
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int freshCount = 0;
        int time = 0;
        queue<pair<pair<int, int>, int>>q;

        vector<vector<int>>temp(m, vector<int>(n, 0));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                temp[i][j] = grid[i][j];
                if(grid[i][j] == 1) freshCount++;
                else if(grid[i][j] == 2) q.push({{i, j}, 0});
            }
        }

        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int minute = q.front().second;
            q.pop();
            time = max(time, minute);

            if(col - 1 >= 0 && temp[row][col - 1] == 1){
                freshCount--;
                temp[row][col - 1] = 2;
                q.push({{row, col - 1}, minute + 1});
            }

            if(col + 1 < n && temp[row][col + 1] == 1){
                freshCount--;
                temp[row][col + 1] = 2;
                q.push({{row, col + 1}, minute + 1});
            }

            if(row - 1 >= 0 && temp[row - 1][col] == 1){
                freshCount--;
                temp[row - 1][col] = 2;
                q.push({{row - 1, col}, minute + 1});
            }

            if(row + 1 < m && temp[row + 1][col] == 1){
                freshCount--;
                temp[row + 1][col] = 2;
                q.push({{row + 1, col}, minute + 1});
            }


        }
        return freshCount == 0 ? time : -1;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> grid = {{2,1,1},{1,1,0},{0,1,1}};
    int result = sol.orangesRotting(grid);
    cout << "Minimum time until no fresh oranges: " << result << endl; // Output: 4
    return 0;
}