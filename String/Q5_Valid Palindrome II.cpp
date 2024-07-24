#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  bool checkPalindrome(string &s, int l, int r)
  {
    while (l < r)
    {
      if (s[l++] != s[r--])
        return false;
    }
    return true;
  }

  bool validPalindrome(string s)
  {
    int canSkipCnt = 1;
    int i = 0, j = s.size() - 1;
    while (i < j)
    {
      if (s[i] != s[j])
      {
        return checkPalindrome(s, i, j - 1) || checkPalindrome(s, i + 1, j);
      }
      i++;
      j--;
    }

    return true;
  }
};