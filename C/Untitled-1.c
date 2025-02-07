#include <stdio.h>
#include <stdbool.h>
#include <string.h>
// Define the maximim capacity of the stack
#define MAX_SIZE 100

// Define a structure for the stack
typedef struct {
    // Array to store stack elements
    int arr[MAX_SIZE];  
    // Index of the top element in the stack
    int top;        
} Stack;
int match(char open, char close);
// Function to initialize the stack
void initialize(Stack *stack) {
    // Set top index to -1 to indicate an empty stack
    stack->top = -1;  
}

// Function to check if the stack is empty
bool isEmpty(Stack *stack) {
    // If top is -1, the stack is empty
    return stack->top == -1;  
}

// Function to check if the stack is full
bool isFull(Stack *stack) {
    // If top is MAX_SIZE - 1, the stack is full
    return stack->top == MAX_SIZE - 1;  
}

// Function to push an element onto the stack
void push(Stack *stack, int value) {
    // Check for stack overflow
    if (isFull(stack)) {
        printf("Stack Overflow\n");
        return;
    }
    // Increment top and add the value to the top of the stack
    stack->arr[++stack->top] = value;
    printf("Pushed %d onto the stack\n", value);
}

// Function to pop an element from the stack
int pop(Stack *stack) {
    // Check for stack underflow
    if (isEmpty(stack)) {
        printf("Stack Underflow\n");
        return -1;
    }
    // Return the top element 
    int popped = stack->arr[stack->top];
    // decrement top pointer
    stack->top--;
    printf("Popped %d from the stack\n", popped);
    // return the popped element
    return popped;
}

// Function to peek the top element of the stack
int peek(Stack *stack) {
    // Check if the stack is empty
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        return -1;
    }
    // Return the top element without removing it
    return stack->arr[stack->top];
}





int is_valid(char *str) {
    Stack s;
    initialize(&s); 
    int flag = 1;
    int n = strlen(str); 

    for (int i = 0; i < n; i++) {
        if (str[i] == '(' || str[i] == '[' || str[i] == '{') {
            push(&s, str[i]);
        } 
        else if (str[i] == ')' || str[i] == ']' || str[i] == '}') {
            if (isEmpty(&s) || !match(pop(&s), str[i])) {
                flag = 0;
                break;
            }
        }
    }

    if (!isEmpty(&s)) {
        flag = 0;  
    }

    return flag;
}

int match(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '[' && close == ']') ||
           (open == '{' && close == '}');
}


int evaluate_postfix(char expression[]) {
    Stack stack;
    init_stack(stack);
    int result = 0;  

    for (int i = 0; expression[i] != '\0'; i++) 
        if (isdigit(expression[i])) 
            push(&stack, expression[i] - '0');
        else {
            int operand2 = pop(&stack);
            int operand1 = pop(&stack);

            switch (expression[i]) {
                case '+': push(&stack, operand1 + operand2); break;
                case '-': push(&stack, operand1 - operand2); break;
                case '*': push(&stack, operand1 * operand2); break;
                case '/': operand2 ? push(&stack, operand1 / operand2) : result = 0;
                default: if (expression[i] != '+' && expression[i] != '-' && expression[i] != '*' && expression[i] != '/') result = 0;
            }
        }

    result = isEmpty(&stack) ? pop(&stack) : 0;  
    return result;
}


void infix_to_postfix(const char infix, char postfix) {
    Stack stack;
    init_stack(stack);
    int j = 0;

    for (int i = 0; infix[i] != '\0'; i++) {
        char token = infix[i];

        if (isdigit(token)) {
            postfix[j++] = token;
        } else if (token == '(') {
            push(&stack, token);
        } else if (token == ')') {
            while (stack.top != -1 && peek_stack(&stack) != '(') {
                postfix[j++] = pop(&stack);
            }
            pop(&stack);
        } else {
            while (stack.top != -1 && precedence(peek_stack(&stack)) >= precedence(token)) {
                postfix[j++] = pop(&stack);
            }
            push(&stack, token);
        }
    }

    while (stack.top != -1) {
        postfix[j++] = pop_stack(&stack);
    }

    postfix[j] = '\0';
}
int answer() {
    infix_to_postfix(infix, postfix);
    int result = evaluate_postfix(postfix);

    return result;
}



int precedence(char op) {
    switch (op) {
        case '+':
        case '-': return 1;
        case '*':
        case '/': return 2;
        default: return 0;
    }
}

void infix_to_postfix(const char* infix, char* postfix) {
    Stack stack;
    init_stack(&stack);
    int j = 0;

    for (int i = 0; infix[i] != '\0'; i++) {
        char token = infix[i];

        if (isdigit(token)) {
            postfix[j++] = token;
        } else if (token == '(') {
            push_stack(&stack, token);
        } else if (token == ')') {
            while (stack.top != -1 && peek_stack(&stack) != '(') {
                postfix[j++] = pop_stack(&stack);
            }
            pop_stack(&stack);
        } else {
            while (stack.top != -1 && precedence(peek_stack(&stack)) >= precedence(token)) {
                postfix[j++] = pop_stack(&stack);
            }
            push_stack(&stack, token);
        }
    }

    while (stack.top != -1) {
        postfix[j++] = pop_stack(&stack);
    }

    postfix[j] = '\0';
}

int evaluate_postfix(const char* postfix) {
    return 0;
}

int answer(const char* infix) {
    char postfix[MAX];
    infix_to_postfix(infix, postfix);
    int result = evaluate_postfix(postfix);

    return result;
}


int main(){
    char str[] = "{[(AH)]}";
    printf("%d\n", is_valid(str));  // Will print 1 if valid, 0 if not
    return 0;
}

