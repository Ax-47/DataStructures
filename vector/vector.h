#ifndef VECTOR_H
#define VECTOR_H
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
#endif // VECTOR_H
