/*
Problem statement
Given an integer array ‘A’ of size ‘N’ and an integer ‘K'.



Split the array ‘A’ into ‘K’ non-empty subarrays such that the largest sum of any subarray is minimized.



Your task is to return the minimized largest sum of the split.



A subarray is a contiguous part of the array.



Example:
Input: ‘N’ = 5, ‘A’ = [1, 2, 3, 4, 5], ‘K’ = 3

Output: 6

Explanation: There are many ways to split the array ‘A’ into K consecutive subarrays. The best way to do this is to split the array ‘A’ into [1, 2, 3], [4], and [5], where the largest sum among the three subarrays is only 6.

This problem is also same as allocate min number of pages or painters partition problem.
*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;

bool isKSubarray(vector<int>&a, int maxSum, int &k){
    int totalSubarrays = 1;
    int totalSum = 0;

    for(int num: a){
        if(totalSum + num <= maxSum)
            totalSum += num;
        else{
            totalSum = num;
            totalSubarrays++;
        }
    }
    return totalSubarrays <= k;
}

int largestSubarraySumMinimized(vector<int> a, int k) {
    // Write Your Code Here
    int low = *max_element(a.begin(), a.end());
    int high = accumulate(a.begin(), a.end(), 0);

    while(low <= high){
        int mid = low + (high - low) / 2;
        if(isKSubarray(a, mid, k)){
            high = mid - 1; // num of subarrays less than or equals k hence decreasing the sum to increase the number of subarrays
        }
        else{
            low = mid + 1;
        }
    }
    return low;
}

int main(){
    vector<int> a = {1, 2, 3, 4, 5};
    int k = 3;
    cout<<largestSubarraySumMinimized(a, k)<<endl;
    return 0;
}