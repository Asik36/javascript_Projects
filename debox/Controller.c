#include <stdio.h>
#include "Box.h"
#include <string.h>
#include "stack.h"
#include "Model.h"
#include <stdlib.h>
Box* createBoxFromUserInput();
void stack_print(Stack *stack);
void stack_print(Stack *stack);
int main(){
    Stack stack;
    stack_init(&stack); 

   Box* box;
    while(1){
        box = createBoxFromUserInput();
        addBox(&stack, box);
        stack_print(&stack);
    }

    return 0; 
}

void stack_print(Stack *stack){
    Box *tmpBox;
    Stack tmpStack;
    stack_init(&tmpStack);
    printf("Stack contents:\n");
    while(!stack_isEmpty(stack)){
        tmpBox = stack_pop(stack);
        stack_push(&tmpStack, tmpBox);
    }
    while(!stack_isEmpty(&tmpStack)){
        tmpBox = stack_pop(&tmpStack);
        box_printBox(tmpBox);
        stack_push(stack, tmpBox);

    }

}
Box* createBoxFromUserInput() {
    char* name = malloc(sizeof(char)*20); // Temporary buffer for the name
    int amount, max_amount;
    fflush(stdout);

    // Prompt user for input
    printf("Enter box name:");
    fflush(stdin);
    fgets(name,20,stdin);
    printf("Enter box amount:");
    while (scanf("%d", &amount) != 1 || amount < 0) { 
        printf("Invalid amount. Please enter a non-negative integer: ");
        while (getchar() != '\n'); 
    }

    printf("Enter box maximum capacity:");
    while (scanf("%d", &max_amount) != 1 || max_amount <= 0) { 
        printf("Invalid capacity. Please enter a positive integer: ");
        while (getchar() != '\n'); 
    }

    if (amount > max_amount) {
        printf("Warning: Initial amount exceeds maximum capacity. Adjusting amount to max capacity.\n");
        amount = max_amount;
    }

    Box* newBox = malloc(sizeof(Box));
    box_init(newBox);
    newBox->name = name;
    newBox->amount = amount;
    newBox->max_amount = max_amount;
    return newBox;
}

void stack_print(Stack *stack){
    Box *tmpBox;
    Stack tmpStack;
    stack_init(&tmpStack);
    printf("Stack contents:\n");
    while(!stack_isEmpty(stack)){
        tmpBox = stack_pop(stack);
        stack_push(&tmpStack, tmpBox);
    }
    while(!stack_isEmpty(&tmpStack)){
        tmpBox = stack_pop(&tmpStack);
        box_printBox(tmpBox);
        stack_push(stack, tmpBox);

    }

}
