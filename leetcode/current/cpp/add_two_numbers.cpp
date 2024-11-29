#include <iostream>

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

void printList(ListNode* head) {
  ListNode* current = head;
  while (current != nullptr) {
    std::cout << current->val << " ";
    current = current->next;
  }
  std::cout << std::endl;
}

ListNode* arrayToLinkedList(const std::vector<int>& arr) {
  if (arr.empty()) {
    return nullptr;
  }

  ListNode* head = new ListNode(arr[0]);
  ListNode* current = head;

  for (size_t i = 1; i < arr.size(); ++i) {
    current->next = new ListNode(arr[i]);
    current = current->next;
  }

  return head;
}

void testCase(const std::vector<int>& a1, const std::vector<int>& a2) {
  ListNode* l1 = arrayToLinkedList(a1);
  ListNode* l2 = arrayToLinkedList(a2);
  printList(l1);
  printList(l2);
}

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

int main() {
  Solution *solution = new Solution();
}
