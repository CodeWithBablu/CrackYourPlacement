#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int maxProfit(vector<int> &prices)
  {

    int bprice = prices[0], profit = 0;

    for (auto price : prices)
    {
      if (price > bprice)
      {
        profit += price - bprice;
      }

      bprice = price;
    }

    return profit;
  }
};