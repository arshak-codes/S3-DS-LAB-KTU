//CSL201 DATA STRUCTURES LAB ----- ARSHAK MUHAMMED P K, R3A, 72
//SELECTION SORT

#include <stdio.h>

void sort(int arr[],int n){
    for(int j=0;j<n-1;j++){
        int min = j;
        for(int i=j+1;i<n;i++){
        if(arr[i]<arr[min]){
            min = i;
        }
        }

        if(min!=j){
        int temp = arr[min];
        arr[min] = arr[j];
        arr[j] = temp;
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
    printf("****SELECTION SORTING****\n");
    printf("Enter number of elements: ");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("\nEnter %dth elem: ",i+1);
        scanf("%d",&arr[i]);
    }

    printf("\nBefore Sorting:");
    display(arr,n);
    printf("\nAfter Sorting:");
    sort(arr,n);
    display(arr,n);
return 0;
}