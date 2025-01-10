#include <bits/stdc++.h>
using namespace std;
// Time complexity: O(logn)
// Space complexity: O(1)
// Binary search is a fast search algorithm with run-time complexity of O(log n). 
// This search algorithm works on the principle of divide and conquer. For this algorithm to work properly, 
// the data collection should be in the sorted form.

int binarySearch(vector<int> arr, int target){
    int n = arr.size();
    int left = 0;
    int right = n - 1;
    while(left <= right){
        int mid = left + (right - left) / 2;
        if(arr[mid] == target){
            return mid;
        }
        else if(arr[mid] < target){
            left = mid + 1;
        }
        else{
            right = mid - 1;
        }
    }
    return -1;
}

int recursiveBinarySearch(vector<int> arr, int target, int left, int right){
    if(left > right){
        return -1;
    }
    int mid = left + (right - left) / 2;
    if(arr[mid] == target){
        return mid;
    }
    else if(arr[mid] < target){
        return recursiveBinarySearch(arr, target, mid + 1, right);
    }
    else{
        return recursiveBinarySearch(arr, target, left, mid - 1);
    }
}

int main(){
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int target = 3;
    int n = arr.size();
    int index = binarySearch(arr, target);
    if(index == -1){
        cout<<"target: "<<target<<" not found"<<endl;
    }
    else
        cout<<"target: "<<target<<" found at index: "<<index<<endl;

    cout<<"Recursive binary search"<<endl;
    int index2 = recursiveBinarySearch(arr, target, 0, n - 1);
    if(index2 == -1){
        cout<<"target: "<<target<<" not found"<<endl;
    }
    else
        cout<<"target: "<<target<<" found at index: "<<index2<<endl;
}
