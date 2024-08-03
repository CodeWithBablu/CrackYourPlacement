#include <bits/stdc++.h>
using namespace std;

struct Node
{
  int data;
  Node *next;

  Node(int x)
  {
    data = x;
    next = NULL;
  }
};

class Solution
{
public:
  Node *compute(Node *head)
  {
    // your code goes here
    head = rev(head);
    int max = head->data;
    Node *curr = head->next;
    Node *prev = head;

    while (curr != NULL)
    {
      if (curr->data >= max)
      {
        prev = curr;      // deleting prev
        max = curr->data; // storing max val of curr in max then return maxval
      }
      else
      {
        prev->next = curr->next; // when curr data is < max make two jumps
      }
      curr = curr->next;
    }
    return rev(head);
  }
  Node *rev(Node *head)
  {
    Node *curr = head;
    Node *prev = nullptr;
    Node *temp = nullptr;

    while (curr != NULL)
    {
      temp = curr->next;
      curr->next = prev;
      prev = curr;
      curr = temp;
    }
    return prev;
  }
};