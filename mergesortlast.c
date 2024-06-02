#include<stdio.h>
#include<limits.h>

void display(int arr[], int si, int ei){
	int i;
	for(i = si; i<=ei; i++){
		printf("%d\t",arr[i]);
	}
	printf("\n");
}

void merge(int arr[], int si, int mid, int ei){
	int merged[ei-si+1];
	int i1 = si, i2 = mid+1, x = 0;
	while(i1 <= mid && i2 <= ei){
		if(arr[i1] < arr[i2]){
			merged[x++] = arr[i1++];
		}
		else{
			merged[x++] = arr[i2++];
		}
	}
	while(i1 <= mid){
		merged[x++] = arr[i1++];
	}
	while(i2 <= ei){
		merged[x++] = arr[i2++];
	}
	int i;
	for(i = 0; i<ei-si+1; i++){
		arr[si+i] = merged[i];
	}
	printf("\n");
	printf("Merging: ");
	display(arr, si, ei);
}

void mergeSort(int arr[], int si, int ei){
	if(si < ei){
		int mid = (si+ei)/2;
		mergeSort(arr, si, mid);
		mergeSort(arr, mid+1, ei);
		merge(arr, si, mid, ei);
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
	mergeSort(arr, 0, n-1);
	printf("Sorted array: \n");
	for(i = 0; i<n; i++){
		printf("%d\t",arr[i]);
	}
	return 0;
}
