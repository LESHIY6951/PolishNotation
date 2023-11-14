#include "field.h"

#include <stdio.h>
#include <stdlib.h>
#define M 80
#define N 25

int mk_dots(struct all_dots* dots, char** graph) {
    double stp = 2.0 / 24.0;
    for (int i = 0; i < M; i++) {
        double n = -1.0;
        for (int j = 0; j < N; j++) {
            if (dots[i].y >= n - stp / 2 && dots[i].y <= n + stp / 2) {
                graph[j][i] = '*';
            }
            n += stp;
        }
    }
    return 0;
}
int free_mem(char** graph) {
    for (int i = 0; i < N; i++) {
        free(graph[i]);
    }
    free(graph);
    return 0;
}

int create(char** graph) {
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++) graph[i][j] = '.';
    return 0;
}

int output(char** graph) {
    printf("\033[0d\033[2J");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) printf("%c", graph[i][j]);
        printf("\n");
    }
    return 0;
}