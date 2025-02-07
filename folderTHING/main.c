#include <stdio.h>
#include <ctype.h>

#define MAX_SIZE 100

typedef struct {
   int arr[MAX_SIZE]; 
   int top;       
} Stack;


void initialize(Stack *stack) {
   stack->top = -1; 
}


int isEmpty(Stack *stack) {
   return stack->top == -1; 
}


int isFull(Stack *stack) {
   return stack->top == MAX_SIZE - 1; 
}


void push(Stack *stack, int value) {
   if (isFull(stack)) {
       printf("Stack Overflow\n");
       return;
   }
   stack->arr[++stack->top] = value;
}


int pop(Stack *stack) {
   if (isEmpty(stack)) {
       printf("Stack Underflow\n");
       return -1;
   }
   int popped = stack->arr[stack->top];
   stack->top--;
   return popped;
}


int peek(Stack *stack) {
   if (isEmpty(stack)) {
       return -1;
   }
   return stack->arr[stack->top];
}

void print_stack(Stack *stack){
   printf("Stack: ");
   for(int i = stack->top; i >= 0; i--){
       printf("%c", stack->arr[i]);
   }
   printf("\n");
}

void stack_to_stack(Stack *s1,Stack *s2){
   while(!isEmpty(s1)){
       push(s2, pop(s1));
   }
}
Stack reverse_stack(Stack *stack){
    Stack reversed;
    initialize(&reversed);
    while(!isEmpty(stack)){
        push(&reversed, pop(stack));
    }
    return reversed;
}
int is_valid(const char *str) {
    int result = 1;

    if (*str != '/') {
        result = 0;
    } else {
        str++;

        while (*str && result == 1) {
            if (!isalpha(*str) && !isdigit(*str) && *str != '.' && *str != '/' && *str != '_') {
                result = 0;
            }
            str++;
        }
    }
    return result;
}
void getInput(char *input){
   do{
   gets(input);
   printf("The entered folder location is: %s\n", input);
   }while(!is_valid(input));
}

Stack string_to_stack(char * dir){
   Stack stack;
   initialize(&stack);
  
   int i = 0;
   while(dir[i]!= '\0'){
       push(&stack, dir[i]);
       i++;
   }
   return stack;

}

void remove_following_duplicates_stack(Stack *stack,char ch){
   Stack temp;
   initialize(&temp);
   int count = 0;
   char value;
   while(!isEmpty(stack)){
       value = pop(stack);
       if(value == ch){
           count++;
           if(count <= 1){
               push(&temp,value);
           }
       }else{
           count = 0;
           push(&temp,value);
       }
   }
   stack_to_stack(&temp, stack);

}


void remove_word_stack(Stack *stack){
   char value;
   while(!isEmpty(stack) && value == '/'){
        value = pop(stack);
   }
   while(!isEmpty(stack) && value != '/'){
       value = pop(stack);
   }

}
void removeDots(Stack *stack){
    Stack temp;
    initialize(&temp);
    while(!isEmpty(stack)){
        char value = pop(stack);
        if(value== '.'){
            if(peek(stack) == '.'){
                remove_word_stack(stack);
            }
            remove_word_stack(stack);
        }
        else{
            push(&temp, value);
        }
    }
    stack_to_stack(&temp, stack);


}

int main() {
    char dir[100];
    getInput(dir);
    Stack stack = string_to_stack(dir);
    removeDots(&stack);
    remove_following_duplicates_stack(&stack, '/');
    if(peek(&stack) == '/'){
        pop(&stack);
    }
    Stack temp = reverse_stack(&stack);
    print_stack(&temp);

   return 0;
}
