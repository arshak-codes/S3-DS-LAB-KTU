//CSL201 DATA STRUCTURES LAB ----- ARSHAK MUHAMMED P K, R3A, 72
//Insertion Sort

#include <stdio.h>

void isort(int arr[],int n){
    for(int i=1;i<n;i++){
        int j = i;
            while(j>0 && arr[j-1]>arr[j]){
                int temp = arr[j-1];
                arr[j-1] = arr[j];
                arr[j] = temp;
                j=j-1;
            }
    }
}

void display(int arr[],int n){
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
}


int main(){
    int n,arr[10];
    printf("****INSERTION SORTING****\n");
    printf("Enter number of elements: ");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("\nEnter %dth elem: ",i+1);
        scanf("%d",&arr[i]);
    }

    printf("\nBefore Sorting:");
    display(arr,n);
    printf("\nAfter Sorting:");
    isort(arr,n);
    display(arr,n);
return 0;
}

//Time comp O(n^2)

//Explanation of the code
/*
1.It starts from the second element (i=1) and iterates through the array.
2.For each element at index i, 
it compares it with the elements in the sorted part of the array (elements before i).
3. If the element at index j-1 is greater than the element at index j, 
it swaps them until the correct position is found.
4.It continues this process until the entire array is sorted.
*/