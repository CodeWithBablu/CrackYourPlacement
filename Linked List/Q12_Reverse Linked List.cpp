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
  ListNode *reverseList(ListNode *head)
  {
    ListNode *prev = nullptr;
    ListNode *curr = head;
    ListNode *next = nullptr;

    // while the current pointer is not NULL
    while (curr != nullptr)
    {
      // set the next pointer to the next node in the list
      next = curr->next;
      // reverse the current node's pointer to point to the previous node
      curr->next = prev;
      // set the previous pointer to the current node
      prev = curr;
      // move the current pointer to the next node
      curr = next;
    }

    // set the head pointer to the last node, which is the
    // new first node after reversal
    return prev;
  }
};