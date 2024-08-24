
#include "../../vector/vector.h"
#include <stdio.h>

int main() {
  vector *vec = make_vec();
  if (!vec) {
    printf("Failed to create vector\n");
    return -1;
  }

  vec_push(vec, 10);
  vec_push(vec, 20);
  vec_push(vec, 30);

  printf("Vector contents: ");
  vec_print(vec);

  printf("Front: %d\n", vec_front(vec));
  printf("Back: %d\n", vec_back(vec));
  printf("At index 1: %d\n", vec_at(vec, 1));

  vec_insert(vec, vec_begin(vec) + 1, 15);
  printf("After insert: ");
  vec_print(vec);
  vec_emplace(vec, vec_begin(vec) + 1, 300);
  printf("Emplace: ");
  vec_print(vec);
  vec_erase(vec, vec_begin(vec) + 2);
  printf("After erase: ");
  vec_print(vec);

  vec_pop(vec);
  printf("After pop: ");
  vec_print(vec);

  vec_free(vec);
  return 0;
}
