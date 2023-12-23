//CSL201 DATA STRUCTURES LAB ----- ARSHAK MUHAMMED P K, R3A, 72
//Binary Search(sorted input)

#include <stdio.h>

int BinarySearch(int arr[],int size,int num){
    int low=0;
    int high=size-1;
    int mid =(low+high)/2;

    while(low<=high){
        if(num>arr[mid]){
            low=mid+1;
        }

        else if(num<arr[mid]){
            high = mid-1;
        }

        else {return mid;}

        mid = (low + high) / 2;
    }

    return -1;

}

int main(){
    int arr[10];
    int num,size;

    printf("Enter number of elements:");
    scanf("%d",&size);

    printf("\nEnter elements in sorted order:");
    for(int i=0;i<size;i++){
        printf("\nEnter %dth num: ",i+1);
        scanf("%d",&arr[i]);
    }

    printf("\nEnter the num to be find:");
    scanf("%d",&num);

    int index = BinarySearch(arr,size,num);

    if(index==-1){
        printf("\nElement Not Found!");
    }

    else{
        printf("\nElement found in %dth position",index+1);
    }
    return 0;
}