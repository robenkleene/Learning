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
    if (current == SENTINEL) {
        return -1;
    }
    for (int i = 0; i < index; i++) {
        current = current->next;
        if (!current) {
            return -1;
        }
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

    if (index == 0) {
        myLinkedListAddAtHead(obj, val);
        return;
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
        return;
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
    if (current == SENTINEL) {
        return;
    }
    while (current) {
        MyLinkedList *head = current;
        current = current->next;
        free(head);
    }
}

