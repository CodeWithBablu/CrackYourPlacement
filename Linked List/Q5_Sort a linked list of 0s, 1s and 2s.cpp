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
  // your task is to complete this function
  void sort(Node **head)
  {
    if ((*head)->next == NULL)
      return;
    Node *p = NULL;
    Node *a = *head;
    Node *b = (*head)->next;
    while (b && b->next)
    {
      a->next = b->next;
      b->next = p;
      a = a->next;
      p = b;
      b = a->next;
    }
    if (b)
    {
      b->next = p;
    }
    else
      a->next = p;
  }
};