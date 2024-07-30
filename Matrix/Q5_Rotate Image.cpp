#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  void rotate(vector<vector<int>> &matrix)
  {

    int n = matrix.size() - 1;
    int outer = n, inner = 0;
    while (n >= 1)
    {
      for (int i = outer; i > inner; i--)
      {
        int first = 0, second = 0;
        second = matrix[inner][n - i + inner]; // first store 5(0,0)
        matrix[inner][n - i + inner] = matrix[i][inner];

        first = second; // store 5(0,0)

        second = matrix[n - i + inner][outer]; // second store 11(0,3)
        matrix[n - i + inner][outer] = first;

        first = second; // first become 11

        second = matrix[outer][i]; // store 16(3.3)
        matrix[outer][i] = first;

        first = second; // store 16

        second = matrix[i][inner]; // store 15(3,0)
        matrix[i][inner] = first;
      }
      outer--;
      inner++;
      n--;
    }
  }
};