#include "../../stack/stack.h"
#include <stdio.h>

int main() {
    stack *stk = make_stack();

    // Push elements onto the stack
    stack_push(stk, 10);
    stack_push(stk, 20);
    stack_push(stk, 30);

    // Peek at the top element
    printf("Top element is: %d\n", stack_peek(stk));

    // Pop elements from the stack
    printf("Popped: %d\n", stack_pop(stk));
    printf("Popped: %d\n", stack_pop(stk));

    // Check if the stack is empty
    if (stack_isEmpty(stk)) {
        printf("The stack is empty.\n");
    } else {
        printf("The stack is not empty.\n");
    }

    // Free the stack
    stack_free(stk);

    return 0;
}
