#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int val;
    struct node *next;
} node_t;

void print_list(node_t *head) {
    node_t *current = head;

    while (current != NULL) {
        printf("%d\n", current->val);
        current = current->next;
    }
}

void append(node_t *head, int val) {
    node_t *current = head;
    while (current->next != NULL) {
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

    if (*head == NULL) {
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
    if (head->next == NULL) {
        retval = head->val;
        free(head);
        return retval;
    }

    node_t *current = head;
    while (current->next->next != NULL) {
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
        if (current->next == NULL) {
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

int main() {
    // Manually creating a node
    node_t *head = NULL;
    head = (node_t *)malloc(sizeof(node_t));
    if (head == NULL) {
        return 1;
    }
    head->val = 1;
    printf("Manually creating a node\n");
    print_list(head);
    printf("\n");

    // Manually adding a ndoe
    head->next = (node_t *)malloc(sizeof(node_t));
    head->next->val = 2;
    head->next->next = NULL;
    printf("Manually adding a node\n");
    print_list(head);
    printf("\n");

    /* append(head, value) */
    /* push(head, value) */
    /* pop(head) */
    /* remove_last(head) */
    /* remove_by_index(head, index) */
}
