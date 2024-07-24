#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  string repeatString(const string &str, int times)
  {
    string result;
    for (int i = 0; i < times; ++i)
    {
      result += str;
    }
    return result;
  }

  string intToRoman(int num)
  {
    vector<pair<int, string>> symList = {
        {1, "I"},
        {4, "IV"},
        {5, "V"},
        {9, "IX"},
        {10, "X"},
        {10, "X"},
        {40, "XL"},
        {50, "L"},
        {90, "XC"},
        {100, "C"},
        {100, "C"},
        {400, "CD"},
        {500, "D"},
        {900, "CM"},
        {1000, "M"},
    };

    int n = symList.size(), val = 1;
    string res = "";
    for (int i = n - 1; i >= 0; i--)
    {
      val = num / symList[i].first;
      if (val)
      {
        res += repeatString(symList[i].second, val);
        num = num % symList[i].first;
        if (num == 0)
          break;
      }
    }

    return res;
  }
};