#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

typedef struct MyLinkedList {
    int val;
    struct MyLinkedList *next;
} MyLinkedList;

void printList(MyLinkedList *obj) {
    MyLinkedList *current = obj;
    while (current != NULL) {
        printf("%d ", current->val);
        current = current->next;
    }
    printf("\n");
}

/** Initialize your data structure here. */
MyLinkedList* myLinkedListCreate() {
    MyLinkedList *node = (MyLinkedList *)malloc(sizeof(MyLinkedList));
    node->val = 0;
    node->next = NULL;
    return node;
}

/** Get the value of the index-th node in the linked list. If the index is
 * invalid, return -1. */
int myLinkedListGet(MyLinkedList* obj, int index) {
    int i = 0;
    MyLinkedList *current = obj;
    for (int i; i < index; i++) {
        if (current == NULL) {
            return -1;
        }
        current = current->next;
    }
    return current->val;
}

/** Add a node of value val before the first element of the linked list. After
 * the insertion, the new node will be the first node of the linked list. */
void myLinkedListAddAtHead(MyLinkedList** obj, int val) {
    MyLinkedList *node = (MyLinkedList *)malloc(sizeof(MyLinkedList));
    node->val = val;
    node->next = *obj;
    *obj = node;
}

/** Append a node of value val to the last element of the linked list. */
void myLinkedListAddAtTail(MyLinkedList* obj, int val) {
    MyLinkedList *current = obj;
    // TODO: What happens if obj is `NULL`?
    // TODO: Continue here

    while (current->next != NULL) {
        current = current->next;
    }
}

/** Add a node of value val before the index-th node in the linked list. If
 * index equals to the length of linked list, the node will be appended to the
 * end of linked list. If index is greater than the length, the node will not
 * be inserted. */
void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val) {
  
}

/** Delete the index-th node in the linked list, if the index is valid. */
void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index) {
  
}

void myLinkedListFree(MyLinkedList* obj) {
    
}

int main() {
    printf("myLinkedListCreate()\n");
    MyLinkedList *list = myLinkedListCreate();
    printList(list);
    printf("myLinkedListAddAtHead(&list, 5)\n");
    myLinkedListAddAtHead(&list, 5);
    printList(list);
}

/**
 * Your MyLinkedList struct will be instantiated and called as such:
 * MyLinkedList* obj = myLinkedListCreate();
 * int param_1 = myLinkedListGet(obj, index);
 
 * myLinkedListAddAtHead(obj, val);
 
 * myLinkedListAddAtTail(obj, val);
 
 * myLinkedListAddAtIndex(obj, index, val);
 
 * myLinkedListDeleteAtIndex(obj, index);
 
 * myLinkedListFree(obj);
*/
