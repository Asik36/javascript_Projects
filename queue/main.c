#include <stdio.h>
#define MAX_SIZE 100

typedef struct {
    int items[MAX_SIZE];
    int front;
    int rear;
} Queue;

void initializeQueue(Queue* q)
{
    q->front = -1;
    q->rear = 0;
}

int isEmpty(Queue* q) { return (q->front == q->rear - 1); }
int isFull(Queue* q) { return (q->rear == MAX_SIZE); }

void enqueue(Queue* q, int value)
{
    if (isFull(q)) {
        printf("Queue is full\n");
        return;
    }
    q->items[q->rear] = value;
    q->rear++;
}

int dequeue(Queue* q)
{
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return -1;
    }
    q->front++;
    return q->items[q->front];
 
}
void printQueue(Queue* q)
{
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return;
    }

    printf("Current Queue: ");
    for (int i = q->front + 1; i < q->rear; i++) {
        printf("%d ", q->items[i]);
    }
    printf("\n");
}

void redBlackQueue(Queue* q){
    Queue red;
    initializeQueue(&red);
    Queue black;
    initializeQueue(&black);
    int value;
    while(!isEmpty(q)){
        value = dequeue(q);
        (value) ? enqueue(q, value) : enqueue(&red,value);
    }
    while(!isEmpty(&red)){
        enqueue(q, dequeue(&red));
    }
    while(!isEmpty(&black)){
        enqueue(q, dequeue(&black));
    }
}


int IsQueueDiffrent1(Queue* q1, Queue* q2){
    int value;
    int flag = 1;
    while(!isEmpty(q1)){
        value = dequeue(q1);
        while(!isEmpty(q2)){
            if(value == dequeue(q2) && flag == 1){
                flag = 0;       
            }
        }
    }
    return flag;
}
int findMaxQueue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return -1; 
    }

    int max = dequeue(q);             
    enqueue(q, max);                  

    while (!isEmpty(q)) {   
        int value = dequeue(q);        
        if (value > max) {
            max = value;               
        }
        enqueue(q, value);             
    }

    return max;
}
int IsQueueDiffrent(Queue* q1, Queue* q2){
    int flag = 1;
    int max1 = findMaxQueue(q1);
    int max2 = findMaxQueue(q2);
    int max = max1>max2 ? max1 : max2;

    int* arr = (int*)malloc(max * sizeof(int));

    while((!isEmpty(q1) || !isEmpty(q2))&& flag){
        int value = dequeue(q1);
        arr[value]++;
        if(arr[value] > 1)  flag = 0;
        value = dequeue(q2);
        arr[value]++;
        if(arr[value] > 1)  flag = 0;

    }
    return flag;
}

Queue sortQueue(Queue* q){
    Queue sorted;
    initializeQueue(&sorted);
    int value;
    while(!isEmpty(q)){
        value = dequeue(q);
        while(!isEmpty(q) && value > dequeue(q)){
            enqueue(&sorted, dequeue(q));
        }
        enqueue(&sorted, value);
        while(!isEmpty(&sorted) && value < dequeue(&sorted)){
            enqueue(q, dequeue(&sorted));
        }
    }
    return sorted;
}
int isQueueDiffrent3(Queue* q1 ,Queue* q2){
    int flag = 1;
    Queue sortedQ1 = sortQueue(q1);
    Queue sortedQ2 = sortQueue(q2);
    while((!isEmpty(q1) && !isEmpty(q2))&& flag){
        flag = dequeue(q1) != dequeue(q2);        
    } 
    return flag;

}
int isSortedQueue(Queue* q1){
    int value;
    int max = 0;

    int flag = 1;
    while(!isEmpty(q1) && flag){
        value = dequeue(q1);
        if(value > max){
            max = value;
        }else{
            flag = 0;
        }
    }
    flag ? printf("cute"): printf("not cute");
    return flag;

}
