//CSL201 DATA STRUCTURES LAB ----- ARSHAK MUHAMMED P K, R3A, 72,TKMCE
//Doubly Linked List

// Write a menu driven program for performing the following operations on a Linked List:
// 1.Display
// 2.Insert at Beginning
// 3.Insert at End
// 4.Insert at a specified Position
// 5.Delete from a specified Position

#include <stdio.h>
#include <stdlib.h>

typedef struct doubly{
    int data;
    struct doubly *left;
    struct doubly *right;
}node;

node *head,*c,*newnode;

// Function to display the elements of the doubly linked list
// Input: Pointer to the head of the linked list
// Time Complexity: O(n), where n is the number of elements in the list
void display(node *head) {
    // Initialize a temporary pointer 'c' to the head of the list
    c = head;

    // Traverse the list and print each element
    while (c != NULL) {
        printf("%d->", c->data);
        c = c->right;  // Move to the next node on the right
    }

    // Print "NULL" to signify the end of the list
    printf("NULL\n");
}

// Function to insert a new node at the beginning of the doubly linked list
// Allocates memory for a new node, sets its data, and adjusts pointers
// Input: None (Uses global variables 'head', 'c', and 'newnode')
// Time Complexity: O(1)
void insertbeg() {
    // Allocate memory for the new node
    newnode = (node*)malloc(sizeof(node));
    newnode->left = NULL;
    newnode->right = NULL;

    // Get user input for data
    printf("Enter data: ");
    scanf("%d", &newnode->data);

    // Check if the list is empty
    if (head == NULL) {
        head = c = newnode;  // Set 'head' and 'c' to the new node
    } else {
        // Adjust pointers to insert the new node at the beginning
        newnode->right = head;
        head->left = newnode;
        head = newnode;
    }

    // Print a message indicating the successful insertion
    printf("\n%d inserted!", newnode->data);
}

// Function to insert a new node at the end of the doubly linked list
// Allocates memory for a new node, sets its data, and adjusts pointers
// Input: None (Uses global variables 'head', 'c', and 'newnode')
// Time Complexity: O(n), where n is the number of elements in the list
void insertend() {
    // Allocate memory for the new node
    newnode = (node*)malloc(sizeof(node));
    newnode->left = NULL;
    newnode->right = NULL;

    // Get user input for data
    printf("\nData to be inserted at the end: ");
    scanf("%d", &newnode->data);

    // Check if the list is empty
    if (head == NULL) {
        head = c = newnode;  // Set 'head' and 'c' to the new node
    } else {
        // Traverse the list to the end
        c = head;
        while (c->right != NULL) {
            c = c->right;
        }

        // Adjust pointers to insert the new node at the end
        c->right = newnode;
        newnode->left = c;
        c = c->right;
        
        // Print a message indicating the successful insertion
        printf("%d Inserted!", newnode->data);
    }
}

// Function to insert a new node at a specified position in the doubly linked list
// Allocates memory for a new node, sets its data, and adjusts pointers
// Input: None (Uses global variables 'head', 'c', 'newnode', and 'count')
// Time Complexity: O(n), where n is the number of elements in the list
void insertpos() {
     int pos, count;
    node *prev;
    // Allocate memory for the new node
    newnode = (node*)malloc(sizeof(node));
    newnode->left = NULL;
    newnode->right = NULL;

    // Get position and data from the user
    printf("\nEnter the position: ");
    scanf("%d", &pos);
    printf("\nEnter data: ");
    scanf("%d", &newnode->data);

    // Check if the insertion is at the beginning
    if (pos == 1) {
        newnode->right = head;
        head->left = newnode;
        head = newnode;
    } else {
        // Initialize counters and pointers
        count = 1;
        c = head;

        // Traverse the list to the specified position
        while (c != NULL && count < pos) {
            prev = c;
            c = c->right;
            count++;
        }

        // Insert the new node at the specified position
        newnode->right = c;
        c->left = newnode;
        prev->right = newnode;
        newnode->left = prev;
        printf("%d inserted at position %d", newnode->data, pos);
    }
}

// Function to delete a node from a specified position in the doubly linked list
// Frees memory occupied by the deleted node and adjusts pointers
// Input: None (Uses global variables 'head', 'c', 'p', 'count', and 'pos')
// Time Complexity: O(n), where n is the number of elements in the list
void deletepos() {
    int pos;
    int ch = 1;
    node *p = NULL;
    int count = 1;

    // Get the position to be deleted from the user
    printf("\nEnter the position to be deleted: ");
    scanf("%d", &pos);

    // Initialize pointers for traversal
    p = c = head;

    // Check if the node to be deleted is the first node
    if (pos == 1) {
        printf("\n%d deleted!", head->data);
        head = head->right;
        head->left = NULL;
        free(c);
    } else {
        // Traverse the list to the specified position
        while (c != NULL && count < pos) {
            p = c;
            c = c->right;
            count++;
        }

        // Check if the position is valid
        if (c == NULL) {
            printf("\nPosition not found. List may be shorter than specified position.");
        } else {
            // Delete the node at the specified position
            printf("\n%d deleted!", c->data);
            p->right = c->right;
            c->right->left = p;
            c->left = NULL;
            c->right = NULL;
            free(c);
        }
    }
}


int main() {
    int choice;
    while (1) {
        // Display the menu
        printf("\n***Doubly Linked List Operations Menu:***\n");
        printf("1. Display\n");
        printf("2. Insert at Beginning\n");
        printf("3. Insert at End\n");
        printf("4. Insert at a specified Position\n");
        printf("5. Delete from a specified Position\n");
        printf("6. Exit\n");

        // Get the user's choice
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Perform the chosen operation
        switch (choice) {
            case 1:
                // Display
                display(head);
                break;
            case 2:
                // Insert at Beginning
                insertbeg();
                break;
             case 3:
                // Insert at End
                 insertend();
                 break;
             case 4:
                 // Insert at a specified Position
                 insertpos();
                 break;
             case 5:
                // Delete from a specified Position
              deletepos();
               break;
            case 6:
                // Exit the program
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    }

    return 0;
}
