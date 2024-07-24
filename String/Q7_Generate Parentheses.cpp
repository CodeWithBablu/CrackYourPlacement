#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<string> generateParenthesis(int n)
  {
    stack<char> bracket;
    vector<string> res;

    function<void(string, char, int, int)> getParentheses = [&](string s, char ch, int openBracketCnt, int k)
    {
      s += ch;
      if (k == (2 * n))
      {
        cout << "pop";
        res.push_back(s);
        return;
      }

      if (!bracket.empty())
      {
        bracket.pop();
        getParentheses(s, ')', openBracketCnt, k + 1);
        bracket.push('(');
      }

      if (openBracketCnt < n)
      {
        bracket.push('(');
        getParentheses(s, '(', openBracketCnt + 1, k + 1);
        bracket.pop();
      }

      return;
    };

    bracket.push('(');
    getParentheses("", '(', 1, 1);
    return res;
  }
};