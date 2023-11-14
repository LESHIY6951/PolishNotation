#ifndef POLISH_MATH_H
#define POLISH_MATH_H
#include "stack.h"

double calculate(char* stack, double x);
struct pole* plus(struct pole* current);
struct pole* minus(struct pole* current);
struct pole* multi(struct pole* current);
struct pole* devide(struct pole* current);
struct pole* power(struct pole* current);
struct pole* uniminus(struct pole* current);
struct pole* cosinus(struct pole* current);
struct pole* sinus(struct pole* current);
struct pole* logorithm(struct pole* current);
struct pole* sqroot(struct pole* current);
struct pole* tangen(struct pole* current);
struct pole* cotang(struct pole* current);
#endif