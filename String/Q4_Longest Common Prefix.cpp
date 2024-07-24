#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  string longestCommonPrefix(vector<string> &strs)
  {
    sort(strs.begin(), strs.end());
    int n = strs.size();
    string ans = "";
    string firstWord = strs[0], lastWord = strs[n - 1];

    for (int i = 0; i < min(firstWord.size(), lastWord.size()); i++)
    {
      if (strs[0][i] == strs[n - 1][i])
      {
        ans += strs[0][i];
        continue;
      }
      break;
    }
    return ans;
  }
};