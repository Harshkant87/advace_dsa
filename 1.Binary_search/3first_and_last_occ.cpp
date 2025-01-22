/*

Problem statement
You have been given a sorted array/list 'arr' consisting of ‘n’ elements. You are also given an integer ‘k’.

Now, your task is to find the first and last occurrence of ‘k’ in 'arr'.

If ‘k’ is not present in 'arr', then return -1, -1.

Input: 'arr' = [0,1,1,5] , 'k' = 1

Output: 1 2

*/
#include<iostream>
#include<vector>

using namespace std;

int firstOccurence(vector<int>& arr, int n, int k){
    int first = -1;
    int low = 0, high = n - 1;

    while(low <= high){
        int mid = low + (high - low) / 2;

        if(arr[mid] == k)
            first = mid, high = mid - 1;
        else if(arr[mid] > k)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return first;
}

int secondOccurence(vector<int>& arr, int n, int k){
    int second = -1;
    int low = 0, high = n - 1;

    while(low <= high){
        int mid = low + (high - low) / 2;

        if(arr[mid] == k)
            second = mid, low = mid + 1;
        else if(arr[mid] < k)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return second;
}

pair<int, int> firstAndLastPosition(vector<int>& arr, int n, int k)
{
    // Write your code here
    int first = firstOccurence(arr, n, k);
    if(first == -1) return {-1, -1};
    int second = secondOccurence(arr, n, k);
    return {first, second};
}

int main(){
    vector<int> arr = {0, 1, 1, 5};
    int n = arr.size();
    int k = 1;
    pair<int, int> ans = firstAndLastPosition(arr, n, k);
    cout << "First occurence of " << k << " is " << ans.first << " and second occurence is " << ans.second << endl;
    // using similar approcah we can find total count of element in a sorted array.
    return 0;
}