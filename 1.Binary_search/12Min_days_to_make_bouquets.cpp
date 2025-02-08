/*
Problem statement
You are given 'n' roses and you are also given an array 'arr' where 'arr[i]' denotes that the 'ith' rose will bloom on the 'arr[i]th' day.



You can only pick already bloomed roses that are adjacent to make a bouquet. You are also told that you require exactly 'k' adjacent bloomed roses to make a single bouquet.



Find the minimum number of days required to make at least 'm' bouquets each containing 'k' roses. Return -1 if it is not possible.



Example :
Input: n = 9,  arr = [ 1, 2, 1, 2, 7, 2, 2, 3, 1 ], k = 3, m = 2

Output: 3. 

Explanation: This is because on the 3rd day: all the roses with 'arr[i]' less than equal to 3 have already bloomed, this means every rose except the 5th rose has bloomed. Now we can form the first bouquet from the first three roses and the second bouquet from the last three roses.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int numOfBouq(vector<int> arr, int k, int numOfDays){
	int numsOfBouquets = 0, count = 0;
	for(int day: arr){
		if(day <= numOfDays){
			count++;
		}
		else{
			numsOfBouquets += (count / k);
			count = 0;
		}
	}
	numsOfBouquets += (count / k);
	return numsOfBouquets;
}

int roseGarden(vector<int> arr, int k, int m)
{
	// Write your code here
	int low = *min_element(arr.begin(), arr.end());
	int high = *max_element(arr.begin(), arr.end());
	int ans = -1;

	while(low <= high){
		int mid = low + (high - low) / 2;
		if(numOfBouq(arr, k, mid) >= m){
			ans = mid;
			high = mid - 1;
		}
		else
			low = mid + 1;
	}
	return ans;
}

int main()
{
    int n = 9, k = 3, m = 2;
    vector<int> arr = {1, 2, 1, 2, 7, 2, 2, 3, 1};
    cout << roseGarden(arr, k, m) << endl;
    return 0;
}