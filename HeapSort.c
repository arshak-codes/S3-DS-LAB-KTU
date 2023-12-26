//CSL201 DATA STRUCTURES LAB ----- ARSHAK MUHAMMED P K, R3A, 72
//Heap Sort

#include <stdio.h>

//heapify method
void heapify(int arr[],int n,int i){
    int largest = i;
    int left = 2*i+1;
    int right = 2*i+2;

    if(left<n && arr[left]>arr[largest]){
        largest = left;
    }
    if(right<n && arr[right]>arr[largest]){
        largest = right;
    }
    if (largest!=i){
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        heapify(arr,n,largest);
    }

}

//build max heap method

void buildmaxheap(int arr[],int n){
    for(int i = (n/2)-1;i>=0;i--){
        heapify(arr,n,i);
    }

}

//heapsort meathod

void heapsort(int arr[],int n){
    buildmaxheap(arr,n);
    for(int i = n-1;i>=1;i--){//extract elements from heap one by one
        int temp = arr[0];//moving current root to the end of array
        arr[0] = arr[i];
        arr[i] = temp;
        heapify(arr,i,0);//heapify the reduced heap
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
    printf("****HEAP SORTING****\n");
    
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
    heapsort(arr,n);
    display(arr, n);

    return 0;
}