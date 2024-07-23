#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  string convertToTitle(int columnNumber)
  {
    string res = "";
    int offset = 0;

    while (columnNumber > 0)
    {
      offset = (columnNumber - 1) % 26;
      res = (char)(65 + offset) + res;
      columnNumber = (columnNumber - 1) / 26;
    }

    return res;
  }
};