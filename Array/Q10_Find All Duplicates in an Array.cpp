#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<int> findDuplicates(vector<int> &nums)
  {
    vector<int> duplicate;
    int index = 0;

    /*
    ex: [3,3,2,2]
        [0,1,2,3] //index

    use Value as index and mark the value at that index as negative
    step-1
        [3,3,-2,2]
        [0,1, 2,3] //index

    step-2
        [3,3,-2,2]
        [0,1, 2,3] //index
        we verify no at 3-1 index is already negative so 3 is repeated

    step-3
        [3,-3,-2,2] make valiue negative at nums[abs(2)-1]
        [0, 1, 2,3] //index

    step-4
        [3,-3,-2,2]
        [0, 1, 2,3] //index
        we verify no at 2-1 index is already negative so 2 is repeated

    Simply think that we are traversing the array. for each element x
        - go to nums[x-1] and make that value negative
        - before that check if nums[x-1] is negative
        - if it is bingo you have already come across this someone who converted this as negative bcoz it has to be positive.

        NOTE: we are making use of the contraint [1-n]

        -you can do dry run. thank you!!
    */
    for (int i = 0; i < nums.size(); i++)
    {
      index = abs(nums[i]) - 1;

      if (nums[index] < 0)
        duplicate.emplace_back(index + 1);

      nums[index] *= -1;
    }

    if (duplicate.size() == 0)
      return {};

    return duplicate;
  }
};