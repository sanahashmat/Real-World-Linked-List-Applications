#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the linked list
struct Node {
    int data;          // Data field to store the value
    struct Node* next; // Pointer to the next node
};

// Global pointer to the top of the stack, initialized to NULL for an empty stack
struct Node* top = NULL;

// Function to check if the stack is empty
int isEmpty() {
    return top == NULL;
}

// Function to push an element onto the stack
void push(int value) {
    // Allocate memory for a new node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Stack Overflow! Memory allocation failed.\n");
        return;
    }
    // Assign data to the new node
    newNode->data = value;
    // Link the new node to the current top of the stack
    newNode->next = top;
    // Update the top pointer to the new node
    top = newNode;
    printf("%d pushed to stack.\n", value);
}

// Function to pop an element from the stack
void pop() {
    if (isEmpty()) {
        printf("Stack Underflow! Cannot pop from an empty stack.\n");
        return;
    }
    // Temporary pointer to hold the top node to be freed
    struct Node* temp = top;
    // Store the value of the top element
    int poppedValue = temp->data;
    // Move the top pointer to the next node
    top = top->next;
    // Free the memory of the original top node
    free(temp);
    printf("%d popped from stack.\n", poppedValue);
}

// Function to peek at the top element of the stack
void peek() {
    if (isEmpty()) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Top element is %d.\n", top->data);
}

// Function to display all elements in the stack
void display() {
    if (isEmpty()) {
        printf("Stack is empty.\n");
        return;
    }
    struct Node* temp = top;
    printf("Stack elements: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Main function to demonstrate stack operations
int main() {
    push(10);
    push(20);
    push(30);
    display();
    peek();
    pop();
    display();
    pop();
    pop();
    pop(); // Attempting to pop from an empty stack

    return 0;
}
