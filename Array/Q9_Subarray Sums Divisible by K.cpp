#include <bits/stdc++.h>
using namespace std;

/// @brief intuition
/*
prefixSum(j)=k(a)+r1;
prefixSum(i)=k(b)+r0;
prefixSum(j)-prefixSum(i)=k(a-b)+ (r1-r0)

so the sum of the no's in array btw j and i is divisible by k if remainder is same
*/
class Solution
{
public:
  int subarraysDivByK(vector<int> &nums, int k)
  {

    unordered_map<int, int> rFreq;
    rFreq[0]++;
    int cnt = 0, sum = 0, remainder = 1;

    for (int i = 0; i < nums.size(); i++)
    {
      sum += nums[i];
      remainder = sum % k;

      if (remainder < 0)
        remainder += k;

      if (rFreq.find(remainder) != rFreq.end())
      {
        cnt += rFreq[remainder];
      }
      rFreq[remainder]++;
    }

    return cnt;
  }
};