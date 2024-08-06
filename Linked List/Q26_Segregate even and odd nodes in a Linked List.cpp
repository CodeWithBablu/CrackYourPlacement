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
  Node *divide(Node *head)
  {
    Node *h = new Node(-1);
    Node *t = head;

    Node *ans = h;
    Node *temp = new Node(-1);
    temp->next = head;
    head = temp;
    Node *prev = head;

    while (t != nullptr)
    {
      if (t->data % 2 == 0)
      {
        h->next = t;
        h = t;
        t = t->next;

        h->next = nullptr;
        prev->next = t;
      }
      else
      {
        prev->next = t;
        prev = t;
        t = t->next;
      }
    }
    h->next = head->next;
    return ans->next;
  }
};