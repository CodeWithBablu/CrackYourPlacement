#include <bits/stdc++.h>
using namespace std;

struct Node
{
  int data;
  struct Node *next;

  Node(int x)
  {
    data = x;
    next = NULL;
  }
};

class Solution
{
public:
  void rearrangeEvenOdd(Node *head)
  {
    Node *even = head->next;
    Node *odd = head;
    Node *evenhead = even;
    while (even && even->next)
    {
      odd->next = odd->next->next;
      even->next = even->next->next;

      odd = odd->next;
      even = even->next;
    }
    odd->next = evenhead;
  }
};