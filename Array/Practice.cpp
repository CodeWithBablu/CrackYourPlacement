#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int reverse(int x)
  {
    int rn = 0;
    cout << INT_MAX << " " << INT_MIN << endl;
    while (x != 0)
    {
      int rem = x % 10;
      cout << rem;
      if (rn > (INT_MAX - 1) || rn < INT_MIN)
        return 0;

      rn = (rn * 10) + rem;
      x /= 10;
    }

    return rn;
  }
};

int main()
{
  cout << endl
       << "########################" << endl;
  Solution *obj = new Solution();

  int rn = obj->reverse(-123);
  cout << rn;
  cout << endl
       << "########################" << endl;
  return 0;
}