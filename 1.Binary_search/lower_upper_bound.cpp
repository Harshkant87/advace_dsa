#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
//LowerBound: returns the min index i such that arr[i] >= x
// Time complexity: O(logn)

int lowerBound(vector<int> arr, int n, int x) {
	int low = 0, high = n - 1, ans = n;
	while(low <= high){
		int mid = low + (high - low) / 2;

		if(arr[mid] >= x){ // this may be m answer but i need to check the left part again
			ans = mid;
			high = mid - 1;
		}
		else{ // this is not my answer, i need to check the right part
			low = mid + 1;
		}
	}
	return ans;
}

//UpperBound: returns the min index i such that arr[i] > x
// Time complexity: O(logn)

int upperBound(vector<int> &arr, int x, int n){
	int low = 0, high = n - 1, ans = n;
	while(low <= high){
		int mid = low + (high - low) / 2;

		if(arr[mid] > x){ // this may be m answer but i need to check the left part again
			ans = mid;
			high = mid - 1;
		}
		else // this is not my answer, i need to check the right part
			low = mid + 1;
	}
	return ans;	
}

// problems on similar pattern: search insert, floor and ceil in sorted array

int main(){
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int n = arr.size();
    int x = 5;
    int index = lowerBound(arr, n, x);
    cout << "Lower bound of " << x << " is " << index << endl;

    int index2 = lower_bound(arr.begin(), arr.end(), x) - arr.begin(); // using STL
    cout << "Lower bound using STL of " << x << " is " << index2 << endl;

    int index3 = upperBound(arr, x, n);
    cout << "Upper bound of " << x << " is " << index3 << endl;

    int index4 = upper_bound(arr.begin(), arr.end(), x) - arr.begin(); // using STL
    cout << "Upper bound using STL of " << x << " is " << index4 << endl;
    return 0;

}