#ifndef STACK_H
#define STACK_H

struct node {
    char ch;
    int priority;
    struct node* next;
};

struct node* init(char ch, int priority);
void push(struct node** stk, char ch, int priority);
void pop(struct node** stk);
#endif