#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  string addBinary(string a, string b)
  {
    int i = a.size() - 1, j = b.size() - 1, total = 0, carry = 0;
    string res = "";
    while (i >= 0 || j >= 0)
    {
      int digitA = (i >= 0 ? (a[i--] - '0') : 0);
      int digitB = (j >= 0 ? (b[j--] - '0') : 0);
      total = digitA + digitB + carry;

      res = to_string(total % 2) + res;
      carry = total / 2;
    }

    if (carry)
      res = to_string(carry) + res;

    return res;
  }
};