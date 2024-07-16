#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  void sortColors(vector<int> &nums)
  {
    int l = 0, i = 0, r = nums.size() - 1;

    while (i <= r)
    {
      if (nums[i] == 0)
      {
        swap(nums[i], nums[l]);
        l++;
        i++;
      }
      else if (nums[i] == 2)
      {
        swap(nums[i], nums[r]);
        r--;
      }
      else
        i++;
    }
  }
};