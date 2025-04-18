/*Write an efficient algorithm that searches for a value target in an m x n integer matrix matrix. This matrix has the following properties:

Integers in each row are sorted in ascending from left to right.
Integers in each column are sorted in ascending from top to bottom.

Input: matrix = [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]], target = 5
Output: true

Input: matrix = [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]], target = 20
Output: false

*/
#include <iostream>
#include <vector>
using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int n=matrix.size(),m=matrix[0].size(),r=0,c=m-1;
    
    while(r<n && c>=0){
        if(matrix[r][c]==target) 
            return true;
        
        matrix[r][c]>target ? c-- : r++; // move left if current element is greater than target, else move down
        
        }
    return false;
}

int main() {
    vector<vector<int>> matrix = {{1, 4, 7, 11, 15}, {2, 5, 8, 12, 19}, {3, 6, 9, 16, 22}, {10, 13, 14, 17, 24}, {18, 21, 23, 26, 30}};
    int target = 5;
    bool result = searchMatrix(matrix, target);
    cout << (result ? "true" : "false") << endl; // Output: true

    target = 20;
    result = searchMatrix(matrix, target);
    cout << (result ? "true" : "false") << endl; // Output: false

    return 0;
}
// Time Complexity: O(m+n), where m is the number of rows and n is the number of columns in the matrix. 
