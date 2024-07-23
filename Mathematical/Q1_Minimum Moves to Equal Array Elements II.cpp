#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int minMoves2(vector<int> &nums)
  {
    int moves = 0;
    int mid = nums.size() / 2;

    sort(nums.begin(), nums.end());

    for (int i = 0; i < nums.size(); i++)
    {
      moves += abs(nums[i] - nums[mid]);
    }

    return moves;
  }
};