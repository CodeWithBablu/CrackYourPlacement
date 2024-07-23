#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  // nums: given vector
  // return the Product vector P that hold product except self at each index
  vector<long long int> productExceptSelf(vector<long long int> &nums, int n)
  {

    // code here
    int len = nums.size();
    vector<long long> p(nums.size(), 1);
    vector<long long> left(nums.size(), 1);
    vector<long long> right(nums.size(), 1);
    long long product = 1;

    for (int i = 1, j = len - 2; i < len, j >= 0; i++, j--)
    {
      left[i] *= left[i - 1] * nums[i - 1];
      right[j] *= right[j + 1] * nums[j + 1];
    }

    // cout<<product<<endl;

    for (int i = 0; i < nums.size(); i++)
    {
      p[i] = (left[i] * right[i]);
    }

    return p;
  }
};