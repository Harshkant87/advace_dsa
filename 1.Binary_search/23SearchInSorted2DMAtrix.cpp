/*
You are given an m x n integer matrix matrix with the following two properties:

Each row is sorted in non-decreasing order.
The first integer of each row is greater than the last integer of the previous row.
Given an integer target, return true if target is in matrix or false otherwise.

You must write a solution in O(log(m * n)) time complexity.

Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
Output: true

Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
Output: false
*/

#include <iostream>
#include <vector>
using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int row = matrix.size();
    int col = matrix[0].size();

    int low = 0;
    int high = (row * col) - 1;

    while(low <= high){
        int mid = low + (high - low ) / 2;
        int r = mid / col; // linearisng the 2D matrix to 1D
        int c = mid % col;

        int num = matrix[r][c];

        if(num == target) return true;
        else if(num > target) high = mid - 1;
        else low = mid + 1;
    }
    return false;
}

int main() {
    vector<vector<int>> matrix = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
    int target = 3;
    bool result = searchMatrix(matrix, target);
    cout << (result ? "true" : "false") << endl; // Output: true

    target = 13;
    result = searchMatrix(matrix, target);
    cout << (result ? "true" : "false") << endl; // Output: false

    return 0;
}
// Time Complexity: O(log(m * n)), where m is the number of rows and n is the number of columns in the matrix.