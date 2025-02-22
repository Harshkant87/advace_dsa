/*
Problem statement
Given an array/list of length ‘n’, where the array/list represents the boards and each element of the given array/list represents the length of each board. Some ‘k’ numbers of painters are available to paint these boards. Consider that each unit of a board takes 1 unit of time to paint.



You are supposed to return the area of the minimum time to get this job done of painting all the ‘n’ boards under a constraint that any painter will only paint the continuous sections of boards.



Example :
Input: arr = [2, 1, 5, 6, 2, 3], k = 2

Output: 11

Explanation:
First painter can paint boards 1 to 3 in 8 units of time and the second painter can paint boards 4-6 in 11 units of time. Thus both painters will paint all the boards in max(8,11) = 11 units of time. It can be shown that all the boards can't be painted in less than 11 units of time.

This question is as same as book allcation problem

*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>

using namespace std;

int numOfPainters(vector<int> &boards, int maxArea){
    int painters = 1;
    int totalArea = 0;

    for(int area: boards){
        if(totalArea + area <= maxArea){
            totalArea += area;
        }
        else{
            painters++;
            totalArea = area;
        }
    }
    return painters;
}

int findLargestMinDistance(vector<int> &boards, int k)
{
    //    Write your code here.
    int low = *max_element(boards.begin(), boards.end());
    int high = accumulate(boards.begin(), boards.end(), 0);
    int ans = 0;

    while(low <= high){
        int mid = low + (high - low) / 2;
        if(numOfPainters(boards, mid) <= k){
            high = mid - 1;
            ans = mid;
        }
        else{
            low = mid + 1;
        }
    }
    return ans;
}

int main(){
    vector<int> boards = {2, 1, 5, 6, 2, 3};
    int k = 2;
    cout << findLargestMinDistance(boards, k) << endl;
    return 0;
}