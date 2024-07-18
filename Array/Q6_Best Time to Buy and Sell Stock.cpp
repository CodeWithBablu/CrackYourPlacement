#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int maxProfit(vector<int> &prices)
  {

    int bprice = prices[0], maxProfit = 0;

    for (int i = 1; i < prices.size(); i++)
    {
      bprice = min(bprice, prices[i]);
      maxProfit = max(prices[i] - bprice, maxProfit);
    }

    return maxProfit;
  }
};