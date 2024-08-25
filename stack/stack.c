#include "../vector/vector.h"
#include <stdbool.h>
#include <stdlib.h>
typedef struct {
  vector *data;
  int top;
} stack;

stack *make_stack();
void stack_push(stack *stk, int value);
int stack_pop(stack *stk);
int stack_peek(const stack *stk);
bool stack_isEmpty(const stack *stk);
void stack_free(stack *stk);
// init stack
stack *make_stack() {
  stack *newStack = malloc(sizeof(stack));
  newStack->data = make_vec();
  newStack->top = -1;
  return newStack;
}
void stack_push(stack *stk, int value) {
  vec_push(stk->data, value);
  stk->top++;
}
int stack_pop(stack *stk) {
  if (stk->top == -1)
    return 0;
  int value = vec_pop(stk->data);
  stk->top--;
  return value;
}
int stack_peek(const stack *stk) {
  if (stk->top == -1)
    return 0;
  int value = vec_at(stk->data, stk->top);
  return value;
}
bool stack_isEmpty(const stack *stk) { return stk->top == -1; }
void stack_free(stack *stk) {
  vec_free(stk->data);
  free(stk);
}
