#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  string removeKdigits(string num, int k)
  {
    int n = num.size();
    int ind = 0;
    if (k == n)
      return "0";
    while (num.size() > ind && k)
    {
      if (ind <= num.size() - 2 && num[ind] > num[ind + 1])
      {
        num.erase(ind, 1);
        ind--;
        k--;
      }
      else
        ind++;
      if (ind < 0)
        ind++;
    }
    ind = num.size() - 1;
    while (ind >= 0 && k)
    {
      if (num[ind] <= num[ind + 1])
      {
        num.erase(ind + 1, 1);
        ind++;
        k--;
      }
      ind--;
    }
    while (num[0] == '0' && num.size() > 1)
      num.erase(0, 1);

    return num;
  }
};