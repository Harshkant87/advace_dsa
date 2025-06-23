/*
mergeSort.cpp
This file contains the implementation of the merge sort algorithm.
It includes functions to merge two sorted subarrays and to perform the merge sort on an array.
The merge sort algorithm is a divide-and-conquer algorithm that sorts an array by recursively dividing it into two halves, sorting each half, and then merging the sorted halves back together.

Time Complexity: O(n log n), where n is the number of elements in the array.
Space Complexity: O(n), where n is the number of elements in the array, for storing the temporary arrays during merging.

*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    void merge(vector<int>& arr, int left, int mid, int right) {
        int n1 = mid - left + 1;
        int n2 = right - mid;

        vector<int> L(n1), R(n2);

        for (int i = 0; i < n1; i++)
            L[i] = arr[left + i];
        for (int j = 0; j < n2; j++)
            R[j] = arr[mid + 1 + j];

        int i = 0, j = 0, k = left;
        while (i < n1 && j < n2) {
            if (L[i] <= R[j]) {
                arr[k++] = L[i++];
            } else {
                arr[k++] = R[j++];
            }
        }

        while (i < n1) {
            arr[k++] = L[i++];
        }
        while (j < n2) {
            arr[k++] = R[j++];
        }
    }

    void mergeSortUtil(vector<int>& arr, int left, int right) {
        if (left < right) {
            int mid = left + (right - left) / 2; // Prevents overflow
            // Recursively sort the first and second halves
            mergeSortUtil(arr, left, mid); // Sort the first half
            mergeSortUtil(arr, mid + 1, right); // Sort the second half
            merge(arr, left, mid, right); // Merge the sorted halves
        }
    }
public:
    void mergeSort(vector<int>& arr) {
        if (arr.empty()) return; // Handle empty array case
        mergeSortUtil(arr, 0, arr.size() - 1);
    }

};

int main() {
    Solution sol;
    vector<int> arr = {38, 27, 43, 3, 9, 82, 10};
    
    cout << "Original array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    sol.mergeSort(arr);

    cout << "Sorted array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}