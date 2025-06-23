/*
quick sort
This code implements the Quick Sort algorithm in C++. It defines a class `Solution` with methods to perform the sorting. The `quickSort` method is the main entry point, and it uses a helper method `quickSortUtil` to recursively sort the array. The partitioning is done using the `partition` method, which rearranges the elements based on a pivot.
Time Complexity: O(n log n) on average, O(n^2) in the worst case.
Space Complexity: O(log n) due to the recursive stack space used by the algorithm.

steps of the algorithm:
1. Choose a pivot element from the array.   
2. Partition the array into two halves: elements less than the pivot and elements greater than the pivot.
3. Recursively apply the same steps to the two halves until the base case is reached (when the left index is greater than or equal to the right index).


*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    int partition(vector<int>& arr, int low, int high) {
        int pivot = arr[low]; // Choose the first element as pivot
        int left = low + 1; // Start from the next element
        int right = high; // Start from the last element

        while (true) {
            while (left <= right && arr[left] <= pivot) left++; // Find the first element greater than pivot
            while (left <= right && arr[right] >= pivot) right--; // Find the first element less than pivot
            
            if (left > right) break; // If pointers cross, break the loop
            
            swap(arr[left], arr[right]); // Swap elements that are on the wrong side of the pivot
        }
        swap(arr[low], arr[right]); // Place the pivot in its correct position
        return right; // Return the partitioning index
    }

    void quickSortUtil(vector<int>& arr, int left, int right) {
        if (left < right) {
            int pi = partition(arr, left, right); // Partitioning index
            quickSortUtil(arr, left, pi - 1); // Recursively sort elements before partition
            quickSortUtil(arr, pi + 1, right); // Recursively sort elements after partition
        }
    }
public:
    void quickSort(vector<int>& arr) {
        if (arr.empty()) return; // Handle empty array case
        quickSortUtil(arr, 0, arr.size() - 1);
    }
};

int main() {
    Solution sol;
    vector<int> arr = {10, 7, 8, 9, 1, 5};
    
    cout << "Original array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    sol.quickSort(arr);

    cout << "Sorted array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}