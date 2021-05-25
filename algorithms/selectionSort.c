#include<stdio.h>

// Time Complexity = O(n^2)
void swap(int arr[], int* a, int* b){
    int temp = *a;
    *a=*b;
    *b=temp;
}

void selectionSort(int arr[], int n){
    for(int i=0;i<n-1;i++){
        int minIndex=i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[minIndex]){
                minIndex=j;
            }
        }
        swap(arr, &arr[i], &arr[minIndex]);
    }
}

int main(){
    int n;
    scanf("%d", &n);
    int arr[100];
    for(int i=0;i<n;i++){
        scanf("%d", &arr[i]);
    }
    
    selectionSort(arr, n);
    for(int i=0;i<n;i++){
        printf("%d ", arr[i]);
    }printf("\n");
    return 0;
}