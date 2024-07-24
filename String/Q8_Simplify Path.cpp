#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  string simplifyPath(string path)
  {
    stack<string> pathStack;

    path += '/';
    string curr = "", res = "";
    for (char ch : path)
    {
      if (ch == '/')
      {
        if (curr == "..")
        {
          if (!pathStack.empty())
            pathStack.pop();
        }
        else if (curr != "" && curr != ".")
        {
          pathStack.push(curr);
        }
        curr = "";
      }
      else
        curr += ch;
    }

    while (!pathStack.empty())
    {
      res = "/" + pathStack.top() + res;
      pathStack.pop();
    }

    return res[0] == '/' ? res : "/" + res;
  }
};