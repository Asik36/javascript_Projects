#ifndef BOX_H
#define BOX_H
#include <stdbool.h>

typedef struct {
    char *name;         
    unsigned int amount; 
    unsigned int max_amount;
} Box;


void box_init(Box *box);

bool box_isEmpty(Box *box);
bool box_isFull(Box *box);

int boxToBox(Box *box1, Box *box2);

void box_printBox(Box *box);

#endif 