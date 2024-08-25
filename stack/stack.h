#ifndef STACK_H
#define STACK_H

#include "../vector/vector.h"  // Include your vector header file
#include <stdbool.h>           // For using `bool`, `true`, and `false`

typedef struct {
    vector *data;  // Pointer to the vector used as the underlying data structure
    int top;       // Index of the top element
} stack;

// Function to create and initialize a new stack
stack *make_stack();

// Function to push an element onto the stack
void stack_push(stack *stk, int value);

// Function to pop an element from the stack
int stack_pop(stack *stk);

// Function to peek at the top element of the stack without popping it
int stack_peek(const stack *stk);

// Function to check if the stack is empty
bool stack_isEmpty(const stack *stk);

// Function to free the stack and its resources
void stack_free(stack *stk);

#endif // STACK_H
