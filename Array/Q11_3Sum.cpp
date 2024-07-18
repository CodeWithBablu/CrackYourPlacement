#include <bits/stdc++.h>
using namespace std;

/// @brief using sorting and then two pointer
class Solution
{
public:
  vector<vector<int>> threeSum(vector<int> &nums)
  {

    vector<vector<int>> ans;

    sort(nums.begin(), nums.end());

    if (nums.empty())
      return ans;

    int j = 0, k = 0, sum = 0;

    for (int i = 0; i + 2 < nums.size(); i++)
    {
      j = i + 1;
      k = nums.size() - 1;
      sum = 0;
      if (i > 0 && nums[i] == nums[i - 1])
        continue;

      while (j < k)
      {

        sum = nums[i] + nums[j] + nums[k];

        if (sum == 0)
        {
          ans.push_back({nums[i], nums[j], nums[k]});
          k--;
          while (j < k && nums[k] == nums[k + 1])
            k--;
        }
        else if (sum > 0)
        {
          k--;
        }
        else
        {
          j++;
        }
      }
    }

    return ans;
  }
};