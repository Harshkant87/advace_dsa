/*
Problem statement
You are given a positive integer ‘n’.



Your task is to find and return its square root. If ‘n’ is not a perfect square, then return the floor value of sqrt(n).



Example:
Input: ‘n’ = 7

Output: 2

Explanation:
The square root of the number 7 lies between 2 and 3, so the floor value is 2.
*/

#include <iostream>
#include <vector>

using namespace std;

int floorSqrt(int n)
{
    // Write your code here.
    int low = 1, high = n;
    while(low <= high){
        long long mid = low + (high - low) / 2;
        long long val = mid * mid;
        if(val <= n) // this may be answer but look right side
            low = mid + 1;
        else
            high = mid - 1; // this is not answer so look left side
    }
    return high;
}

int main()
{
    int n;
    cin >> n;
    cout << floorSqrt(n) << endl;
    return 0;
}