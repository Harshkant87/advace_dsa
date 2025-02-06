/*
Problem statement
You are given two positive integers 'n' and 'm'. You have to return the 'nth' root of 'm', i.e. 'm(1/n)'. If the 'nth root is not an integer, return -1.



Note:
'nth' root of an integer 'm' is a number, which, when raised to the power 'n', gives 'm' as a result.


Example:
Input: ‘n’ = 3, ‘m’ = 27

Output: 3

Explanation: 
3rd Root of 27 is 3, as (3)^3 equals 27.
*/

#include <iostream>
#include <vector>

using namespace std;

int func(int mid, int n, int m) {
    long long ans = 1;
    for (int i = 1; i <= n; i++) {
        ans = ans * mid;
        if (ans > m) return 2; // to avoid overflow
    }
    if (ans == m) return 1;
    return 0;
}

int NthRoot(int n, int m) {
  // Write your code here.
  int low = 1;
  int high = m;

  while(low <= high){
    int mid = (high + low) / 2;
    int prod = func(mid, n, m);

    if(prod == 2){
      high = mid - 1;
    }
    else if(prod == 0){
      low = mid + 1;
    }
    else{
      return mid;
    }
  }
  return -1;
}

int main()
{
    int n, m;
    cin >> n >> m;
    cout << NthRoot(n, m) << endl;
    return 0;
}