#define myQueue_H

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define SIZE 20
#define TYP int

typedef struct {
    TYP data[SIZE];
    int front;
    int rear;
    int count;
} Queue;

void init_queue(Queue* q);
int enqueue(Queue* q, TYP element);
TYP dequeue(Queue* q);
int is_full_queue(Queue* q);
int is_empty_queue(Queue* q);
void copy_queue(Queue* original, Queue* copy);
void print_queue(Queue* q);

