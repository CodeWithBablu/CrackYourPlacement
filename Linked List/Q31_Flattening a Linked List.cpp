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
  // Function which returns the  root of the flattened linked list.
  Node *flatten(Node *root)
  {

    Node *temp = root;
    vector<int> arr;

    while (temp)
    {

      arr.push_back(temp->data);
      Node *child = temp->bottom;
      while (child)
      {
        arr.push_back(child->data);
        child = child->bottom;
      }
      temp = temp->next;
    }

    sort(arr.begin(), arr.end());

    Node *dummy = new Node(-1);
    dummy->bottom = new Node(arr[0]);
    temp = dummy->bottom;
    for (int i = 1; i < arr.size(); i++)
    {
      temp->bottom = new Node(arr[i]);
      temp = temp->bottom;
    }

    return dummy->bottom;
  }
};
