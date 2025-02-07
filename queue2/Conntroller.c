#include <stdio.h>
#include "myQueue.h"
#include "Model.h"

void check1() {
	Queue q1, q2, result;

	init_queue(&q1);
	init_queue(&q2);
	init_queue(&result);

	// (int)q1 = 1234
	enqueue(&q1, 1);
	enqueue(&q1, 2);
	enqueue(&q1, 3);
	enqueue(&q1, 4);

	// (int)q2 = 456
	enqueue(&q2, 4);
	enqueue(&q2, 5);
	enqueue(&q2, 6);

	// (int)result = 1690
	add_queue(&q1, &q2, &result);
	
	print_queue(&result);
}
void check2() {
	Queue q1,q2;
	int lowest;

	init_queue(&q1);
	init_queue(&q2);
	
	enqueue(&q1, 4);
	enqueue(&q1, 3);
	enqueue(&q1, 2);
	enqueue(&q1, 1);
	


	
	
	enqueue(&q2, 9);
	enqueue(&q2, 6);
	enqueue(&q2, 3);
	enqueue(&q2, 2);
	
	
	
	
	
	
	
	lowest = getDuo(&q1, &q2);
	printf("%d \n", lowest);

}


void check3() {
	Queue q1, q2;
	int is_perm;

	init_queue(&q1);
	init_queue(&q2);

	enqueue(&q1, 1);
	enqueue(&q1, 2);
	enqueue(&q1, 3);

	enqueue(&q2, 3);
	enqueue(&q2, 1);
	enqueue(&q2, 2);


	is_perm = is_permutation_queue(&q1, &q2);

	printf("Queues are %s permutations", is_perm ? "" : "not");

}



int main() {
	check1();
	check2();
	check3();
}