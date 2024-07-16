#include <bits/stdc++.h>
using namespace std;

/// @brief using set
class Solution
{
public:
  int findDuplicate(vector<int> &nums)
  {
    unordered_set<int> numsSet;

    for (int i = 0; i <= nums.size(); i++)
    {
      if (numsSet.find(nums[i]) != numsSet.end())
      {
        return nums[i];
      }

      numsSet.insert(nums[i]);
    }

    return 0;
  }
};

/// @brief using Binary search
class Solution
{
public:
  int findDuplicate(vector<int> &nums)
  {
    // ex: input array: [1,3,4,2,5,4,6]
    // treating array as [1,2,3...n] intead of input array so imagine our array as [1,2,3,4,4,5,6]

    int len = nums.size(), l = 1, h = len - 1;

    while (l < h)
    {
      int mid = l + (h - l) / 2;
      int cnt = 0;

      for (int i = 0; i < len; i++)
      {
        if (nums[i] <= mid)
          cnt++;
      }

      if (cnt <= mid)
      {
        l = mid + 1;
      }
      else
      {
        h = mid;
      }
    }

    return l;
  }
};

/// @brief using floyd's trotoise and hare method
class Solution
{
public:
  int findDuplicate(vector<int> &nums)
  {
    // ex: input array: [1,3,4,2,5,4,6]

    int slow = 0;
    int fast = 0;

    do
    {
      slow = nums[slow];
      fast = nums[nums[fast]];
    } while (slow != fast);

    // slow= 1,3,2,4 ...->{5,4,5,4}
    // fast= 3,4,4,4

    // slow= 1,3,2,4
    // fast= 5,4,5,4
    slow = 0;
    do
    {
      slow = nums[slow];
      fast = nums[fast];
    } while (slow != fast);

    return slow;
  }
};