/*
Given an array nums and an integer k.Return the number of non-empty subsequences of nums such that the sum of all elements in the subsequence is equal to k.


Examples:
Input : nums = [4, 9, 2, 5, 1] , k = 10

Output : 2

Explanation : The possible subsets with sum k are [9, 1] , [4, 5, 1].

Input : nums = [4, 2, 10, 5, 1, 3] , k = 5

Output : 3

Explanation : The possible subsets with sum k are [4, 1] , [2, 3] , [5].

time complexity: O(2^n), where n is the number of elements in the input array.
space complexity: O(n), where n is the number of elements in the input array, for storing the current subset.

*/

#include <iostream>
#include <vector>

using namespace std;

class Solution{
    private:
    int utils(vector<int>& nums, int index, int k){
        if(k == 0)
            return 1;
        if(index >= nums.size() || k < 0)
            return 0;
        int notTake = utils(nums, index + 1, k);
        int take = utils(nums, index + 1, k - nums[index]);

        return notTake + take;
    }

    public:    	
    int countSubsequenceWithTargetSum(vector<int>& nums, int k){
    	//your code goes here
        return utils(nums, 0, k);
    }
};

int main() {
    Solution sol;
    vector<int> nums = {4, 9, 2, 5, 1};
    int k = 10;
    int result = sol.countSubsequenceWithTargetSum(nums, k);
    cout << "Number of subsequences with sum " << k << ": " << result << endl;

    nums = {4, 2, 10, 5, 1, 3};
    k = 5;
    result = sol.countSubsequenceWithTargetSum(nums, k);
    cout << "Number of subsequences with sum " << k << ": " << result << endl;

    return 0;
}