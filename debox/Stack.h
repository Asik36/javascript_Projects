#ifndef STACK_H
#define STACK_H
#include <stdbool.h>
#include "Box.h"
#define TYP Box*
typedef struct {
    TYP *data;    
    int top;      
    int capacity; 
} Stack;

void stack_init(Stack *stack);

bool stack_isEmpty(Stack *stack);


void stack_push(Stack *stack, TYP value);

TYP stack_pop(Stack *stack);

void stack_freeStack(Stack *stack);
#endif 