#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
  ListNode *middleNode(ListNode *head)
  {

    unordered_map<int, ListNode *> pointers; // To store pointer for each node

    ListNode *curr = head, *future;
    int cnt = 0;

    while (curr != nullptr) // Iterate over LL and store pointer to every node
    {
      pointers[cnt + 1] = curr; // will store pointer as [nodeno] -> pointer
      cout << curr->val << " ";
      cnt++;
      curr = curr->next;
    }

    return pointers[cnt / 2 + 1];
  }
};