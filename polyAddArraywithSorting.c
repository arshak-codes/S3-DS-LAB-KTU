//CSL201 DATA STRUCTURES LAB ----- ARSHAK MUHAMMED P K, R3A, 72
//Write a program to read two polynomials and store them in an array. 
//Calculate the sum of the two polynomials and display the first polynomial, 
//second polynomial and the resultant polynomial.

#include <stdio.h>
typedef struct node {
    int coef;
    int expo;
} poly;

// Bubble sort algorithm to sort polynomial terms based on exponent values
void sortpoly(poly a[], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (a[j].expo < a[j + 1].expo) {
                poly temp = a[j + 1];
                a[j + 1] = a[j];
                a[j] = temp;
            }
        }
    }
}

// Function to add two polynomials and display the result
void addpoly(poly a[], poly b[], int size1, int size2) {
    poly respoly[100] = {0}; // Resultant polynomial

    int i = 0, j = 0, k = 0;

    while (i < size1 && j < size2) {
        if (a[i].expo > b[j].expo) {
            respoly[k++] = a[i++];
        } else if (a[i].expo < b[j].expo) {
            respoly[k++] = b[j++];
        } else {
            respoly[k].expo = a[i].expo;
            respoly[k++].coef = a[i++].coef + b[j++].coef;
        }
    }

    while (i < size1) {
        respoly[k++] = a[i++];
    }

    while (j < size2) {
        respoly[k++] = b[j++];
    }

    // Displaying the first polynomial
    printf("***First Polynomial***\n");
    for (int i = 0; i < size1; i++) {
        printf("%dx^%d ", a[i].coef, a[i].expo);
        if (i < size1 - 1) {
            printf("+ ");
        }
    }
    printf("\n");

    // Displaying the second polynomial
    printf("***Second Polynomial***\n");
    for (int i = 0; i < size2; i++) {
        printf("%dx^%d ", b[i].coef, b[i].expo);
        if (i < size2 - 1) {
            printf("+ ");
        }
    }
    printf("\n");

    // Displaying the resultant polynomial
    printf("***Resultant Polynomial***\n");
    for (int i = 0; i < k; i++) {
        printf("%dx^%d ", respoly[i].coef, respoly[i].expo);
        if (i < k - 1) {
            printf("+ ");
        }
    }
    printf("\n");
}

int main() {
    poly a[100] = {0}, b[100] = {0}; // Arrays to store two polynomials

    int size1, size2;
    printf("***First Polynomial***\n");
    printf("Enter number of terms: ");
    scanf("%d", &size1);

    // Input for the first polynomial
    for (int i = 0; i < size1; i++) {
        printf("Enter the coeff: ");
        scanf("%d", &a[i].coef);
        printf("Enter the exponent: ");
        scanf("%d", &a[i].expo);
    }

    printf("***\nSecond Polynomial***\n");
    printf("Enter number of terms: ");
    scanf("%d", &size2);

    // Input for the second polynomial
    for (int i = 0; i < size2; i++) {
        printf("Enter the coeff: ");
        scanf("%d", &b[i].coef);
        printf("Enter the exponent: ");
        scanf("%d", &b[i].expo);
    }

    // Sorting both polynomials based on exponents
    sortpoly(a, size1);
    sortpoly(b, size2);

    // Adding and displaying the polynomials
    addpoly(a, b, size1, size2);

    return 0;
}

//ALGORITHM

// 1. **`typedef struct node`**: Defines a structure named `poly` to represent a term in a polynomial.

// 2. **`sortpoly` function**: Takes an array of polynomial terms and sorts them in descending order based on the exponent values using the bubble sort algorithm.

// 3. **`addpoly` function**: Takes two arrays representing polynomials (`a` and `b`), their sizes (`size1` and `size2`),
//  and adds them to create a new polynomial (`respoly`). It prints the first polynomial, second polynomial, and the resulting polynomial.

// 4. **`main` function**:
//    - Declares arrays `a` and `b` to store two polynomials.
//    - Takes input for the first and second polynomials, including the number of terms, coefficient, and exponent for each term.
//    - Calls `sortpoly` for both polynomials to ensure they are sorted in descending order based on exponents.
//    - Calls `addpoly` to add the