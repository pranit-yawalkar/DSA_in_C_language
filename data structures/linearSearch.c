#include<stdio.h>

int linearSearch(int arr[], int size, int element){
    for (int i = 0; i < size; i++)
    {
        if(arr[i] == element){
            return i;
        }
    }
    return -1;
}

int main(){
    // Unsorted array for linear search
    int arr[] = {1,3,5,7,8,54,34,67,45,112,89};
    int size = sizeof(arr)/sizeof(int);
    int element = 112;
    int searchIndex = linearSearch(arr, size, element);
    if (searchIndex == -1){
        printf("The element was not found...");
    }
    else{
        printf("The element %d was found at index %d \n", element, searchIndex);
    }
    return 0;
}