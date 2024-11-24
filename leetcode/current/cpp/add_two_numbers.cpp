/*
   Input: l1 = [2,4,3], l2 = [5,6,4]
   Output: [7,0,8]
   Explanation: 342 + 465 = 807.
*/
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode *c1 = l1;
    ListNode *c2 = l2;
    ListNode *result = new ListNode();
    ListNode *c = result;
    while (c1 != nullptr) {
      int v1 = l1->val;
      while (c2 != nullptr) {
        int v2 = l2->val;
        c2 = l2->next;
        c->val = v1 + v2;
        c->next = new ListNode();
        c = c->next;
      }
      c1 = l1->next;
    }
    return result;
  }
};
