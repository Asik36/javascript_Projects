#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = newNode; // Circular link
    newNode->prev = newNode; // Circular link
    return newNode;
}

// Insert at the end
void insertEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* tail = (*head)->prev; // Get last node
        tail->next = newNode;
        newNode->prev = tail;
        newNode->next = *head;
        (*head)->prev = newNode;
    }
}

// Insert at the beginning
void insertBegin(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* tail = (*head)->prev;
        newNode->next = *head;
        newNode->prev = tail;
        tail->next = newNode;
        (*head)->prev = newNode;
        *head = newNode; // Update head
    }
}

// Delete a node with a given value
void deleteNode(struct Node** head, int key) {
    if (*head == NULL) return;

    struct Node *curr = *head, *prevNode = NULL;

    // Search for the node with the given key
    do {
        if (curr->data == key) {
            if (curr == *head) { // Node to be deleted is head
                if ((*head)->next == *head) { // Only one node
                    free(*head);
                    *head = NULL;
                    return;
                }
                struct Node* tail = (*head)->prev;
                *head = (*head)->next;
                tail->next = *head;
                (*head)->prev = tail;
                free(curr);
                return;
            } else { // Deleting non-head node
                prevNode->next = curr->next;
                curr->next->prev = prevNode;
                free(curr);
                return;
            }
        }
        prevNode = curr;
        curr = curr->next;
    } while (curr != *head);
}


int main(){
   
    return 0;
}