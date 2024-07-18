#include <bits/stdc++.h>
using namespace std;

/// @brief using hashMap
class Solution
{
public:
  vector<int> twoSum(vector<int> &nums, int target)
  {
    unordered_map<int, int> nPos;

    for (int i = 0; i < nums.size(); i++)
    {
      if (nPos.find(target - nums[i]) != nPos.end())
        return {nPos[target - nums[i]], i};

      nPos[nums[i]] = i;
    }

    return {0, 0};
  }
};