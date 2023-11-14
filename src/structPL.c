#include "structPL.h"

#include <stdlib.h>
struct pole* pushPL(struct pole** stk, char* str) {
    struct pole* node = initPL(str);
    node->next = *stk;
    *stk = node;
    return node;
}

void popPL(struct pole** stk) {
    struct pole* tmp = *stk;
    *stk = tmp->next;
    free(tmp);
}

struct pole* initPL(char* str) {
    struct pole* node = (struct pole*)malloc(sizeof(struct pole));
    if (NULL != node) {
        node->num = atof(str);
        node->str = str;
        node->next = NULL;
    }
    return node;
}

void destroyPL(struct pole* root) {
    if (NULL != root) {
        struct pole* current = root;
        struct pole* next = root->next;
        while (current != NULL) {
            free(current);
            current = next;
            if (NULL != current) next = current->next;
        }
    }
}