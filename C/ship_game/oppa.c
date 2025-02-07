#include <stdio.h>

#define MAX_SIZE 100

typedef struct {
    int items[MAX_SIZE];
    int top;
} Stack;

void stack_init(Stack* s) {
    s->top = -1;
}

int stack_is_empty(Stack* s) {
    return s->top == -1;
}

int stack_is_full(Stack* s) {
    return s->top == MAX_SIZE - 1;
}

int stack_push(Stack* s, int value) {
    if (stack_is_full(s)) {
        return 0; 
    }
    s->items[++(s->top)] = value;
    return 1; 
}

int stack_pop(Stack* s, int* value) {
    if (stack_is_empty(s)) {
        return 0;
    }
    *value = s->items[(s->top)--];
    return 1; 
}

int stack_peek(Stack* s, int* value) {
    if (stack_is_empty(s)) {
        return 0; 
    }
    *value = s->items[s->top];
    return 1;
}

void stack_opposite(Stack* s) {
    int temp[MAX_SIZE];
    int i = 0;
    while (!stack_is_empty(s)) {
        stack_pop(s, &temp[i++]);
    }
    for (int j = 0; j < i; j++) {
        stack_push(s, temp[j]);
    }
}

void stack_copy(Stack* dest, Stack* src) {
    Stack temp;
    stack_init(&temp);
    int value;
    
    while (!stack_is_empty(src)) {
        stack_pop(src, &value);
        stack_push(&temp, value);
    }
    
    while (!stack_is_empty(&temp)) {
        stack_pop(&temp, &value);
        stack_push(src, value);
        stack_push(dest, value);
    }
}

int if_num_in_stack(Stack* s, int num) {
    for (int i = 0; i <= s->top; i++) {
        if (s->items[i] == num) {
            return 1; 
        }
    }
    return 0;
}

int total_items_in_stack(Stack* s) {
    return s->top + 1;
}

void split_stack(Stack* s, Stack* s1, Stack* s2, int (*criterion)(int)) {
    int value;
    Stack temp;
    stack_init(&temp);

    while (!stack_is_empty(s)) {
        stack_pop(s, &value);
        if (criterion(value)) {
            stack_push(s1, value);
        } else {
            stack_push(s2, value);
        }
    }

    while (!stack_is_empty(&temp)) {
        stack_pop(&temp, &value);
        stack_push(s, value);
    }
}

void united_stack(Stack* s1, Stack* s2, Stack* dest) {
    Stack temp1, temp2;
    stack_init(&temp1);
    stack_init(&temp2);

    int value;

    while (!stack_is_empty(s1)) {
        stack_pop(s1, &value);
        stack_push(&temp1, value);
    }
    while (!stack_is_empty(s2)) {
        stack_pop(s2, &value);
        stack_push(&temp2, value);
    }

    while (!stack_is_empty(&temp1)) {
        stack_pop(&temp1, &value);
        stack_push(dest, value);
        stack_push(s1, value);
    }
    while (!stack_is_empty(&temp2)) {
        stack_pop(&temp2, &value);
        stack_push(dest, value);
        stack_push(s2, value);
    }
}

void stack_empty(Stack* s) {
    s->top = -1;
}

int is_equal_stack(Stack* s1, Stack* s2) {
    if (s1->top != s2->top) {
        return 0; 
    }
    for (int i = 0; i <= s1->top; i++) {
        if (s1->items[i] != s2->items[i]) {
            return 0; 
        }
    }
    return 1; 
}

int stack_sum(Stack* s) {
    int sum = 0;
    for (int i = 0; i <= s->top; i++) {
        sum += s->items[i];
    }
    return sum;
}

void print_stack(Stack* s) {
    for (int i = 0; i <= s->top; i++) {
        printf("%d ", s->items[i]);
    }
    printf("\n");
}
int isXCY(char[] str , int n){
    Stack s1;
    stack_init(s1);
    Stack s2;
    stack_init(s2);
    Stack s = s1;
    short flag = 1;
    for(int i = 0 ; i < n ; i++){
        if(str[i] == 'A' || str[i] == 'B'){
            stack_push(s, str[i]);
        }else if(str[i] == 'C' && flag){
            s = s2;
            flag = 0;
        }else{
            return 0;
        }
    }
    return is_equal_stack(s1, stack_opposite(s2));

}
int are_permutations(Stack s1, Stack s2) { 
    Stack tmp;
    stack_init(tmp);

    int value1;
    int value2;
    satck_pop(s1,&value1);


    while (!stack_is_empty(s1)) {
        satck_pop(s2,&value2);
        if(value1 == value2){
            stack_pop(s1,&value1);

        }else{
            stack_push(tmp, value2);
        if(stack_empty(s2)){
            Stack t = s2;
            s2 = tmp;
            tmp = t;
        }else if(stack_empty(tmp)){
            Stack t = s2;
            s2 = tmp;
            tmp = t;
        }

        }
        

    }
}

int isN_M(char str[], int n){
    int i = 1;
    Stack s1;
    Stack s2; 
 
    stack_init(s1);
    stack_init(s2);

    while(str[i] != '*'){
        if(i%2 == 0){
            stack_push(s1, str[i]);
        }
        i++;
    }
    while(i < n){
        stack_push(s2, str[i]);
        i++;
    }
    return is_equal_stack(s1, stack_opposite(s2));
}
Stack func(Stack s1 , Stack s2){
    while(!stack_empty(s1)){
        if(!if_num_in_stack(s1,stack_pop(s2))){
            stack_pop(s1);
        }
    }
    return s1;
}















int main(){
    char a[] = "HEL(L)O WORLD";
    printf("%d\n",  is_valid(a));
   
    return 0;
}