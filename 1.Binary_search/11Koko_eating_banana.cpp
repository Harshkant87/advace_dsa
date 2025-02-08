/*
A monkey is given ‘n’ piles of bananas, where the 'ith' pile has ‘a[i]’ bananas. An integer ‘h’ is also given, which denotes the time (in hours) in which all the bananas should be eaten.



Each hour, the monkey chooses a non-empty pile of bananas and eats ‘m’ bananas. If the pile contains less than ‘m’ bananas, then the monkey consumes all the bananas and won’t eat any more bananas in that hour.



Find the minimum number of bananas ‘m’ to eat per hour so that the monkey can eat all the bananas within ‘h’ hours.



Example:

Input: ‘n’ = 4, ‘a’ =  [3, 6, 2, 8] , ‘h’ = 7

Output: 3
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

long long checkBanana(vector<int> &v, int hourlyBanana){
    long long totalHours = 0;
    for(int banana: v){
        totalHours += ceil(double(banana) / (double)hourlyBanana);
    }
    return totalHours;
}


int minimumRateToEatBananas(vector<int> v, int h) {
    // Write Your Code Here
    int max_banana = *max_element(v.begin(), v.end());
    // cout<<max_banana<<endl;
    int low = 1, high = max_banana;
    int ans = 0;

    while(low <= high){
        int mid = low + (high - low) / 2;

        if(checkBanana(v, mid) <= h){ // answer is possible
            ans = mid;
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    return ans;
}

int main()
{
    int n = 4, h = 7;
    vector<int> v = {3, 6, 2, 8};

    cout << minimumRateToEatBananas(v, h) << endl;
    return 0;
}