#include <stdio.h>
#include "Box.h"
#include <string.h>
#include "stack.h"
#include <stdlib.h>

void addBox(Stack *stack, Box *box) {
    Stack temp;
    stack_init(&temp);

    int found = 0;
    Box* topBox;

    while (!stack_isEmpty(stack) && !found) { 
        topBox = stack_pop(stack);
        if (strcmp(topBox->name, box->name) == 0) {
            if (boxToBox(topBox, box)) {
                stack_push(stack, topBox);
                stack_push(stack, box); 
            } else {
                stack_push(&temp, topBox); 
            }
            found = 1;
        }
        else{
            stack_push(&temp, topBox);
        }

    }

    while (!stack_isEmpty(&temp)) {
        stack_push(stack, stack_pop(&temp));
    }

    if (!found) {
        stack_push(stack, box);
    }

    stack_freeStack(&temp);
}



