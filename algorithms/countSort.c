#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

// Time complexity = O(n+max)
int maximum(int* a, int n){
    int max = INT_MIN;
    for(int i=0;i<n;i++){
        if(a[i]>max){
            max = a[i];
        }
    }
    return max;
}

void countSort(int* a, int n){
    int max = maximum(a, n);
    int* count = (int *)malloc((max+1)*sizeof(int));
    int i,j;
    for(int i=0;i<max+1;i++){
        count[i] = 0;
    }
    for(i=0;i<n;i++){
        count[a[i]]++;
    }
    i=0;j=0;
    while(i<=max){
        if(count[i]>0){
            a[j] = i;
            count[i]--;
            j++;
        }
        else{
            i++;
        }
    }
}


int main(){
    int n;
    scanf("%d", &n);
    int* a = (int *)malloc(n*sizeof(int));
    for(int i=0;i<n;i++){
        scanf("%d", &a[i]);
    }
    countSort(a, n);
    for(int i=0;i<n;i++){
        printf("%d ", a[i]);
    }printf("\n");
    return 0;
}