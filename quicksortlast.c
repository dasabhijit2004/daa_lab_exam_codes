#include<stdio.h>

void swap(int arr[], int i, int j){
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

void display(int arr[], int si, int ei){
	int i;
	for(i = si; i<=ei; i++){
		printf("%d\t",arr[i]);
	}
}

int partition(int arr[], int si, int ei){
	int i, j = si;
	int pivot = arr[si];
	printf("\nPivot = %d\n",pivot);
	for(i = si+1; i<=ei; i++){
		if(arr[i]<pivot){
			j++;
			swap(arr, i, j);
		}
	}
	swap(arr, si, j);
	return j;
}

void quickSort(int arr[], int si, int ei){
	if(si < ei){
		int part = partition(arr, si, ei);
		display(arr, si, ei);
		printf("\n");
		quickSort(arr, si, part-1);
		quickSort(arr, part+1, ei);
	}
}

int main(){
	int n;
	printf("Enter the no of elements: ");
	scanf("%d",&n);
	int arr[n];
	printf("Enter elements: ");
	int i;
	for(i = 0; i<n; i++){
		scanf("%d",&arr[i]);
	}
	printf("Unsorted array: \n");
	for(i = 0; i<n; i++){
		printf("%d\t",arr[i]);
	}
	quickSort(arr, 0, n-1);
	printf("Sorted array: \n");
	for(i = 0; i<n; i++){
		printf("%d\t",arr[i]);
	}
	return 0;
}
