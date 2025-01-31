/*
Problem statement
You are given an array 'arr' of size 'n' having unique elements that has been sorted in ascending order and rotated between 1 and 'n' times which is unknown.



The rotation involves shifting every element to the right, with the last element moving to the first position. For example, if 'arr' = [1, 2, 3, 4] was rotated one time, it would become [4, 1, 2, 3].



Your task is to find the minimum number in this array.



Note :
All the elements in the array are distinct. 


Example :
Input: arr = [3,4,5,1,2]

Output: 1

Explanation: The original array was [1,2,3,4,5] and it was rotated 3 times.


*/

#include <iostream>
#include <vector>

using namespace std;

int findMin(vector<int>& arr)
{
	// Write your code here.
	int low = 0, high = arr.size() - 1;
	int ans = INT_MAX;

	while(low <= high){
		int mid = low + (high - low) / 2;

		if(arr[low] <= arr[mid]){ // left part is sorted
			ans = min(ans, arr[low]); // update the answer
			low = mid + 1; // move to the right part
		}
		else{ // right part is sorted
			ans = min(ans, arr[mid]); // update the answer
			high = mid - 1; // move to the left part
		}
	}
	return ans;
}

// this is the same as the above function but instead of returning the minimum element, we are returning the index of the minimum element
int findKRotation(vector<int> &arr){
    // Write your code here. 
    int low = 0;
    int high = arr.size() - 1;
    int ans = 1e9;
    int minIndex = -1;


    while(low <= high){
        int mid = low + (high - low) / 2;

        if(arr[low] <= arr[mid]){
            if(arr[low] < ans){
                ans = arr[low];
                minIndex = low;
            }
            low = mid + 1;
        }
        else{
            if(arr[mid] < ans){
                ans = arr[mid];
                minIndex = mid;
            }
            high = mid - 1;
        }
    }
    return minIndex;   
}

int main()
{
    vector<int> arr = {3, 4, 5, 1, 2};
    cout << findMin(arr) << endl;
    cout << findKRotation(arr) << endl;
    return 0;
}