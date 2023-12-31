 //CSL201 DATA STRUCTURES LAB ----- ARSHAK MUHAMMED P K, R3A, 72,TKMCE
 //Polynomial addition using array

 //qn)Write a program to read two polynomials and store them in an array. Calculate the sum of the two 
// polynomials and display the first polynomial, second polynomial and the resultant polynomial.

#include <stdio.h>

#define MAX 100

// Function to add two polynomials
// Time Complexity: O(N), where N is the maximum degree of the two polynomials
void addpoly(int poly1[], int poly2[], int size1, int size2) {
    int resultantpoly[MAX] = {0};  // Initialize entire array to zero

    // Loop through each term of the polynomials and add them
    for (int i = (size1 > size2) ? size1 : size2; i >= 0; i--) {
        resultantpoly[i] = poly1[i] + poly2[i];
    }

    // Print the original polynomials
    printf("Polynomial 1: ");
    for (int i = size1; i >= 0; i--) {
        printf("%dx^%d ", poly1[i], i);
        if (i > 0) {
            printf("+ ");
        }
    }
    printf("\n");

    printf("Polynomial 2: ");
    for (int i = size2; i >= 0; i--) {
        printf("%dx^%d ", poly2[i], i);
        if (i > 0) {
            printf("+ ");
        }
    }
    printf("\n");

    // Print the resultant polynomial
    printf("Resultant Polynomial: ");
    for (int i = (size1 > size2) ? size1 : size2; i >= 0; i--) {
        printf("%dx^%d ", resultantpoly[i], i);
        if (i > 0) {
            printf("+ ");
        }
    }
    printf("\n");
}

int main() {
    int poly1[MAX] = {0};  // Initialize entire array to zero
    int poly2[MAX] = {0};  // Initialize entire array to zero
    int size1, size2;

    // Input for the first polynomial
    printf("Enter the degree of the first polynomial: ");
    scanf("%d", &size1);

    // Input coefficients for the first polynomial
    for (int i = size1; i >= 0; i--) {
        printf("Enter coefficient of x^%d: ", i);
        scanf("%d", &poly1[i]);
    }

    // Input for the second polynomial
    printf("Enter the degree of the second polynomial: ");
    scanf("%d", &size2);

    // Input coefficients for the second polynomial
    for (int i = size2; i >= 0; i--) {
        printf("Enter coefficient of x^%d: ", i);
        scanf("%d", &poly2[i]);
    }

    // Call the addpoly function to add the two polynomials
    addpoly(poly1, poly2, size1, size2);

    return 0;
}

