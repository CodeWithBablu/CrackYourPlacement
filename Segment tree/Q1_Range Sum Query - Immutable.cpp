#include <bits/stdc++.h>
using namespace std;

class NumArray
{
public:
  vector<int> seg;
  int n;
  void build(vector<int> &nums, int treeIndex, int low, int high)
  {
    if (low == high)
    {
      seg[treeIndex] = nums[low];
      return;
    }
    int mid = (low + high) / 2;
    build(nums, 2 * treeIndex + 1, low, mid);
    build(nums, 2 * treeIndex + 2, mid + 1, high);
    seg[treeIndex] = seg[2 * treeIndex + 1] + seg[2 * treeIndex + 2];
  }
  int query(int treeIndex, int low, int high, int lq, int hq)
  {
    if (low >= lq && high <= hq)
      return seg[treeIndex];
    if (low > hq || high < lq)
      return 0;
    int mid = (low + high) / 2;
    int lQuery = query(2 * treeIndex + 1, low, mid, lq, hq);
    int rQuery = query(2 * treeIndex + 2, mid + 1, high, lq, hq);
    return lQuery + rQuery;
  }
  NumArray(vector<int> &nums)
  {
    n = nums.size();
    seg.resize(4 * n);
    build(nums, 0, 0, n - 1);
  }

  int sumRange(int left, int right)
  {
    return query(0, 0, n - 1, left, right);
  }
};