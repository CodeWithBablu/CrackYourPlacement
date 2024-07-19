#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<vector<int>> fourSum(vector<int> &nums, int target)
  {
    vector<vector<int>> ans;
    vector<int> quad;

    if (nums.size() < 4)
      return {};

    sort(nums.begin(), nums.end());

    function<void(int, int, long)> kSum = [&](int k, int start, long target) -> void
    {
      if (k != 2)
      {
        for (int i = start; i < nums.size() - k + 1; i++)
        {
          if (i > start && nums[i] == nums[i - 1])
            continue;
          quad.push_back(nums[i]);
          kSum(k - 1, i + 1, target - nums[i]);
          quad.pop_back();
        }

        return;
      }

      /// if k==2 we are calculating two sum here(using two pointer)
      int l = start, r = nums.size() - 1;
      long sum = 0;
      while (l < r)
      {
        sum = nums[l] + nums[r];

        if (sum == target)
        {
          vector<int> temp = quad;
          temp.insert(temp.end(), {nums[l], nums[r]});
          ans.push_back(temp);
          l++;
          while (l < r && nums[l] == nums[l - 1])
          {
            l++;
          }
        }
        else if (sum > target)
        {
          r--;
        }
        else
        {
          l++;
        }
      }
    };

    kSum(4, 0, target);
    return ans;
  }
};