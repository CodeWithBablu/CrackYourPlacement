#include <bits/stdc++.h>
using namespace std;

static const auto speedup = []()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  return 0;
}();

class Solution
{
public:
  bool isNumber(string s)
  {
    // if s starts with alpha
    if (isalpha(s[0]))
    {
      return false;
    }
    // if s doesn't end with decimal or num
    if ((s[s.length() - 1] != '.') && !isdigit(s[s.length() - 1]))
    {
      return false;
    }
    bool dec = false; // decimal flag, have we seen a decimal yet
    bool e = false;   // e flag, have we seen an e yet
    for (int i = 0; i < s.length(); i++)
    {
      char curr = s[i]; // current char in s
      // sign
      if ((curr == '+') || (curr == '-'))
      {
        // if not first char in string and previous char not e
        if ((i > 0) && (s[i - 1] != 'e') && (s[i - 1] != 'E'))
        {
          return false;
        }
      }
      // decimal
      else if (curr == '.')
      {
        // if after e or already have decimal
        if (e || dec)
        {
          return false;
        }
        // if no num before or after
        if (!(((i > 0) && isdigit(s[i - 1])) || ((i < (s.length() - 1)) && isdigit(s[i + 1]))))
        {
          return false;
        }
        dec = true;
      }
      // e
      else if ((curr == 'e') || (curr == 'E'))
      {
        // if 2nd e
        if (e)
        {
          return false;
        }
        // if e after sign
        if ((s[i - 1] == '+') || (s[i - 1] == '-'))
        {
          return false;
        }
        e = true;
      }
      // alpha
      else if (isalpha(curr))
      {
        return false;
      }
    }
    // no issues, valid num
    return true;
  }
};