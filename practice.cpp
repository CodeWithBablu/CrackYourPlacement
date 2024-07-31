#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
  int val;
  Node *next;

  Node(int val)
  {
    this->val = val;
    this->next = nullptr;
  }

  Node(int val, Node *ref)
  {
    this->val = val;
    this->next = ref;
  }
};

class MyLinkedList
{
private:
  Node *head;
  Node *tail;
  int size;

public:
  MyLinkedList()
  {
    this->size = 0;
    this->head = nullptr;
    this->tail = nullptr;
  }

  int get(int index)
  {
    if (index < 0 || index >= size)
      return -1;

    Node *curr = head;
    int idx = 0;
    while (curr)
    {
      if (idx == index)
      {
        return curr->val;
      }
      idx++;
      curr = curr->next;
    }
    return -1;
  }

  void addAtHead(int val)
  {
    Node *curr = new Node(val, head);
    head = curr;
    if (size == 0)
    {
      tail = head;
    }
    size++;
  }

  void addAtTail(int val)
  {
    Node *curr = new Node(val);
    if (size == 0)
    {
      head = tail = curr;
    }
    else
    {
      tail->next = curr;
      tail = curr;
    }
    size++;
  }

  void addAtIndex(int index, int val)
  {
    if (index < 0 || index > size)
      return;
    if (index == 0)
    {
      addAtHead(val);
    }
    else if (index == size)
    {
      addAtTail(val);
    }
    else
    {
      Node *curr = head;
      for (int i = 0; i < index - 1; ++i)
      {
        curr = curr->next;
      }
      Node *newNode = new Node(val, curr->next);
      curr->next = newNode;
      size++;
    }
  }

  void deleteAtIndex(int index)
  {
    if (index < 0 || index >= size)
      return;

    Node *curr = head;

    if (index == 0)
    {
      head = head->next;
      if (head == nullptr)
        tail = nullptr;
      delete curr;
    }
    else
    {
      Node *prev = nullptr;
      for (int i = 0; i < index; ++i)
      {
        prev = curr;
        curr = curr->next;
      }
      prev->next = curr->next;
      if (prev->next == nullptr)
        tail = prev;
      delete curr;
      size--;
    }
  }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */