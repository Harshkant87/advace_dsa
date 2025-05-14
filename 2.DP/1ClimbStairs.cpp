/*
You are climbing a staircase. It takes n steps to reach the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

 

Example 1:

Input: n = 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps
Example 2:

Input: n = 3
Output: 3
Explanation: There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step

*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    vector<int>dp;
    void dpVectorSetter(int size){
        dp.resize(size + 1, -1);
    }
public:

    int climbStairsUtils(int steps){
        if(steps < 0)
            return 0;
        if(steps <= 2)
            return steps;
        if(dp[steps] != -1)
            return dp[steps];
        return dp[steps] = climbStairsUtils(steps - 1) + climbStairsUtils(steps - 2);
    }

    int climbStairs(int n) {
        dpVectorSetter(n);
        return climbStairsUtils(n);
    }
};

int main() {
    Solution solution;
    int n = 5; // Example input
    cout << "Number of distinct ways to climb to the top: " << solution.climbStairs(n) << endl;
    return 0;
}