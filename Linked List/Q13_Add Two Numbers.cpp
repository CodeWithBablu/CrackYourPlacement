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

#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
  {
    ListNode *l1_curr = l1, *l2_curr = l2;
    ListNode *curr, *start, *prev = nullptr;
    int sum = 0, val = 0;
    sum = ((l1_curr->val + l2_curr->val) / 10 == 1) ? 1 : 0;
    val = ((l1_curr->val + l2_curr->val));
    val = val >= 10 ? val % 10 : val;
    curr = new ListNode(val, nullptr);
    start = curr;
    prev = curr;
    l1_curr = l1_curr->next;
    l2_curr = l2_curr->next;

    while (l1_curr != nullptr && l2_curr != nullptr)
    {
      val = ((l1_curr->val + l2_curr->val) + sum);
      val = val >= 10 ? val % 10 : val;
      curr = new ListNode(val, nullptr);
      prev->next = curr;
      prev = curr;
      sum = (((l1_curr->val + l2_curr->val) + sum) / 10 == 1) ? 1 : 0;
      l1_curr = l1_curr->next;
      l2_curr = l2_curr->next;
    }

    l1_curr = l1_curr != nullptr ? l1_curr : l2_curr;

    while (l1_curr != nullptr)
    {
      val = ((l1_curr->val) + sum);
      val = val >= 10 ? val % 10 : val;
      curr = new ListNode(val, nullptr);
      prev->next = curr;
      prev = curr;
      sum = (((l1_curr->val) + sum) / 10 == 1) ? 1 : 0;
      l1_curr = l1_curr->next;
    }

    if (sum == 1)
    {
      curr = new ListNode(1, nullptr);
      prev->next = curr;
      prev = curr;
    }

    return start;
  }
};