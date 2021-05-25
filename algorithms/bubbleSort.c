#include<stdio.h>

// Time Complexity = O(n^2)
void printArray(int arr[], int n){
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void swap(int *a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void bubbleSort(int arr[], int n){
    for (int i = 0; i < n-1; i++)
    {
        printf("Working on pass number: %d\n", i+1);
        for (int j = 0; j < n-i-1; j++)
        {
            if (arr[j]>arr[j+1])
            {
                swap(&arr[j], &arr[j+1]);
            }   
        }
    }
}

void adaptiveBubbleSort(int arr[], int n){
    int isSorted = 0;
    for (int i = 0; i < n-1; i++)
    {
        printf("Working on pass number: %d\n", i+1);
        isSorted = 1;
        for (int j = 0; j < n-i-1; j++)
        {
            if (arr[j]>arr[j+1])
            {
                swap(&arr[j], &arr[j+1]);
                isSorted = 0;
            }
        }
        if (isSorted)
        {
            return;
        } 
    }
}


int main(){
    // int n;
    // scanf("%d", &n);
    // int arr[10];
    // for (int i = 0; i < n; i++)
    // {
    //     scanf("%d", &arr[i]);
    // }
    int arr[5] = {1,2,34,21,22};
    int n=5;
    printArray(arr, n);
    // bubbleSort(arr, n);
    printArray(arr, n);
    adaptiveBubbleSort(arr,n);
    printArray(arr, n);
    return 0;
}