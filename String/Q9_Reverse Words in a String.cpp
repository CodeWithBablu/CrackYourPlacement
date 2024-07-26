#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  string reverseWords(string s)
  {
    stringstream str(s);
    string word = "", res = "";
    while (str >> word)
    {
      res = " " + word + res;
    }

    return res.substr(1);
  }
};

class Solution
{
public:
  string reverseWords(string s)
  {
    string word = "", res = "";
    int i = 0;
    int size = s.size();
    while (i < size)
    {
      if (s[i] == ' ')
      {
        if (word != "")
        {
          res = " " + word + res;
        }
        word = "";
      }
      else
      {
        word += s[i];
      }
      i++;
    }
    return word != "" ? word + res : res.substr(1);
  }
};
