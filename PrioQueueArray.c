//ARSHAK MUHAMMED R3A 72 TKMCE
// Implement a priority queue using arrays with the operations:
// ●Insert elements to the priority queue.
// ●Delete elements from the priority queue.
// ●Display the contents of the priority queue
#include <stdio.h>
#include <stdlib.h>
#define MAX 10

int front = -1, rear = -1;

// Function to check priority and insert the element accordingly
void check_priority(int q[], int item) {
    int i, j;
    for (i = 0; i <= rear; i++) {
        if (item >= q[i]) {
            // Shift elements to make space for the new element
            for (j = rear + 1; j > i; j--) {
                q[j] = q[j - 1];
            }
            // Insert the new element at the correct position
            q[i] = item;
            return;
        }
    }
    // If the new element has the lowest priority, insert it at the end
    q[i] = item;
}

// Function to enqueue (insert) an element into the priority queue
void enqueue(int q[], int item) {
    // If the queue is empty, initialize front and rear
    if (front == -1) {
        front = rear = 0;
        q[rear] = item;
        printf("%d inserted\n", item);
    } 
    // If the queue is full, print an error message
    else if (rear == MAX - 1) {
        printf("Queue is full\n");
    } 
    // If the queue has elements, insert the element based on priority
    else {
        check_priority(q, item);
        printf("%d inserted\n", item);
        rear++;
    }
}

// Function to dequeue (delete) an element from the priority queue
void dequeue(int q[], int item) {
    // If the queue is empty, print an error message
    if (front == -1) {
        printf("Queue is empty\n");
        return;
    }
    int i;
    // Find the position of the element to be deleted
    for (i = 0; i <= rear; i++) {
        if (item == q[i]) {
            break;
        }
    }
    // If the element is not found, print an error message
    if (i > rear) {
        printf("Item not found\n");
        return;
    }
    // Shift elements to fill the gap created by deleting the element
    for (; i < rear; i++) {
        q[i] = q[i + 1];
    }
    // Update rear and front if necessary
    rear--;
    if (rear == -1) {
        front = -1;
    }
    printf("%d deleted\n", item);
}

// Function to display the contents of the priority queue
void display(int q[]) {
    // If the queue is empty, print an error message
    if (front == -1) {
        printf("Queue is empty\n");
        return;
    }
    int i;
    printf("Priority Queue contents: ");
    // Display the contents of the priority queue
    for (i = front; i <= rear; i++) {
        printf("%d ", q[i]);
    }
    printf("\n");
}

// Main function to interact with the user and execute priority queue operations
void main() {
    int q[MAX];
    int n, choice;

    // Menu-driven program
    printf("\nEnter 1 to insert element by priority ");
    printf("\nEnter 2 to delete element by priority ");
    printf("\nEnter 3 to display priority queue ");
    printf("\nEnter 4 to exit");

    while (1) {
        printf("\nEnter your choice : ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nEnter element to insert : ");
                scanf("%d", &n);
                enqueue(q, n);
                break;
            case 2:
                printf("\nEnter element to delete : ");
                scanf("%d", &n);
                dequeue(q, n);
                break;
            case 3:
                display(q);
                break;
            case 4:
                exit(0);
            default:
                printf("\nPlease enter a valid choice");
        }
    }
}
