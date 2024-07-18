#include <bits/stdc++.h>
using namespace std;

/// @brief
class Solution
{
public:
  void moveZeroes(vector<int> &nums)
  {

    for (int lastZero = 0, curr = 0; curr < nums.size(); curr++)
    {
      if (nums[curr] != 0)
      {
        swap(nums[curr], nums[lastZero++]);
      }
    }
  }
};