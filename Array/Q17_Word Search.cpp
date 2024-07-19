#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  bool exist(vector<vector<char>> &board, string word)
  {
    int rows = board.size(), cols = board[0].size();

    vector<vector<bool>> isVisited(rows, vector<bool>(cols, false));

    function<bool(int, int, int)> dfs = [&](int r, int c, int k)
    {
      if (k == word.size())
        return true;

      if (r < 0 || c < 0 || r >= rows || c >= cols || word[k] != board[r][c] || isVisited[r][c])
        return false;

      isVisited[r][c] = true;

      bool res = (dfs(r + 1, c, k + 1) || dfs(r - 1, c, k + 1) ||
                  dfs(r, c + 1, k + 1) || dfs(r, c - 1, k + 1));

      isVisited[r][c] = false;
      return res;
    };

    for (int i = 0; i < rows; i++)
    {
      for (int j = 0; j < cols; j++)
      {
        if (word[0] == board[i][j] && dfs(i, j, 0))
          return true;
      }
    }

    return false;
  }
};
