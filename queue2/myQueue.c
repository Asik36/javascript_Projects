#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#include "myQueue.h"


void init_queue(Queue* q) {
    q->front = 0;
    q->rear = 0;
    q->count = 0;
}

int enqueue(Queue* q, TYP element) {
    if (q->count == SIZE) {
        return -1;
    }
    q->data[q->rear] = element;
    q->rear++;
    if (q->rear == SIZE) q->rear = 0;  // Wrap rear manually
    q->count++;
    return 0;
}

TYP dequeue(Queue* q) {
    if (q->count == 0) {
        return -1;
    }
    TYP element = q->data[q->front];
    q->front++;
    if (q->front == SIZE) q->front = 0;  // Wrap front manually
    q->count--;
    return element;
}

int is_empty_queue(Queue* q) { return q->count == 0; }

int is_full_queue(Queue* q) { return q->count == SIZE; }

void copy_queue(Queue* original, Queue* copy) {
    Queue temp;
    init_queue(&temp);
    TYP item;

    while (!is_empty_queue(original))
        enqueue(&temp, dequeue(original));
    while (!is_empty_queue(&temp)) {
        item = dequeue(&temp);
        enqueue(original, item);
        enqueue(copy, item);
    }
}

void print_queue(Queue* q) {
    Queue copy;
    init_queue(&copy);
    copy_queue(q, &copy);

    printf("front <----- rear\n");
    while (!is_empty_queue(&copy))
        printf("%d ", dequeue(&copy));
    printf("\n\n");
}

