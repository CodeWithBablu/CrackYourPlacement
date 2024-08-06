#include <bits/stdc++.h>
using namespace std;

struct Node
{
  int data;
  struct Node *next;
  struct Node *bottom;

  Node(int x)
  {
    data = x;
    next = NULL;
    bottom = NULL;
  }
};

class Solution
{
public:
  Node *subtract(Node *h1, Node *h2, bool borrow)
  {
    if (!h1)
      return h1;
    if (borrow)
    {
      h1->data--;
    }
    borrow = false;
    if (h2)
    {
      if (h1->data < h2->data)
      {
        h1->data += 10;
        borrow = true;
      }
      h1->data -= h2->data;
      h2 = h2->next;
    }
    if (h1->data < 0)
    {
      h1->data += 10;
      borrow = true;
    }
    Node *ans = subtract(h1->next, h2, borrow);
    if (!ans)
      ans = h1;
    else
    {
      h1->next->next = h1;
    }
    return ans;
  }
  Node *revLinkedList(Node *root)
  {
    if (!root->next)
      return root;
    Node *ans = revLinkedList(root->next);
    root->next->next = root;
    return ans;
  }
  void compare(Node *h1, Node *h2, int &valCompare, int &lenCompare)
  {
    if (h1 == NULL && h2 == NULL)
      return;
    if (h1 == NULL || h2 == NULL)
    {
      if (!h1)
        lenCompare = -1;
      else
        lenCompare = (1);
      return;
    }
    if (valCompare == 0)
    {
      if (h1->data > h2->data)
        valCompare = 1;
      else if (h1->data < h2->data)
        valCompare = -1;
    }
    compare(h1->next, h2->next, valCompare, lenCompare);
    return;
  }
  Node *subLinkedList(Node *head1, Node *head2)
  {
    // Your implementation of subLinkedList goes here
    // Make sure to return the head of the resulting linked list
    while (head1->next && head1->data == 0)
    {
      head1 = head1->next;
    }
    while (head2->next && head2->data == 0)
    {
      head2 = head2->next;
    }
    Node *minuend = head1;
    Node *subtrahend = head2;
    int valCompare = 0, lenCompare = 0;
    compare(head1, head2, valCompare, lenCompare);
    if (lenCompare == -1 || (lenCompare == 0 && valCompare == -1))
    {
      minuend = head2;
      subtrahend = head1;
    }
    Node *temp;
    temp = revLinkedList(minuend);
    minuend->next = NULL;
    minuend = temp;
    temp = revLinkedList(subtrahend);
    subtrahend->next = NULL;
    subtrahend = temp;
    temp = subtract(minuend, subtrahend, false);
    minuend->next = NULL;
    minuend = temp;
    while (minuend->next && minuend->data == 0)
    {
      minuend = minuend->next;
    }

    return minuend;
  }
};