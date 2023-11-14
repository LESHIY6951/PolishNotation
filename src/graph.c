#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "field.h"
#include "graph_io.h"
#include "polish_math.h"
#include "stack.h"
#include "structPL.h"

char* getStr();
char* tranaslate(char* str);
#define M 80
#define N 25

int main() {
    char* str = getStr();
    int status = 1;
    if (str != NULL && strcmp(str, "") == 0) {
        status = 0;
    }
    if (status == 1) {
        char* stack = tranaslate(str);
        if (stack[0] != '\0') {
            struct all_dots dots[80];
            double x = 0;
            char** graph = (char**)malloc(N * sizeof(int*));
            for (int i = 0; i < N; i++) {
                graph[i] = (char*)malloc(M * sizeof(int));
            }
            create(graph);
            int i = 0;
            while (x < 4 * M_PI) {
                dots[i].x = x;
                dots[i].y = calculate(stack, x);  //сюда надо передать нужную функцию/уравнение
                x += M_PI / 20;
                i++;
            }

            mk_dots(dots, graph);
            output(graph);
            free_mem(graph);
        }
        free(stack);
    }
    free(str);
    if (status == 0) {
        printf("n/a");
    }

    return 0;
}
