/*
Given an integer array nums of unique elements, return all possible subsets (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.

 

Example 1:

Input: nums = [1,2,3]
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
Example 2:

Input: nums = [0]
Output: [[],[0]]

step-by-step solution:
1. Initialize a vector to store the result.
2. Define a recursive function that takes the current index and the current subset as parameters.
3. In the recursive function:
   a. If the current index is equal to the size of the input array, add the current subset to the result.
   b. Otherwise, include the current element in the subset and call the function recursively with the next index.
   c. Exclude the current element from the subset and call the function recursively with the next index.

time complexity: O(2^n), where n is the number of elements in the input array.
space complexity: O(n), where n is the number of elements in the input array, for storing the current subset.

*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    vector<vector<int>>ans;
    vector<int>temp;

    void subsetsUtils(int index, vector<int>& nums){
        if(index >= nums.size()){
            ans.push_back(temp);
            return;
        }
        temp.push_back(nums[index]); // include the current element
        // Explore the next index with the current element included
        subsetsUtils(index + 1, nums);
        temp.pop_back();

        // Backtrack to explore the next index without the current element
        subsetsUtils(index + 1, nums); // exclude the current element
        // Explore the next index without the current element
    }

public:
    vector<vector<int>> subsets(vector<int>& nums) {
        ans.clear();
        temp.clear();

        subsetsUtils(0, nums);
        return ans;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> result = solution.subsets(nums);

    cout << "Subsets: " << endl;
    for (const auto& subset : result) {
        cout << "[";
        for (int num : subset) {
            cout << num << " ";
        }
        cout << "]" << endl;
    }

    return 0;
}