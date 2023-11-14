#include "stack.h"

#include <stdlib.h>
void push(struct node** stk, char ch, int priority) {
    struct node* node = init(ch, priority);
    node->next = *stk;
    *stk = node;
}

void pop(struct node** stk) {
    struct node* tmp = *stk;
    if (tmp != NULL) {
        *stk = tmp->next;
        free(tmp);
    }
}

struct node* init(char ch, int priority) {
    struct node* node = (struct node*)malloc(sizeof(struct node));
    if (NULL != node) {
        node->priority = priority;
        node->ch = ch;
        node->next = NULL;
    }
    return node;
}
