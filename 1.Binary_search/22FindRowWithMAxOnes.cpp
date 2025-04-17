/*
Given a non-empty grid mat consisting of only 0s and 1s, where all the rows are sorted in ascending order, find the index of the row with the maximum number of ones.

If two rows have the same number of ones, consider the one with a smaller index. If there's no row with at least 1 zero, return -1.


Examples:
Input : mat = [ [1, 1, 1], [0, 0, 1], [0, 0, 0] ]

Output: 0

Explanation: The row with the maximum number of ones is 0 (0 - indexed).

Input: mat = [ [0, 0], [0, 0] ]

Output: -1

Explanation: The matrix does not contain any 1. So, -1 is the answer.

*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int lower_bound(vector<int>nums, int k, int n){
    int ans = n;
    int low = 0;
    int high = n - 1;

    while(low <= high){
      int mid = low + (high - low) / 2;
      if(nums[mid] >= k){
        ans = mid;
        high = mid - 1;
      }
      else{
        low = mid + 1;
      }
    }
    return ans;
  }

  int rowWithMax1s(vector < vector < int >> & mat) {
    int row = mat.size();
    int col = mat[0].size();

    int count = 0;
    int ans_row = -1;

    for(int i = 0; i < row; i++){
      int count_ones = col - lower_bound(mat[i], 1, col);
      if(count_ones > count){
        ans_row = i;
        count = count_ones;
      }
    }
    return ans_row;
  }

int main() {
    vector<vector<int>> mat = {
        {0, 0, 1},
        {0, 1, 1},
        {1, 1, 1}
    };

    int result = rowWithMax1s(mat);
    cout << "Row with maximum number of ones: " << result << endl;

    return 0;
}