#include <iostream>

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
  ListNode* reverseList(ListNode* l) {
    return nullptr;
  }

  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode *c1 = l1;
    ListNode *c2 = l2;
    ListNode *result = new ListNode();
    ListNode *c = result;
    while (c1 != nullptr && c2 != nullptr) {
      int v1 = 0;
      int v2 = 0;

      if (c1 != nullptr) {
        v1 = c1->val;
        c1 = c1->next;
        if (c1 != nullptr && c->next == nullptr) {
          c->next = new ListNode();
        }
      }

      if (c2 != nullptr) {
        v2 = c2->val;
        c2 = c2->next;
        if (c2 != nullptr && c->next == nullptr) {
          c->next = new ListNode();
        }
      }

      c->val = v1 + v2;

      if (c->next != nullptr) {
        c = c->next;
      }
    }
    return result;
  }
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
  std::cout << "l1: ";
  printList(l1);
  std::cout << "l2: ";
  printList(l2);
  Solution *solution = new Solution();
  ListNode* result = solution->addTwoNumbers(l1, l2);
  std::cout << "re: ";
  printList(result);
  std::cout << "\n";
}

int main() {
  testCase({2, 4, 3}, {5,6,4});
  testCase({0}, {0});
  testCase({9, 9, 9, 9, 9, 9, 9}, {9, 9, 9, 9});
}
