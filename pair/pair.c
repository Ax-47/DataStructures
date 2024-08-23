#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
typedef struct {
  int first;
  int second;
} int_pair;
int_pair *make_pair_default() {
  int_pair *newPair = malloc(sizeof(int_pair));
  if (newPair == NULL) {
    perror("Failed to allocate memory");
    exit(EXIT_FAILURE);
  }
  newPair->first = 0;
  newPair->second = 0;
  return newPair;
};
int_pair *make_pair(int first, int second) {
  int_pair *newPair = malloc(sizeof(int_pair));
  if (newPair == NULL) {
    perror("Failed to allocate memory");
    exit(EXIT_FAILURE);
  }
  newPair->first = first;
  newPair->second = second;
  return newPair;
};

bool int_pair_cmp(int_pair const *lhs, int_pair const *rhs) {
  return lhs->first == rhs->first && lhs->second == rhs->second;
}
int int_pair_swap(int_pair *pair_lhs, int_pair *pair_rhs) {
  if (pair_lhs == NULL)
    return -1;
  if (pair_rhs == NULL)
    return -2;

  int firstTemp = pair_lhs->first;
  int secondTemp = pair_lhs->second;
  pair_lhs->first = pair_rhs->first;
  pair_lhs->second = pair_rhs->second;
  pair_rhs->first = firstTemp;
  pair_rhs->second = secondTemp;
  return 0;
}
void print_int_pair(int_pair const *pair) {
  if (pair == NULL) {
    printf("this pair is NULL\n");
    return;
  }
  printf("pair_address:%p, pair_value: [%d, %d]\n", pair, pair->first,
         pair->second);
}
int_pair *int_pair_clone(int_pair const *pair) {
  if (pair == NULL) {
    return NULL;
  }
  int_pair *newPair = make_pair(pair->first, pair->second);
  return newPair;
}
void int_pair_free(int_pair **pair) {
  if (pair == NULL)
    return;
  free(*pair);
  (*pair) = NULL;
}
