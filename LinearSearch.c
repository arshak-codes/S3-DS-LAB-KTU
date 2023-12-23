//CSL201 DATA STRUCTURES LAB ----- ARSHAK MUHAMMED P K, R3A, 72
//Linear Search

#include <stdio.h>

int LinearSearch(int arr[],int size,int num){
    for(int i=0;i<size;i++){
        if(arr[i]==num){
            return i;//if item found->return index 
        }
    }
    return -1;
}

int main(){
    int arr[10];//max 10
    int num,size;

    printf("Enter number of elements:");
    scanf("%d",&size);

    for(int i=0;i<size;i++){
    printf("\nEnter %dth number: ",i+1);
    scanf("%d",&arr[i]);
    }

    printf("\nEnter the number to search: ");
    scanf("%d",&num);

    int index = LinearSearch(arr,size,num);

    if(index==-1){
        printf("\nElement not found!");
    }
    else{
        printf("\nElement found at index %d",index);
    }

    return 0;
}