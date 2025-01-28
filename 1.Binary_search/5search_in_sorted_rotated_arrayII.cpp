/*
Problem statement
You are given a rotated sorted array 'a' of length 'n' and a 'key'. You need to determine if the 'key' exists in the array 'a'.



The given sorted array is rotated from an unknown index 'x'. Such that after rotation the array became [a[x], a[x+1]...., a[n-1], a[1]..., a[x-1]], (0-based indexing). For example, if the array is [1, 2, 3, 4, 5] and x = 2 then the rotated array will be [3, 4, 5, 1, 2, 3].



Return True if the 'key' is found in 'a'. Otherwise, return False.



Note: Array ‘a’ may contain duplicate elements.



Example:

Input: a = [6, 10, 1, 3, 5], key = 3

Output: True

Explanation: The array 'a' contains the 'key' = 3, so we return True.

*/

#include <iostream>
#include <vector>

using namespace std;

bool searchInARotatedSortedArrayII(vector<int>&A, int key) {
    // Write your code here.
    int low = 0;
    int high = A.size() - 1;

    while(low <= high){
        int mid = low + (high - low) / 2;
        
        if(A[mid] == key)
            return true;
        
        if(A[low] == A[mid] && A[mid] == A[high]){ // focus point
            low++, high--; // trimming down the answer space
            continue;
        }

        if(A[low] <= A[mid]){ // left part is sorted
            if(key >= A[low] && key <= A[mid]) // key is in sorted range
                high = mid - 1;
            else
                low = mid + 1;
        }
        else{ // right part is sorted
            if(key >= A[mid] && key <= A[high]) // key is in sorted part
                low = mid + 1;
            else
                high = mid - 1;
        }
    }
    return false;
}

int main() {
    vector<int> A = {6, 6, 10, 1, 1, 3, 5, 5};
    int key = 3;

    cout << searchInARotatedSortedArrayII(A, key) << endl; // returns 1 as 3 is present in the array

    return 0;
}