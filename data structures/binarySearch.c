#include<stdio.h>

int binarySearch(int arr[], int size, int element){
    int low, mid, high;
    low = 0;
    high = size-1;
    while(low<=high){
        mid = (high+low)/2;
        if (arr[mid] == element)
        {
            return mid;
        }
        if (arr[mid]<element)
        {
            low = mid+1;
        }
        else{
            high = mid-1;
        } 
    }
    return -1;
}

int main(){
    // Sorted array for linear search
    int arr[] = {1,3,5,7,8,54,134,167,245,312,489};
    int size = sizeof(arr)/sizeof(int);
    int element = 134;
    int searchIndex = binarySearch(arr, size, element);
    if (searchIndex == -1){
        printf("The element was not found...");
    }
    else{
        printf("The element %d was found at index %d \n", element, searchIndex);
    }
    return 0;
}