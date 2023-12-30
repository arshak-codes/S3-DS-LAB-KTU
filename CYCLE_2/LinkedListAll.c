//CSL201 DATA STRUCTURES LAB ----- ARSHAK MUHAMMED P K, R3A, 72,TKMCE
//Linked List

// Write a menu driven program for performing the following operations on a Linked List:
// 1.Display
// 2.Insert at Beginning
// 3.Insert at End
// 4.Insert at a specified Position
// 5.Delete from Beginning
// 6.Delete from End
// 7.Delete from a specified Position

#include <stdio.h>
#include <stdlib.h>

typedef struct LinkedList
{
    int data;
    struct LinkedList *next;
}node;

node *head=NULL,*c,*newnode;//global declaration of necessary pointers

void createlist(){//linked list creation function
    int choice = 1;
    while(choice){
        newnode = (node*)malloc(sizeof(node));
        newnode->next=NULL;
        printf("Enter data: ");
        scanf("%d",&newnode->data);
        if(head==NULL){
            head=c=newnode;
        }
        else{
            c->next = newnode;
            c = c->next;
        }
        printf("\nAdd more? ");
        scanf("%d",&choice);
    }
}

void display(node *head){//display function
    c=head;
    while(c!=NULL){
    printf("%d->",c->data);
    c = c->next;
    }
    printf("NULL\n");
}

// Function to insert a node at the beginning of a linked list
void insertbeg() {
    // Allocate memory for the new node
    newnode = (node*)malloc(sizeof(node));
    newnode->next = NULL;

    // Get data from the user
    printf("\nData to insert at the front: ");
    scanf("%d", &newnode->data);

    // Store the current head in a temporary pointer
    node *temp = head;

    // Check if the list is empty
    if (head == NULL) {
        // If the list is empty, make the new node the head
        head = c = newnode;
    } else {
        // If the list is not empty, insert the new node at the beginning
        newnode->next = head;
        head = newnode;
    }

    // Display the linked list before insertion
    printf("\nBefore Inserting:");
    display(temp);

    // Display the linked list after insertion
    printf("\nAfter Inserting:");
    display(head);
}

void insertend(){
    newnode = (node*)malloc(sizeof(node));
    newnode->next = NULL;
    printf("\nData to insert at tail: ");
    scanf("%d",&newnode->data);
    node *temp=head;//to store old head
    printf("\nBefore Inserting:");
    display(temp);
    if(head==NULL){
        head=c=newnode;
    }
    else{
        c=head;
        while(c->next!=NULL){
            c=c->next;
        }
        c->next = newnode;
        c = c->next;
    }
    printf("\nAfter Inserting:");
    display(head);
}

// Function to insert a node at a specified position in a linked list
void insertpos() {
    int pos, count;
    node *prev;

    // Allocate memory for the new node
    newnode = (node*)malloc(sizeof(node));
    newnode->next = NULL;

    // Get position and data from the user
    printf("\nEnter the position: ");
    scanf("%d", &pos);
    printf("\nEnter data: ");
    scanf("%d", &newnode->data);

    // Store the current head in a temporary pointer
    node *temp = head;

    // Display the linked list before insertion
    printf("\nBefore Inserting:");
    display(temp);

    // Check if the insertion is at the beginning
    if (pos == 1) {
        newnode->next = head;
        head = newnode;
    } else {
        // Initialize counters and pointers
        count = 1;
        c = head;

        // Traverse the list to the specified position
        while (c != NULL && count < pos) {
            prev = c;
            c = c->next;
            count++;
        }

        // Insert the new node at the specified position
        newnode->next = c;
        prev->next = newnode;
    }

    // Display the linked list after insertion
    printf("\nAfter Inserting:");
    display(head);
}

// Function to delete the first node of a linked list
void deletebeg() {
    int ch = 1;

    // Continue deletion until the user decides to stop
    while (ch) {
        // Check if the list is empty
        if (head == NULL) {
            printf("\nNothing to delete.");
            break;  // Exit the loop if the list is empty
        } else {
            // Initialize a temporary pointer for the first node
            c = head;

            // Display the data of the first node before deletion
            printf("\n%d deleted!", head->data);

            // Move the head to the next node
            head = head->next;

            // Free the memory of the deleted first node
            free(c);
        }

        // Display the linked list after deletion
        display(head);

        // Ask the user if they want to perform more deletions
        printf("\nMore? (1 for yes, 0 for no): ");
        scanf("%d", &ch);
    }
}

// Function to delete the last node of a linked list
void deleteend() {
    int ch = 1;
    node *p = NULL;

    // Continue deletion until the user decides to stop
    while (ch) {
        // Check if the list is empty
        if (head == NULL) {
            printf("\nNothing to delete.");
            break;  // Exit the loop if the list is empty
        } else {
            // Initialize pointers for traversal
            c = p = head;

            // Traverse the list to the last node
            while (c->next != NULL) {
                p = c;
                c = c->next;
            }

            // Display the data of the last node before deletion
            printf("\n%d deleted!", c->data);

            // Check if there is only one node in the list
            if (p == c) {
                head = NULL;
            } else {
                // Update the previous node's next pointer
                p->next = NULL;
            }

            // Free the memory of the deleted node
            free(c);
        }

        // Display the linked list after deletion
        display(head);

        // Ask the user if they want to perform more deletions
        printf("\nMore? (1 for yes, 0 for no): ");
        scanf("%d", &ch);
    }
}

// Function to delete a node at a specified position in a linked list
void deletepos() {
    int pos;
    int ch = 1;
    node *p = NULL;

    while (ch) {
        int count = 1;

        // Get the position to be deleted from the user
        printf("\nEnter the position to be deleted: ");
        scanf("%d", &pos);

        // Initialize pointers for traversal
        p = c = head;

        // Check if the node to be deleted is the first node
        if (pos == 1) {
            printf("\n%d deleted!", head->data);
            head = head->next;
            free(c);
        } else {
            // Traverse the list to the specified position
            while (c != NULL && count < pos) {
                p = c;
                c = c->next;
                count++;
            }

            // Check if the position is valid
            if (c == NULL) {
                printf("\nPosition not found. List may be shorter than specified position.");
            } else {
                // Delete the node at the specified position
                printf("\n%d deleted!", c->data);
                p->next = c->next;
                c->next = NULL;
                free(c);
            }
        }

        // Display the linked list after deletion
        printf("After Deletion: ");
        display(head);

        // Ask the user if they want to perform more deletions
        printf("\nMore? (1 for yes, 0 for no): ");
        scanf("%d", &ch);
    }
}

//main method
int main() {
    int choice;
    while (1) {
        // Display the menu
        printf("\n***Linked List Operations Menu:***\n");
        printf("1. Display\n");
        printf("2. Insert at Beginning\n");
        printf("3. Insert at End\n");
        printf("4. Insert at a specified Position\n");
        printf("5. Delete from Beginning\n");
        printf("6. Delete from End\n");
        printf("7. Delete from a specified Position\n");
        printf("8. Exit\n");

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
                // Delete from Beginning
                deletebeg();
                break;
            case 6:
                // Delete from End
                deleteend();
                break;
            case 7:
                // Delete from a specified Position
                deletepos();
                break;
            case 8:
                // Exit the program
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    }

    return 0;
}

