#include "Stack.h"
#include <stdio.h>
#include <stdlib.h>


void stack_init(Stack *stack) {
    stack->top = -1;
    stack->capacity = 1;
    stack->data = NULL;
    

}

bool stack_isEmpty(Stack *stack) {
    return stack->top == -1;
}



void stack_push(Stack *stack, TYP value) {
        stack->capacity *= 2;
        stack->data = (TYP *)realloc(stack->data, stack->capacity * sizeof(TYP));
        if (!stack->data) {
            fprintf(stderr, "Memory allocation failed\n");
            exit(EXIT_FAILURE);
        }
    stack->data[++stack->top] = value;
}

TYP stack_pop(Stack *stack) {
    return stack->data[stack->top--];
}

void stack_freeStack(Stack *stack) {
    free(stack->data);
    stack->data = NULL;
    stack->top = -1;
    stack->capacity = 0;
}
