
#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS
#include "myQueue.h"

void add_queue(Queue* q1, Queue* q2, Queue* result) {
	int num1 = 0, num2 = 0, sum, reversed;


	enqueue(q1, -1);
	enqueue(q2, -1);


	// move numbers to integers
	int T1 = dequeue(q1);
	int T2 = dequeue(q2);
	while (T1 != -1){
		num1 = num1 * 10 + T1;
		enqueue(q1, T1);
		T1 = dequeue(q1);
	}
	while (T2 != -1) {

		num2 = num2 * 10 + T2;
		enqueue(q2, T2);
		T2 = dequeue(q2);
	}

	// add numbers
	sum = num1 + num2;

	// put in result
    while (sum != 0) {
        enqueue(result, sum % 10);
        sum /= 10;
    }
}
TYP getDuo(Queue* q1, Queue* q2){
    TYP a = dequeue(q1);
    TYP b = dequeue(q2);
    TYP tempA = a+1,tempB = b+1, value = -1;
    while(a<tempA && b < tempB){
        if(a>b){
            enqueue(q1,a);
            tempA = a;
            a = dequeue(q1);
        }
		else {
			if (a < b) {
				enqueue(q2, b);
				tempB = b;
				b = dequeue(q2);
			}
			else {
				value = a;
				enqueue(q1, a);
				enqueue(q2, b);
				tempA = a;
				tempB = b;
				a = dequeue(q1);
				b = dequeue(q2);
		}
		}

    }
    enqueue(q1,a);
    enqueue(q2, b);

    return value;
}
int is_permutation_queue(Queue* q1, Queue* q2) {
	/*
	*if the queues are not the same size immediate return.

		T(n, n) = 2*O(n) + O(n * (O(n) + O(n))) = 2*O(n^2) + 2*O(n)
	*/

	Queue copy1, copy2, temp;
	init_queue(&copy1);
	init_queue(&copy2);
	init_queue(&temp);
	copy_queue(q1, &copy1);
	copy_queue(q2, &copy2);

	TYP item, curr;
	int is_found;

	is_found = 1;
	while (!is_empty_queue(&copy1) && is_found) {
		item = dequeue(&copy1);
		is_found = 0;

		while (!is_empty_queue(&copy2) && !is_found) {
			curr = dequeue(&copy2);
			is_found = curr == item;
			if (!is_found)
				enqueue(&temp, curr);
		}

		while (!is_empty_queue(&temp))
			enqueue(&copy2, dequeue(&temp));
	}

	return is_found;
}





