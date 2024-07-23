#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<int> spiralOrder(vector<vector<int>> &matrix)
  {
    int top = 0, bottom = matrix.size();
    int left = 0, right = matrix[0].size();

    vector<int> res;

    while (left < right && top < bottom)
    {
      // get every i in the top row
      for (int i = left; i < right; i++)
      {
        res.push_back(matrix[top][i]);
      }
      top++;

      // get every i in the right col
      for (int i = top; i < bottom; i++)
      {
        res.push_back(matrix[i][right - 1]);
      }
      right--;

      if (!(left < right && top < bottom))
        break;

      // get every i in the bottom row
      for (int i = right - 1; i >= left; i--)
      {
        res.push_back(matrix[bottom - 1][i]);
      }
      bottom--;

      // get every i in the left col
      for (int i = bottom - 1; i >= top; i--)
      {
        res.push_back(matrix[i][left]);
      }
      left++;
    }

    return res;
  }
};