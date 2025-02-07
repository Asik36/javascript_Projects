#include "box.h"
#include "stack.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

void box_init(Box *box){

    box->name = "";
    box->amount = 0;
    box->max_amount = 0;

}
bool box_isEmpty(Box *box){
    return box->amount == 0;
}
bool box_isFull(Box *box){
    return box->amount == box->max_amount;
}

int boxToBox(Box *box1, Box *box2) {
    int transferable = box1->max_amount - box1->amount;

    if (transferable >= box2->amount) {
        // Box1 can take all of box2's amount
        box1->amount += box2->amount;
        box2->amount = 0;
    } else {
        // Box1 takes as much as it can, leaving the rest in box2
        box1->amount = box1->max_amount;
        box2->amount -= transferable;
    }
    return box2->amount;
}
void box_printBox(Box *box){
    printf("Name: %s , Number: %d , max Size: %d\n", box->name, box->amount, box->max_amount);
}
