#include <assert.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct MyLinkedList {
    int val;
    struct MyLinkedList *next;
} MyLinkedList;

static MyLinkedList SENTINEL_STATIC;
MyLinkedList *const SENTINEL = &SENTINEL_STATIC;

/** Initialize your data structure here. */
MyLinkedList *myLinkedListCreate() {
    SENTINEL->next = NULL;
    return SENTINEL;
}

/** Get the value of the index-th node in the linked list. If the index is
 * invalid, return -1. */
int myLinkedListGet(MyLinkedList *obj, int index) {
    assert(obj == SENTINEL);
    MyLinkedList *current = obj;
    while (current == SENTINEL && current->next) {
        current = current->next;
    }
    for (int i = 0; i < index; i++) {
        if (!current) {
            return -1;
        }
        current = current->next;
    }
    return current->val;
}

/** Add a node of value val before the first element of the linked list. After
 * the insertion, the new node will be the first node of the linked list. */
void myLinkedListAddAtHead(MyLinkedList *obj, int val) {
    assert(obj == SENTINEL);
    MyLinkedList *current = obj;
    while (current == SENTINEL && current->next) {
        current = current->next;
    }
    MyLinkedList *new = (MyLinkedList *)malloc(sizeof(MyLinkedList));
    new->val = val;
    new->next = current == SENTINEL ? NULL : current;
    SENTINEL->next = new;
}

/** Append a node of value val to the last element of the linked list. */
void myLinkedListAddAtTail(MyLinkedList *obj, int val) {
    assert(obj == SENTINEL);
    MyLinkedList *current = obj;
    while (current->next) {
        current = current->next;
    }
    MyLinkedList *new = (MyLinkedList *)malloc(sizeof(MyLinkedList));
    new->val = val;
    new->next = NULL;
    current->next = new;
}

/** Add a node of value val before the index-th node in the linked list. If
 * index equals to the length of linked list, the node will be appended to the
 * end of linked list. If index is greater than the length, the node will not
 * be inserted. */
void myLinkedListAddAtIndex(MyLinkedList *obj, int index, int val) {
    assert(obj == SENTINEL);
    MyLinkedList *current = obj;
    while (current == SENTINEL && current->next) {
        current = current->next;
    }
    for (int i = 0; i < index - 1; i++) {
        if (!current->next) {
            return;
        }
        current = current->next;
    }

    MyLinkedList *new = (MyLinkedList *)malloc(sizeof(MyLinkedList));
    new->val = val;
    new->next = current->next;
    current->next = new;
}

/** Delete the index-th node in the linked list, if the index is valid. */
void myLinkedListDeleteAtIndex(MyLinkedList *obj, int index) {
    assert(obj == SENTINEL);

    if (index == 0) {
        MyLinkedList *delete = SENTINEL->next;
        if (!delete) {
            return;
        }
        SENTINEL->next = delete->next;
        free(delete);
    }

    MyLinkedList *current = obj;
    while (current == SENTINEL && current->next) {
        current = current->next;
    }
    for (int i = 0; i < index - 1; i++) {
        if (!current->next) {
            return;
        }
        current = current->next;
    }
    if (current->next) {
        MyLinkedList *delete = current->next;
        current->next = delete->next;
        free(delete);
    }
}

