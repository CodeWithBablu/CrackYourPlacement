#include <bits/stdc++.h>
using namespace std;

/// @brief
/*
  use sorting keep two pointer l and r just slide l and r by 1. r++, l++
  just check the difference. if diffrence is < currMin chnage the currMin
*/

class Solution
{
public:
  long long findMinDiff(vector<long long> a, long long n, long long m)
  {
    // code
    sort(a.begin(), a.end());

    int l = 0, r = m - 1, min = INT_MAX;

    while (r < a.size())
    {
      if (a[r] - a[l] < min)
      {
        min = a[r] - a[l];
      }

      r++;
      l++;
    }

    return min;
  }
};