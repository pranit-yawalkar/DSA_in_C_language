#include<stdio.h>

// Time Complexity: Worst Case-> O(n^2)
//                  Best Case-> O(nlogn) 
int swap(int arr[], int i, int j){
    int tmp = arr[i];
    arr[i] = arr[j];
    arr[j] = tmp;
    
}

int partition(int arr[], int low, int high){
    int pivot = arr[low];
    int i = low;
    // int i = low+1;  // if do while loop is used
    int j = high;
    // do{
    //     while(arr[i]<=pivot)
    //         i++;
    //     while(arr[j]>pivot)
    //         j--;
    //     if(i<j)
    //         swap(arr, i, j);
    // }while(i<j);    
    while(i<j){
        while(arr[i]<=pivot)
            i++;
        while(arr[j]>pivot)
            j--;
        if(i<j)
            swap(arr, i, j);
    }   
    swap(arr, low, j);
    return j;
}

void quickSort(int arr[], int low, int high){ // divide and conquer
    if(low<high){
        int partitionIndex = partition(arr, low, high);
        quickSort(arr, low, partitionIndex-1);
        quickSort(arr, partitionIndex+1, high);
    }
}

int main(){
    // int arr[] = {10,5,2,8,3,5,6,9};
    // int arr[] = {1,3,5,6,8,9}; // worst case    
    // int arr[] = {100, 24, 32, 23, 67, 55, 24, 89, 14, 1, 3, 5};
    int arr[] = {95, 25, 12, 45, 71, 2, 3, 1, 15, 18, 3, 5};

    int n = 12;
    quickSort(arr, 0, n-1);
    for(int i=0;i<n;i++){
        printf("%d ", arr[i]);
    }
    return 0;
}