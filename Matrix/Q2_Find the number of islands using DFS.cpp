// C++ Program to count islands in boolean 2D matrix
#include <bits/stdc++.h>
using namespace std;

class Solution
{
  int ROW, COL;

public:
  int isSafe(vector<vector<char>> &grid, int row, int col,
             vector<vector<bool>> visited)
  {
    // row number is in range, column
    // number is in range and value is 1
    // and not yet visited
    return (row >= 0) && (row < ROW) && (col >= 0) && (col < COL) && (grid[row][col] && !visited[row][col]);
  }

  // A utility function to do DFS for a
  // 2D boolean matrix. It only considers
  // the 8 neighbours as adjacent vertices
  void DFS(vector<vector<char>> &grid, int row, int col,
           vector<vector<bool>> visited)
  {
    // These arrays are used to get
    // row and column numbers of 8
    // neighbours of a given cell
    static int rowNbr[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    static int colNbr[] = {-1, 0, 1, -1, 1, -1, 0, 1};

    // Mark this cell as visited
    visited[row][col] = true;

    // Recur for all connected neighbours
    for (int k = 0; k < 8; ++k)
      if (isSafe(grid, row + rowNbr[k], col + colNbr[k],
                 visited))
        DFS(grid, row + rowNbr[k], col + colNbr[k],
            visited);
  }

  // The main function that returns
  // count of islands in a given boolean
  // 2D matrix
  int numIslands(vector<vector<char>> &grid)
  {
    // Make a bool array to mark visited cells.
    // Initially all cells are unvisited

    ROW = grid.size();
    COL = grid[0].size();
    vector<vector<bool>> visited(ROW, vector<bool>(COL, false));

    // Initialize count as 0 and
    // traverse through the all cells of
    // given matrix
    int count = 0;
    for (int i = 0; i < ROW; ++i)
      for (int j = 0; j < COL; ++j)

        // If a cell with value 1 is not
        if (grid[i][j] && !visited[i][j])
        {
          // visited yet, then new island found
          // Visit all cells in this island.
          DFS(grid, i, j, visited);

          // and increment island count
          ++count;
        }

    return count;
  }
};