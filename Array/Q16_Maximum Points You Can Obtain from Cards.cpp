#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int maxScore(vector<int> &cardPoints, int k)
  {

    int total_pts = cardPoints[0], size = cardPoints.size();

    int sumOfCurrentWindow = 0, max_pts = INT_MIN;
    vector<int> prefixSum(size, 0);
    prefixSum[0] = cardPoints[0];

    for (int i = 1; i < size; i++)
    {
      total_pts += cardPoints[i];
      prefixSum[i] = prefixSum[i - 1] + cardPoints[i];
    }

    if (size == k)
      return total_pts;

    int l = 0, r = size - k - 1;
    while (r < size)
    {
      sumOfCurrentWindow = prefixSum[r] - (l > 0 ? prefixSum[l - 1] : 0);
      max_pts = max(max_pts, total_pts - sumOfCurrentWindow);
      r++;
      l++;
    }

    return max_pts;
  }
};