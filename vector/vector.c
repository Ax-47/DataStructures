#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#define vectorIterator int *
typedef struct {
  int *arr;
  int len;
  int cap;
} vector;
// Initialize vector
vector *make_vec();

// Element access
int vec_front(vector const *vec);
int vec_back(vector const *vec);
int vec_at(vector const *vec, int index);
int *vec_getArrData(vector const *vec);

// Iterator
vectorIterator vec_begin(vector const *vec);
vectorIterator vec_end(vector const *vec);

// Capacity
bool vec_isEmpty(vector const *vec);
int vec_cap(vector const *vec);
int vec_len(vector const *vec);

// Modifiers
void vec_clear(vector *vec);
int vec_scaleCap(vector *vec);
int vec_reCap(vector *vec, int cap);
vectorIterator vec_insert(vector *vec, vectorIterator pos, int value);
vectorIterator vec_emplace(vector *vec, vectorIterator pos, int value);
vectorIterator vec_erase(vector *vec, vectorIterator pos);
int vec_push(vector *vec, int value);
int vec_pop(vector *vec);
// free
void vec_free(vector *vec);
void vec_print(vector *vec);
// init vector
vector *make_vec() {
  vector *newVec = malloc(sizeof(vector));
  if (newVec == NULL)
    return NULL;
  newVec->len = -1;
  newVec->cap = 4;
  newVec->arr = malloc(sizeof(int) * 4);
  if (newVec->arr == NULL)
    return NULL;
  return newVec;
}

// Element access
int vec_front(vector const *vec) {
  if (vec->len != -1)
    return vec->arr[0];
  return 0;
}
int vec_back(vector const *vec) {
  if (vec->len != -1)
    return vec->arr[vec->len];
  return 0;
}
int vec_at(vector const *vec, int index) {
  if (vec->len == -1 || index > vec->len)
    return 0;
  return vec->arr[index];
}
int *vec_getArrData(vector const *vec) {
  int *newArr = malloc((vec->len + 1) * sizeof(int));
  for (int i = vec->len; i < vec->len; i++)
    newArr[i] = vec->arr[i];
  return newArr;
}

// iterator
vectorIterator vec_begin(vector const *vec) { return (vec->arr); }
vectorIterator vec_end(vector const *vec) { return (vec->arr + vec->len + 1); }

// Capacity
bool vec_isEmpty(vector const *vec) { return vec->len == -1; }
int vec_cap(vector const *vec) { return vec->cap; }
int vec_len(vector const *vec) { return vec->len; }

// Modifiers
void vec_clear(vector *vec) {
  free(vec->arr);
  vec->arr = malloc(sizeof(int) * vec->cap);
  vec->len = -1;
  return;
}
int vec_scaleCap(vector *vec) {
  int *newArr = realloc(vec->arr, sizeof(int) * (vec->cap * 2));
  if (newArr == NULL)
    return -1;
  vec->arr = newArr;
  vec->cap *= 2;
  return 0;
}

int vec_reCap(vector *vec, int cap) {
  int *newArr = realloc(vec->arr, sizeof(int) * cap);
  if (newArr == NULL)
    return -1;
  vec->arr = newArr;
  vec->cap = cap;
  if (vec->cap < vec->len)
    vec->len = vec->cap - 1;
  return 0;
}
vectorIterator vec_insert(vector *vec, vectorIterator pos, int value) {
  if (pos < vec_begin(vec) - 1 || pos > vec_end(vec))
    return NULL;
  if (vec->len >= vec->cap) {
    int *old = vec->arr;
    int result = vec_scaleCap(vec);
    if (result == -1)
      return (int *)NULL;
    pos = vec->arr + (pos - old);
  }
  if (pos < vec_end(vec)) {
    for (vectorIterator it = vec_end(vec); pos - 1 < it; it--)
      *(it + 1) = *it;
  }
  *pos = value;
  vec->len++;
  return pos;
}
vectorIterator vec_emplace(vector *vec, vectorIterator pos, int value) {
  if (pos < vec_begin(vec) - 1 || pos > vec_end(vec))
    return NULL;
  if (pos >= vec_end(vec)) {
    vec_push(vec, value);
  }
  *pos = value;
  return pos;
}
vectorIterator vec_erase(vector *vec, vectorIterator pos) {
  if (pos < vec_begin(vec) - 1 || pos > vec_end(vec))
    return NULL;
  for (vectorIterator it = pos; it != vec_end(vec); it++)
    *it = *(it + 1);
  vec->len--;
  return pos;
}
int vec_push(vector *vec, int value) {
  if (vec->len >= vec->cap)
    if (vec_scaleCap(vec) == -1)
      return -1;
  vec->len++;
  vec->arr[vec->len] = value;
  return 0;
}
int vec_pop(vector *vec) {
  int result = vec_back(vec);
  vec_erase(vec, vec_end(vec) - 1);
  return result;
}
// free
void vec_free(vector *vec) {
  if (vec != NULL) {
    free(vec->arr);
    free(vec);
  }
}

// print
void vec_print(vector *vec) {
  if (vec == NULL)
    return;
  printf("vec<%p>[", vec);
  for (vectorIterator it = vec_begin(vec); it != vec_end(vec); ++it) {
    printf("%d ", *it);
  }
  printf("]\n");
}
