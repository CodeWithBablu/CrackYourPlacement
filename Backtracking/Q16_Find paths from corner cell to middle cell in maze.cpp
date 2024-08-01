#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  bool f(int i, int j, vector<vector<int>> &matrix, vector<vector<int>> &ans)
  {
    int jump = matrix[i][j];
    int n = matrix.size();
    if (i == n - 1 && j == n - 1)
    {
      return true;
    }
    for (int k = 1; k <= jump; k++)
    {
      if (k + j < n && (matrix[i][k + j] != 0 || k + j == n - 1))
      {
        ans[i][k + j] = 1;
        if (f(i, k + j, matrix, ans))
          return true;
        ans[i][k + j] = 0;
      }

      if (i + k < n && (matrix[i + k][j] != 0 || k + i == n - 1))
      {
        ans[i + k][j] = 1;
        if (f(i + k, j, matrix, ans))
          return true;
        ans[i + k][j] = 0;
      }
    }
    return false;
  }
  vector<vector<int>> ShortestDistance(vector<vector<int>> &matrix)
  {
    int n = matrix.size();
    vector<vector<int>> ans(n, vector<int>(n, 0));
    ans[0][0] = 1;
    if (f(0, 0, matrix, ans))
      return ans;
    return {{-1}};
  }
};