#include "graph_io.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "polish_math.h"
#include "stack.h"
#include "structPL.h"

char* getStr() {
    int initial_size = 20;
    char* str = (char*)malloc(initial_size * sizeof(char));
    if (str != NULL) {
        int i = 0;
        int status = 1;
        while (status == 1) {
            char c;
            int scanC = scanf("%c", &c);
            if (c == '\n') {
                status = 0;
            }
            if (scanC == 1 && status == 1) {
                str[i] = c;
                i++;
                if (i == initial_size - 1) {
                    initial_size++;
                    char* tmp = (char*)realloc(str, initial_size * sizeof(char));
                    if (tmp == NULL) {
                        status = 0;
                        free(str);
                        printf("Reallor coudn't increase memory allocation. Not student's fault");
                    } else {
                        str = tmp;
                    }
                }
            } else {
                status = 0;
                if (scanC == 0) {
                    printf("n/a");
                    free(str);
                    str = NULL;
                }
            }
        }
    }

    return str;
}

char* tranaslate(char* str) {
    int length = strlen(str);
    int length2 = length * 2;
    int r = 0;
    char* result = (char*)malloc(length2 * sizeof(char));
    struct node* root = (struct node*)malloc(sizeof(struct node));
    struct node* currentS = root;
    int status = 1;
    for (int i = 0; i < length && status == 1; i++) {
        switch (str[i]) {
            case '+': {
                while (currentS && currentS->priority >= 1) {
                    result[r++] = currentS->ch;
                    result[r++] = ' ';
                    pop(&currentS);
                }
                push(&currentS, str[i], 1);
                break;
            }
            case '-': {
                if (i != 0 &&
                    ((str[i - 1] >= '0' && str[i - 1] <= '9') || str[i - 1] == ')' || str[i - 1] == 'x')) {
                    while (currentS && currentS->priority >= 1) {
                        result[r++] = currentS->ch;
                        result[r++] = ' ';
                        pop(&currentS);
                    }
                    push(&currentS, str[i], 1);
                } else {
                    while (currentS && currentS->priority >= 2) {
                        result[r++] = currentS->ch;
                        result[r++] = ' ';
                        pop(&currentS);
                    }
                    push(&currentS, '~', 2);
                }
                break;
            }
            case '^': {
                while (currentS && currentS->priority >= 3) {
                    result[r++] = currentS->ch;
                    result[r++] = ' ';
                    pop(&currentS);
                }
                push(&currentS, str[i], 3);
                break;
            }
            case '*':
            case '/': {
                while (currentS && currentS->priority >= 2) {
                    result[r++] = currentS->ch;
                    result[r++] = ' ';
                    pop(&currentS);
                }
                push(&currentS, str[i], 2);
                break;
            }
            case '(': {
                push(&currentS, str[i], 0);
                break;
            }
            case ')': {
                while (currentS->ch != '(') {
                    result[r++] = currentS->ch;
                    result[r++] = ' ';
                    pop(&currentS);
                }
                pop(&currentS);
                break;
            }
            case 'l': {
                // ln
                if (str[i + 1] == 'n') {
                    while (currentS && currentS->priority >= 4) {
                        result[r++] = currentS->ch;
                        result[r++] = ' ';
                        pop(&currentS);
                    }
                    push(&currentS, str[i], 4);
                } else {
                    printf("n/a");
                    status = 0;
                    i++;
                }
                i++;
                break;
            }
            case 't': {
                // tan
                if (str[i + 1] == 'a' && str[i + 2] == 'n') {
                    while (currentS && currentS->priority >= 4) {
                        result[r++] = currentS->ch;
                        result[r++] = ' ';
                        pop(&currentS);
                    }
                    push(&currentS, str[i], 4);
                } else {
                    printf("n/a");
                    status = 0;
                    i++;
                }
                i += 2;
                break;
            }
            case 's': {
                // sin sqrt
                if (str[i + 1] == 'i' && str[i + 2] == 'n') {
                    while (currentS && currentS->priority >= 4) {
                        result[r++] = currentS->ch;
                        result[r++] = ' ';
                        pop(&currentS);
                    }
                    push(&currentS, str[i], 4);
                    i += 2;
                } else if (str[i + 1] == 'q' && str[i + 2] == 'r' && str[i + 3] == 't') {
                    while (currentS && currentS->priority >= 4) {
                        result[r++] = currentS->ch;
                        result[r++] = ' ';
                        pop(&currentS);
                    }
                    push(&currentS, 'q', 4);
                    i += 3;
                } else {
                    printf("n/a");
                    status = 0;
                }
                break;
            }
            case 'c': {
                // ctg cos
                if (str[i + 1] == 't' && str[i + 2] == 'g') {
                    while (currentS && currentS->priority >= 4) {
                        result[r++] = currentS->ch;
                        result[r++] = ' ';
                        pop(&currentS);
                    }
                    push(&currentS, 'c', 4);
                    i += 2;
                } else if (str[i + 1] == 'o' && str[i + 2] == 's') {
                    while (currentS && currentS->priority >= 4) {
                        result[r++] = currentS->ch;
                        result[r++] = ' ';
                        pop(&currentS);
                    }
                    push(&currentS, 'o', 4);
                    i += 2;
                } else {
                    printf("n/a");
                    status = 0;
                }
                break;
            }
            case 'x': {
                result[r++] = 'x';
                result[r++] = ' ';
                break;
            }
            case '.': {
                result[r++] = '.';
                break;
            }
        }
        if (str[i] >= '0' && str[i] <= '9') {
            result[r++] = str[i];

            if (str[i + 1] < '0' || str[i + 1] > '9') {
                result[r++] = ' ';
            }
        }
        if (i == length - 1) {
            while (currentS) {
                result[r++] = currentS->ch;
                result[r++] = ' ';
                pop(&currentS);
            }
            result[--r] = '\0';
        }
    }

    return result;
}