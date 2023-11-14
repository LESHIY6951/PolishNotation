#ifndef FIELD_H
#define FIELD_H

struct all_dots {
    double x;
    double y;
};

int create(char** graph);
int output(char** graph);
int mk_dots(struct all_dots* dots, char** graph);
int free_mem(char** graph);

#endif