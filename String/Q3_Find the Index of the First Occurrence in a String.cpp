#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int strStr(string haystack, string needle)
  {

    if (haystack.size() < needle.size())
      return -1;

    int i = 0, j = needle.size() - 1, len = haystack.size();
    string word = "";

    while (j < len)
    {
      word = "";

      for (int x = 0, k = i; k <= j; k++, x++)
      {
        if (haystack[k] != needle[x])
          break;
        word += haystack[k];
      }

      if (word == needle)
        return i;

      i++;
      j++;
    }

    return -1;
  }
};