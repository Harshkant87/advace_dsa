/*
    Problem statement
You have been given a sorted array/list 'arr' consisting of ‘n’ elements. You are also given an integer ‘k’.



Now the array is rotated at some pivot point unknown to you.



For example, if 'arr' = [ 1, 3, 5, 7, 8], then after rotating 'arr' at index 3, the array will be 'arr' = [7, 8, 1, 3, 5].



Now, your task is to find the index at which ‘k’ is present in 'arr'.



Note :
1. If ‘k’ is not present in 'arr', then print -1.
2. There are no duplicate elements present in 'arr'. 
3. 'arr' can be rotated only in the right direction.


Example:
Input: 'arr' = [12, 15, 18, 2, 4] , 'k' = 2

Output: 3


 */

#include <iostream>
#include <vector>
using namespace std;

int search(vector<int>& arr, int n, int target)
{
    // Write your code here.
    // Return the position of K in ARR else return -1.
    int low = 0;
    int high = n - 1;

    while(low <= high){
        int mid = low + (high -low) / 2;

        if(arr[mid] == target)
            return mid;
        
        if(arr[low] <= arr[mid]){ // left part is sorted
            if(arr[low] <= target && arr[mid] >= target){ // target in the sorted part
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        else{ // right part is sorted
            if(arr[mid] <= target && target <= arr[high]){ // target in the srted part
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }

        }
    }
    return -1;
}

int main()
{
    vector<int> arr = {12, 15, 18, 2, 4};
    int n = arr.size();
    int target = 2;
    cout << search(arr, n, target) << endl;
    return 0;
}
