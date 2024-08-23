#ifndef INT_PAIR_H
#define INT_PAIR_H
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int first;
  int second;
} int_pair;

// functions declaration
int_pair *make_pair_default();
int_pair *make_pair(int first, int second);
bool int_pair_cmp(int_pair const *lhs, int_pair const *rhs);
int int_pair_swap(int_pair *pair_lhs, int_pair *pair_rhs);
void print_int_pair(int_pair const *pair);
int_pair *int_pair_clone(int_pair const *pair);
void int_pair_free(int_pair **pair);

#endif
