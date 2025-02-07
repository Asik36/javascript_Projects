#include <stdio.h>
#include <stdlib.h>

// LLL structure
typedef struct LLL {
    int data;
    struct LLL* next;
} LLL;

// Function to create a new LLL
LLL* createLLL(int data) {
    LLL* newLLL = (LLL*)malloc(sizeof(LLL));
    if (!newLLL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newLLL->data = data;
    newLLL->next = NULL;
    return newLLL;
}

// Function to insert a LLL at the beginning of the list
LLL* insertAtBeginning(LLL* head, int data) {
    LLL* newLLL = createLLL(data);
    newLLL->next = head;
    return newLLL;
}

// Function to insert a LLL at the end of the list
LLL* insertAtEnd(LLL* head, int data) {
    LLL* newLLL = createLLL(data);
    if (head == NULL) {
        return newLLL;
    }
    LLL* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newLLL;
    return head;
}

// Function to insert a LLL at a specific position
LLL* insertAtPosition(LLL* head, int data, int position) {
    if (position < 0) {
        printf("Position must be non-negative.\n");
        return head;
    }
    if (position == 0) {
        return insertAtBeginning(head, data);
    }

    LLL* newLLL = createLLL(data);
    LLL* current = head;
    for (int i = 0; i < position - 1 && current != NULL; i++) {
        current = current->next;
    }

    if (current == NULL) {
        printf("Position out of bounds.\n");
        free(newLLL);
        return head;
    }

    newLLL->next = current->next;
    current->next = newLLL;
    return head;
}

// Function to delete a LLL by its value
LLL* deleteByValue(LLL* head, int value) {
    if (head == NULL) {
        printf("List is empty.\n");
        return head;
    }

    // If the LLL to be deleted is the head
    if (head->data == value) {
        LLL* temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    LLL* current = head;
    LLL* previous = NULL;

    while (current != NULL && current->data != value) {
        previous = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Value not found in the list.\n");
        return head;
    }

    previous->next = current->next;
    free(current);
    return head;
}

// Function to display the linked list
void printList(LLL* head) {
    LLL* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// Function to free all LLLs in the list
void freeList(LLL* head) {
    LLL* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

// Main function for testing
int main() {
        int arr[5] = {1, 2, 3, 4, 5}; /* מגדירים מערך של חמישה מספרים שלמים */
    printf("גודלו של משתנה מטיפוס שלם הוא %d בתים\n", sizeof(int));
    printf("כמובן, גודלו של איבר במערך הוא %d בתים\n", sizeof(arr[0]));
    printf("גודלו של המערך כולו הוא %d בתים\n", sizeof(arr));
    printf("לכן, במערך יש %d איברים\n", sizeof(arr) / sizeof(arr[0]));

    return 0;

}



