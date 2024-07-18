#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int subarraySum(vector<int> &nums, int k)
  {
    vector<int> prefix(nums.size(), 0);
    unordered_map<int, int> freq; // storing prefix frequencies
    int value = 0, len = nums.size(), cnt = 0;

    prefix[0] = nums[0];
    freq[0] = 1; // edge case if prefix==k
    for (int i = 1; i < len; i++)
    {
      prefix[i] = prefix[i - 1] + nums[i];
    }

    for (int i = 0; i < len; i++)
    {
      value = prefix[i] - k; // value we need to find in prefreq
      if (freq.find(value) != freq.end())
      {
        cnt += freq[value];
      }

      freq[prefix[i]]++;
    }

    return cnt;
  }
};