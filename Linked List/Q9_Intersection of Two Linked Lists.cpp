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
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
  {

    ListNode *currA = headA, *currB = headB;

    unordered_set<ListNode *> store;

    while (currA != nullptr)
    {
      store.insert(currA);
      currA = currA->next;
    }

    while (currB != nullptr)
    {
      if (store.find(currB) != store.end())
        return currB;
      currB = currB->next;
    }

    return 0;
  }
};