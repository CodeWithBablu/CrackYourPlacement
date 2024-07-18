#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int removeDuplicates(vector<int> &nums)
  {

    int prev = INT_MIN, l = 0;
    int k = 0;

    for (int i = 0; i < nums.size(); i++)
    {
      if (prev != nums[i])
      {
        prev = nums[i];
        nums[l] = nums[i];
        l++;
        k++;
      }
    }

    return k;
  }
};