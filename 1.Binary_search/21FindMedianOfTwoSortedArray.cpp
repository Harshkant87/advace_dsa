/*
Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

The overall run time complexity should be O(log (m+n)).

 

Example 1:

Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.
Example 2:

Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.

*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<limits>
#include<cmath>

using namespace std;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int n1 = nums1.size();
    int n2 = nums2.size();

    if(n1 > n2) return findMedianSortedArrays(nums2, nums1);
    int low = 0;
    int high = n1;
    int left = (n1 + n2 + 1) / 2;
    int totalSize = n1 + n2;

    while(low <= high){
        int mid1 = (low + high) >> 1;
        int mid2 = left - mid1;
        int l1 = numeric_limits<int>::min();
        int l2 = numeric_limits<int>::min();
        int r1 = numeric_limits<int>::max();
        int r2 = numeric_limits<int>::max();

        if(mid1 < n1) r1 = nums1[mid1];
        if(mid2 < n2) r2 = nums2[mid2];
        if(mid1 - 1 >= 0) l1 = nums1[mid1 - 1];
        if(mid2 - 1 >= 0) l2 = nums2[mid2 - 1];

        if(l1 <= r2 && l2 <= r1){
            if(totalSize % 2 == 1){
                return max(l1, l2);
            }
            else{
                return ((double)(max(l1, l2) + min(r1, r2))) / 2.0;
            }
        }
        if(l1 > r2) high = mid1 - 1;
        else low = mid1 + 1;
    }
    return 0;
}

int main() {
    vector<int> nums1 = {1, 3};
    vector<int> nums2 = {2};

    double median = findMedianSortedArrays(nums1, nums2);
    cout << "The median is: " << median << endl;

    return 0;
}
