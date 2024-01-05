//CSL201 DATA STRUCTURES LAB ----- ARSHAK MUHAMMED P K, R3A, 72
// Queue using array
// Implement a queue using arrays with the operations:
// ● Insert elements in the queue.
// ● Delete elements from the queue.
// ● Display the contents of the queue after each operation.

#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int front = -1, rear = -1;

// Function to enqueue (insert) an element into the queue
void enque(int item, int q[]) {
    if (front == -1 && rear == -1) {
        // Queue is empty, set front and rear to 0
        front = rear = 0;
        q[rear] = item;
        printf("%d is enqueued!\n", item);
        rear++;
    } else if (rear == MAX - 1) {
        // Queue is full
        printf("Queue is full!\n");
    } else {
        // Queue has space, insert the element at the rear
        q[rear] = item;
        printf("%d is enqueued!\n", item);
        rear++;
    }
}

// Function to dequeue (delete) an element from the queue
void deque(int q[]) {
    if (front == -1) {
        // Queue is empty, nothing to dequeue
        printf("Queue is empty: Nothing to delete here buddy!\n");
    } else if (front == rear) {
        // Only one element in the queue
        printf("%d dequeued!\n", q[front]);
        front = rear = -1;
    } else {
        // Remove the front element from the queue
        printf("%d dequeued!\n", q[front]);
        front++;
    }
}

// Function to display the contents of the queue
void display(int q[]) {
    if (front == -1) {
        // Queue is empty
        printf("Queue is empty\n");
    } else {
        // Display the contents of the queue
        int i;
        printf("Queue contents: ");
        for (i = front; i < rear; i++) {
            printf("%d ", q[i]);
        }
        printf("\n");
    }
}

int main() {
    int q[MAX];
    int d, ch;

    while (1) {
        // Menu-driven program
        printf("MENU\n");
        printf("1. Enqueue\n2. Dequeue\n3. Display Queue\n4. Exit\nEnter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
        case 1:
            // Enqueue operation
            printf("Enter data: ");
            scanf("%d", &d);
            enque(d, q);
            break;
        case 2:
            // Dequeue operation
            deque(q);
            break;
        case 3:
            // Display operation
            display(q);
            break;
        case 4:
            // Exit program
            printf("Exiting program\n");
            exit(0);
        default:
            // Invalid choice
            printf("Invalid choice\n");
            break;
        }
    }

    return 0;
}
