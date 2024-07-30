#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<vector<string>> groupAnagrams(vector<string> &strs)
  {
    vector<vector<string>> ans;
    unordered_map<string, int> wpos;

    int k = 0; // ans Pointer

    for (int i = 0; i < strs.size(); i++)
    {
      string oStr = strs[i];
      sort(oStr.begin(), oStr.end());
      if (wpos.find(oStr) != wpos.end())
      {
        ans[wpos[oStr]].push_back(strs[i]);
      }
      else
      {
        wpos[oStr] = k++;
        ans.push_back({strs[i]});
      }
    }

    return ans;
  }
};