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
  ListNode *removeNthFromEnd(ListNode *head, int n)
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

    int pos = cnt - n + 1; // position of element to be delete

    /*


   [ 1  ,  2  ,  3  ,  4  ,  5  ]
                 !     !     !
                curr  pos  future

    */

    if (cnt - n == 0) // for corner case if node to be deleted is first node
      head = head->next;

    else if (n == 1) // for corner case if node to be deleted is last node
    {
      curr = pointers[pos - 1]; // access the pointers store earlier
      curr->next = nullptr;
    }
    else
    {
      curr = pointers[pos - 1];
      future = pointers[pos + 1];
      curr->next = future;
    }

    return head;
  }
};