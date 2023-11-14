#include "polish_math.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "structPL.h"

double calculate(char* stack, double x) {
    int len = strlen(stack);
    char tmp[len];
    strcpy(tmp, stack);
    double result = 0;
    char* ptr = strtok(tmp, " ");
    struct pole* root = initPL(ptr);
    struct pole* current = root;
    if ((strcmp(ptr, "x") == 0 || strcmp(ptr, "X") == 0)) {
        current->num = x;
    }
    int status = 1;
    while (ptr != NULL && status == 1) {
        ptr = strtok(NULL, " ");
        if (ptr != NULL && atof(ptr)) {
            pushPL(&current, ptr);
        } else if (ptr != NULL) {
            if (strcmp(ptr, "+") == 0)
                current = plus(current);
            else if (strcmp(ptr, "-") == 0)
                current = minus(current);
            else if (strcmp(ptr, "*") == 0)
                current = multi(current);
            else if (strcmp(ptr, "/") == 0)
                current = devide(current);
            else if (strcmp(ptr, "^") == 0)
                current = power(current);
            else if (strcmp(ptr, "~") == 0)
                current = uniminus(current);
            else if (strcmp(ptr, "s") == 0)
                current = sinus(current);
            else if (strcmp(ptr, "o") == 0)
                current = cosinus(current);
            else if (strcmp(ptr, "l") == 0)
                current = logorithm(current);
            else if (strcmp(ptr, "q") == 0)
                current = sqroot(current);
            else if (strcmp(ptr, "t") == 0)
                current = tangen(current);
            else if (strcmp(ptr, "c") == 0)
                current = cotang(current);
            else if (strcmp(ptr, "x") == 0 || strcmp(ptr, "X") == 0) {
                current = pushPL(&current, ptr);
                current->num = x;
            } else {
                status = 0;
                printf("n/a");
            }
        }
    }
    if (status == 1)
        result = current->num;
    else
        result = 0;
    destroyPL(root);
    return result;
}

struct pole* plus(struct pole* current) {
    double result = current->num + current->next->num;
    popPL(&current);
    current->num = result;
    return current;
}

struct pole* minus(struct pole* current) {
    double result = current->next->num - current->num;
    popPL(&current);
    current->num = result;
    return current;
}

struct pole* multi(struct pole* current) {
    double result = current->next->num * current->num;
    popPL(&current);
    current->num = result;
    return current;
}

struct pole* devide(struct pole* current) {
    double result = current->next->num * pow(current->num, -1);
    popPL(&current);
    current->num = result;
    return current;
}

struct pole* power(struct pole* current) {
    double result = pow(current->next->num, current->num);
    popPL(&current);
    current->num = result;
    return current;
}

struct pole* uniminus(struct pole* current) {
    double result = current->num * -1;
    current->num = result;
    return current;
}

struct pole* sinus(struct pole* current) {
    double result = sin(current->num);
    current->num = result;
    return current;
}

struct pole* cosinus(struct pole* current) {
    double result = cos(current->num);
    current->num = result;
    return current;
}

struct pole* logorithm(struct pole* current) {
    double result = log(current->num);
    current->num = result;
    return current;
}

struct pole* sqroot(struct pole* current) {
    double result = sqrt(current->num);
    current->num = result;
    return current;
}

struct pole* tangen(struct pole* current) {
    double result = tan(current->num);
    current->num = result;
    return current;
}

struct pole* cotang(struct pole* current) {
    double result = 1.0 / tan(current->num);
    current->num = result;
    return current;
}