#include<stdio.h>
#include<stdlib.h>

void merge(int a[], int low, int mid, int high){
    int i = low; int j = mid+1; int k = low; 
    int* b = (int *)malloc((high-low+1)*sizeof(int)); // array allocated dynamically
    while(i<=mid && j<=high){
        if(a[i]<=a[j]){
            b[k] = a[i];
            i++;k++;
        }
        else{
            b[k] = a[j];
            j++;k++;
        }
    }
    while(i<=mid){
        b[k] = a[i];
        i++;k++;
    }
    while(j<=high){
        b[k] = a[j];
        j++;k++;
    }
    for(int i=low;i<=high;i++){
        a[i] = b[i];
    }
}

void mergeSort(int a[], int low, int high){
    if(low<high){
        int mid = (low+high)/2;
        mergeSort(a, low, mid);
        mergeSort(a, mid+1, high);
        merge(a,low,mid,high);
    }
}

int main(){
    // int n = 10;
    // int a[] = {12, 10, 8, 9, 2, 4, 5, 7,1, 6};

    int n;
    scanf("%d", &n);
    int* a = (int *)malloc(n*sizeof(int)); // using dynamic array
    for(int i=0;i<n;i++){
        scanf("%d", &a[i]);
    }

    mergeSort(a, 0, n-1);

    for(int i=0;i<n;i++){
        printf("%d ", a[i]);
    }printf("\n");
    return 0;
}