#include <bits/stdc++.h>
using namespace std;

/// @brief using unordered set
class Solution
{
public:
  void setZeroes(vector<vector<int>> &matrix)
  {
    unordered_set<int> rows, cols;

    for (int i = 0; i < matrix.size(); i++)
    {
      for (int j = 0; j < matrix[0].size(); j++)
      {
        if (matrix[i][j] == 0)
        {
          rows.insert(i);
          cols.insert(j);
        }
      }
    }

    for (int i = 0; i < matrix.size(); i++)
    {
      for (int j = 0; j < matrix[0].size(); j++)
      {
        if (rows.find(i) != rows.end() || cols.find(j) != cols.end())
        {
          matrix[i][j] = 0;
        }
      }
    }
  }
};

/// @brief Without using extra space
class Solution
{
public:
  void traverseMatrix(vector<vector<int>> &matrix)
  {
    int rows = matrix.size(), cols = matrix[0].size();

    cout << endl;
    for (int i = 0; i < rows; i++)
    {
      for (int j = 0; j < cols; j++)
      {
        cout << matrix[i][j] << " ";
      }
      cout << endl;
    }
    cout << endl;
  }

  void setZeroes(vector<vector<int>> &matrix)
  {

    int rows = matrix.size(), cols = matrix[0].size();

    bool col0 = false;
    bool row0 = false;

    for (int i = 0; i < rows; i++)
    {
      if (matrix[i][0] == 0)
        col0 = true;

      for (int j = 1; j < cols; j++)
      {
        if (matrix[0][j] == 0 && i == 0)
          row0 = true;

        if (matrix[i][j] == 0)
        {
          matrix[i][0] = 0;
          matrix[0][j] = 0;
        }
      }
    }

    for (int j = 1; j < cols; j++)
    {
      if (matrix[0][j] == 0)
      {
        for (int k = 1; k < rows; k++)
        {
          matrix[k][j] = 0;
        }
      }
    }

    for (int i = 0; i < rows; i++)
    {
      if (matrix[i][0] == 0)
      {
        for (int k = 1; k < cols; k++)
        {
          matrix[i][k] = 0;
        }
      }
    }

    if (col0)
    {
      for (int k = 0; k < rows; k++)
      {
        matrix[k][0] = 0;
      }
    }

    if (row0)
    {
      for (int k = 0; k < cols; k++)
      {
        matrix[0][k] = 0;
      }
    }
  }
};