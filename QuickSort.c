//CSL201 DATA STRUCTURES LAB ----- ARSHAK MUHAMMED P K, R3A, 72
//Quick Sort

#include <stdio.h>

int partition(int arr[], int low, int high) {
    int pivot = arr[low];
    int leftwall = low;

    for (int i = low + 1; i <= high; i++) {
        if (arr[i] < pivot) {
            leftwall++;
            int temp = arr[i]; // Swap
            arr[i] = arr[leftwall];
            arr[leftwall] = temp;
        }
    }
    int temp = arr[leftwall]; // Swap
    arr[leftwall] = pivot;
    arr[low] = temp; 

    return leftwall;
}


void qsort(int arr[], int low, int high) {
    if (low < high) {
        int pivot_location = partition(arr, low, high);
        qsort(arr, low, pivot_location);
        qsort(arr, pivot_location + 1, high);
    }
}

void display(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n, arr[100];
    printf("****QUICK SORTING****\n");
    
    // User input with error checking
    printf("Enter number of elements (max 100): ");
    scanf("%d", &n);
    
    if (n > 100 || n <= 0) {
        printf("Invalid number of elements. Exiting.\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        printf("\nEnter %dth element: ", i + 1);
        scanf("%d", &arr[i]);
    }

    printf("\nBefore Sorting:");
    display(arr, n);
    printf("\nAfter Sorting:");
    qsort(arr, 0, n - 1);
    display(arr, n);

    return 0;
}
