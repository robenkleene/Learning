#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int val;
    struct node *next;
} node_t;

void print_list(node_t *head) {
    node_t *current = head;

    while (current) {
        printf("%d\n", current->val);
        current = current->next;
    }
}

void append(node_t *head, int val) {
    node_t *current = head;
    while (current->next) {
        current = current->next;
    }

    current->next = (node_t *)malloc(sizeof(node_t));
    current->next->val = val;
    current->next->next = NULL;
}

void push(node_t **head, int val) {
    node_t *new_node;
    new_node = (node_t *)malloc(sizeof(node_t));

    new_node->val = val;
    new_node->next = *head;
    *head = new_node;
}

int pop(node_t **head) {
    int retval = -1;
    node_t *next_node = NULL;

    if (!*head) {
        return -1;
    }

    next_node = (*head)->next;
    retval = (*head)->val;
    free(*head);
    *head = next_node;

    return retval;
}

int remove_last(node_t *head) {
    int retval = 0;
    if (!head->next) {
        retval = head->val;
        free(head);
        return retval;
    }

    node_t *current = head;
    while (current->next->next) {
        current = current->next;
    }

    retval = current->next->val;
    free(current->next);
    current->next = NULL;
    return retval;
}

int remove_by_index(node_t **head, int n) {
    int i = 0;
    int retval = -1;
    node_t *current = *head;
    node_t *temp_node = NULL;

    if (n == 0) {
        return pop(head);
    }

    for (i = 0; i < n - 1; i++) {
        if (!current->next) {
            return -1;
        }
        current = current->next;
    }

    temp_node = current->next;
    retval = temp_node->val;
    current->next = temp_node->next;
    free(temp_node);

    return retval;
}

int remove_by_value(node_t **head, int n) {
    int i = 0;
    int retval = -1;
    node_t *current = *head;
    node_t *temp_node = NULL;

    if (n == current->val) {
        return pop(head);
    }

    while (current) {
        if (current->val == n) {
            break;
        }
        current = current->next;
    }

    if (!current) {
        return -1;
    }

    temp_node = current->next;
    retval = temp_node->val;
    current->next = temp_node->next;
    free(temp_node);

    return retval;
}

int main() {
    printf("Manually creating value 1\n");
    node_t *head = NULL;
    head = (node_t *)malloc(sizeof(node_t));
    if (!head) {
        return 1;
    }
    head->val = 1;
    print_list(head);
    printf("\n");

    printf("Manually adding value 2\n");
    head->next = (node_t *)malloc(sizeof(node_t));
    head->next->val = 2;
    head->next->next = NULL;
    print_list(head);
    printf("\n");

    printf("Appending value 3\n");
    append(head, 3);
    print_list(head);
    printf("\n");

    printf("Push a value 4 to the beginning\n");
    push(&head, 4);
    print_list(head);
    printf("\n");

    printf("Pop a value from the beginning\n");
    pop(&head);
    print_list(head);
    printf("\n");

    printf("Remove the last value\n");
    remove_last(head);
    print_list(head);
    printf("\n");

    printf("Remove at index 1\n");
    remove_by_index(&head, 1);
    print_list(head);
    printf("\n");

    printf("Remove by value 1\n");
    remove_by_value(&head, 1);
    print_list(head);
    printf("\n");
}