void myLinkedListFree(MyLinkedList *obj) {
    assert(obj == SENTINEL);
    MyLinkedList *current = obj;
    while (current == SENTINEL && current->next) {
        current = current->next;
    }
    while (current) {
        MyLinkedList *head = current;
        current = current->next;
        free(head);
    }
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

// Helper

void printList(MyLinkedList *obj) {
    assert(obj == SENTINEL);
    MyLinkedList *current = obj;
    while (current == SENTINEL && current->next) {
        current = current->next;
    }
    if (current == SENTINEL) {
        printf("\n");
        return;
    }
    while (current) {
        printf("%d ", current->val);
        current = current->next;
    }
    printf("\n");
}

int main() {
    // Basic
    printf("myLinkedListCreate()\n");
    MyLinkedList *list = myLinkedListCreate();
    printList(list);
    printf("myLinkedListAddAtHead(list, 1)\n");
    myLinkedListAddAtHead(list, 1);
    printList(list);
    printf("myLinkedListAddAtTail(list, 2);\n");
    myLinkedListAddAtTail(list, 2);
    printList(list);
    printf("myLinkedListAddAtIndex(list, 1, 3);\n");
    myLinkedListAddAtIndex(list, 1, 3);
    printList(list);
    printf("myLinkedListAddAtIndex(list, 0, 4);\n");
    myLinkedListAddAtIndex(list, 0, 4);
    printList(list);
    myLinkedListFree(list);

    // Test 1
    printf("\n\nmyLinkedListCreate()\n");
    list = myLinkedListCreate();
    printList(list);
    printf("myLinkedListAddAtHead(list, 1)\n");
    myLinkedListAddAtHead(list, 1);
    printList(list);
    printf("myLinkedListAddAtTail(list, 3);\n");
    myLinkedListAddAtTail(list, 3);
    printList(list);
    printf("myLinkedListAddAtIndex(list, 1, 2);\n");
    myLinkedListAddAtIndex(list, 1, 2);
    printList(list);
    printf("myLinkedListGet(list, 1);\n");
    int result = myLinkedListGet(list, 1);
    printf("result = %i\n", result);
    printf("myLinkedListDeleteAtIndex(list, 1);\n");
    myLinkedListDeleteAtIndex(list, 1);
    printList(list);
    printf("myLinkedListGet(list, 1);\n");
    result = myLinkedListGet(list, 1);
    printf("result = %i\n", result);
    myLinkedListFree(list);

    // Test 2
    printf("\n\nmyLinkedListCreate()\n");
    list = myLinkedListCreate();
    printList(list);
    printf("myLinkedListAddAtHead(list, 7)\n");
    myLinkedListAddAtHead(list, 7);
    printList(list);
    printf("myLinkedListAddAtHead(list, 2)\n");
    myLinkedListAddAtHead(list, 2);
    printList(list);
    printf("myLinkedListAddAtHead(list, 1)\n");
    myLinkedListAddAtHead(list, 1);
    printList(list);
    printf("myLinkedListAddAtIndex(list, 3, 0);\n");
    myLinkedListAddAtIndex(list, 3, 0);
    printList(list);
    printf("myLinkedListDeleteAtIndex(list, 2);\n");
    myLinkedListDeleteAtIndex(list, 2);
    printList(list);
    printf("myLinkedListAddAtHead(list, 6)\n");
    myLinkedListAddAtHead(list, 6);
    printList(list);
    printf("myLinkedListAddAtTail(list, 4);\n");
    myLinkedListAddAtTail(list, 4);
    printList(list);
    printf("myLinkedListGet(list, 4);\n");
    result = myLinkedListGet(list, 4);
    printf("result = %i\n", result);
    printf("myLinkedListAddAtHead(list, 4)\n");
    myLinkedListAddAtHead(list, 4);
    printList(list);
    printf("myLinkedListAddAtIndex(list, 5, 0);\n");
    myLinkedListAddAtIndex(list, 5, 0);
    printList(list);
    printf("myLinkedListAddAtHead(list, 6)\n");
    myLinkedListAddAtHead(list, 6);
    printList(list);

    // Test 3
    printf("\n\nmyLinkedListCreate()\n");
    list = myLinkedListCreate();
    printList(list);
    printf("myLinkedListAddAtHead(list, 1)\n");
    myLinkedListAddAtHead(list, 1);
    printList(list);
    printf("myLinkedListAddAtTail(list, 3);\n");
    myLinkedListAddAtTail(list, 3);
    printList(list);
    printf("myLinkedListAddAtIndex(list, 1, 2);\n");
    myLinkedListAddAtIndex(list, 1, 2);
    printList(list);
    printf("myLinkedListGet(list, 1);\n");
    result = myLinkedListGet(list, 1);
    printf("result = %i\n", result);
    printf("myLinkedListDeleteAtIndex(list, 0);\n");
    myLinkedListDeleteAtIndex(list, 0);
    printList(list);
    printf("myLinkedListGet(list, 0);\n");
    result = myLinkedListGet(list, 0);
    printf("result = %i\n", result);
}
