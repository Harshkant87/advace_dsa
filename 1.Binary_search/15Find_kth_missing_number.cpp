/*
Problem statement
You are given a strictly increasing array 'vec' and a positive integer 'k'.



Find the 'kth' positive integer missing from 'vec'.



Example :
Input: vec = [2,4,5,7] , k = 3

Output: 6

Explanation : 
In the given example, first missing positive integer is 1 second missing positive integer is 3, and the third missing positive integer is 6.
Hence the answer is 6

*/
#include <iostream>
#include <vector>
using namespace std;

int missingK(vector < int > vec, int n, int k) {
    // Write your code here.
    int low = 0;
    int high = n - 1;

    while(low <= high){
        int mid = low + (high - low) / 2;
        int missing = vec[mid] - (mid + 1);

        if(missing < k)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return high + 1 + k; // derived from the fact that the missing number is greater than the high index + k
}

int main() {
    vector < int > vec = {
        2,
        4,
        5,
        7
    };
    int n = 4;
    int k = 3;
    cout << missingK(vec, n, k);
    return 0;
}