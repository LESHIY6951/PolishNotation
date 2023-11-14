#ifndef STRUCTPL_H
#define STRUCTPL_H

struct pole {
    char* str;
    double num;
    struct pole* next;
};
struct pole* pushPL(struct pole** stk, char* str);
void popPL(struct pole** stk);
struct pole* initPL(char* str);
void destroyPL(struct pole* root);
#endif