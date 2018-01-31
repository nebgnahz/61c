#include <stdlib.h>

// #define NULL 0

typedef struct node {
    struct node* next;
    int val;
} node;

void prepend_ll(node** lst, int val) {
    node* item = (node*) malloc(1 * sizeof(node));
    item->val = val;
    item->next = *lst;
    *lst = item;
}

void free_ll(node** lst) {
    node* p = *lst;
    while (p != NULL) {
        node* temp = p;
        p = p->next;
        free(temp);
        temp = NULL;
    }
    lst = NULL;
}

void fancy_free(node** lst) {
    if (*lst != NULL) {
        node* next = (*lst)->next;
        free(&next);
        free(*lst);
    }
    lst = NULL;
}

int main() {
    node* head = NULL;
    prepend_ll(&head, 0);
    prepend_ll(&head, 1);
    prepend_ll(&head, 2);

    free_ll(&head);
    head = NULL;
    return 0;
}
