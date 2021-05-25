#include <stdio.h>

// Time Complexity: Worst Case-> O(n^2)
//					Best Case-> O(n)					
void printArray(int arr[], int n){
	for (int i = 0; i < n; ++i)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void insertionSort(int arr[], int n){
	for (int i = 1; i < n; ++i)
	{
		int key, j;
		key = arr[i];
		j = i-1;
		while(j>=0 && arr[j] > key){
			arr[j+1] = arr[j];
			j--;
		}
		arr[j+1] = key;
	}
}

int main(){
	int arr[] = {24,12,3,4,7};
	int n = 5;
	// int n;
	// scanf("%d", &n);
	// int arr[10];
	// for (int i = 0; i < n; ++i)
	// {
	// 	scanf("%d", &arr[i]);
	// }
	printArray(arr, n);
	insertionSort(arr, n);
	printArray(arr, n);
	return 0;
}