#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  bool isValid(string s)
  {
    if (s.size() == 1)
      return false;

    unordered_map<char, char> bracket_pairs = {
        {')', '('},
        {'}', '{'},
        {']', '['},
    };

    stack<char> parentheses;
    parentheses.push(s[0]);
    char ch;
    for (int i = 1; i < s.size(); i++)
    {
      ch = s[i];
      if (ch == '(' || ch == '{' || ch == '[')
      {
        parentheses.push(ch);
        continue;
      }

      if (!parentheses.empty() && (bracket_pairs[ch] == parentheses.top()))
      {
        parentheses.pop();
      }
      else
        return false;
    }

    return parentheses.empty() ? true : false;
  }
};