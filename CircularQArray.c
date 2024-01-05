//CSL201 DATA STRUCTURES LAB ----- ARSHAK MUHAMMED P K, R3A, 72

// Implement a circular queue using arrays with the operations:
// ●Insert an element to the queue.
// ●Delete an element from the queue.
// ●Display the contents of the queue after each operation.

#include <stdio.h>
#include <stdlib.h>
#define MAX 10
int front = -1, rear = -1;
int nxt_posn;

// Function to enqueue (insert) an element into the circular queue
void enqueue(int item, int q[]) {
    int nxt_posn = (rear + 1) % MAX;
    if (front == nxt_posn) {
        // Circular queue is full
        printf("Queue is FULL!\n");
    } else {
        if (front == -1) {
            // Queue is empty, set front and rear to 0
            front = rear = 0;
        } else {
            // Queue has space, insert the element at the next position in a circular manner
            rear = nxt_posn;
        }
        q[rear] = item;
        printf("%d enqueued!\n", item);
    }
}

// Function to dequeue (delete) an element from the circular queue
void dequeue(int q[]) {
    if (front == -1) {
        // Queue is empty
        printf("Queue is empty!\n");
    } else if (front == rear) {
        // Only one element in the queue
        printf("%d is dequeued\n", q[front]);
        front = rear = -1;
    } else {
        // Remove the front element from the queue
        nxt_posn = (front + 1) % MAX;
        printf("%d is dequeued\n", q[front]);
        front = nxt_posn;
    }
}

// Function to display the contents of the circular queue
void display(int q[]) {
    if (front == -1) {
        // Queue is empty
        printf("Queue is empty\n");
    } else {
        // Display the contents of the circular queue
        nxt_posn = front;
        printf("Queue contents: ");
        while (nxt_posn != rear) {
            printf("%d ", q[nxt_posn]);
            nxt_posn = (nxt_posn + 1) % MAX;
        }
        printf("%d\n", q[rear]);  // Display the last element
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
            enqueue(d, q);
            break;
        case 2:
            // Dequeue operation
            dequeue(q);
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
