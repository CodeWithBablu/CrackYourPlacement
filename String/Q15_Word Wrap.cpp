#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int dp[501];
  int f(int idx, int k, vector<int> &nums)
  {

    if (idx >= nums.size())
      return 0;
    if (dp[idx] != -1)
      return dp[idx];
    int sum = 0;
    int mini = 1e9;
    int cnt = 0;
    for (int i = idx; i < nums.size(); i++)
    {
      sum += nums[i];

      if (k - sum >= 0 && i == nums.size() - 1)
        return dp[idx] = 0;
      else if (i == nums.size() - 1)
        return mini;
      if (k - sum >= 0)
      {
        int cost = (k - sum) * (k - sum) + f(i + 1, k, nums);
        mini = min(mini, cost);
      }
      else
        break;
      sum++;
    }
    return dp[idx] = mini;
  }
  int solveWordWrap(vector<int> nums, int k)
  {
    // Code here
    memset(dp, -1, sizeof(dp));
    return f(0, k, nums);
  }
};