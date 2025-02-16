/*
Problem statement
You are the owner of a Shipment company. You use conveyor belts to ship packages from one port to another. The packages must be shipped within 'd' days.



The weights of the packages are given in an array 'weights'. The packages are loaded on the conveyor belts every day in the same order as they appear in the array. The loaded weights must not exceed the maximum weight capacity of the ship.



Find out the least-weight capacity so that you can ship all the packages within 'd' days

Sample Input 1:
8 5
5 4 5 2 3 4 5 6
Sample Output 1:
9
Explanation for Sample Input 1:
In the test case, the given weights are [5,4,5,2,3,4,5,6] and these are needed to be shipped in 5 days. We can divide these weights in the following manner:
Day         Weights            Total
1        -   5, 4          -    9
2        -   5, 2          -    7
3        -   3, 4          -    7
4        -   5             -    5
5        -   6             -    6
The least weight capacity needed is 9, which is the total amount of weight that needs to be taken on Day 1.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int check_capacity(vector<int> &weights, int curr_capacity){
    int load = 0, days = 1;
    for(int w: weights){
        if(load + w <= curr_capacity)
        {
            load += w;
        }
        else{
            load = w;
            days += 1;
        }
    }
    return days;
}

int leastWeightCapacity(vector<int> &weights, int d)
{
    // Write your code here.
    int low_cap = *max_element(weights.begin(), weights.end());
    int high_cap = accumulate(weights.begin(), weights.end(), 0);
    int min_cap = 0;

    while(low_cap <= high_cap){
        int mid = low_cap + (high_cap - low_cap) / 2;

        if(check_capacity(weights, mid) <= d){
            min_cap = mid;
            high_cap = mid - 1;
        }
        else{
            low_cap = mid + 1;
        }
    }
    return min_cap;
}

int main()
{
    int n = 8, d = 5;
    vector<int> weights = {5, 4, 5, 2, 3, 4, 5, 6};
    cout << leastWeightCapacity(weights, d) << endl;
    return 0;
}
