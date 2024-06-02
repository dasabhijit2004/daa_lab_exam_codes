#include<stdio.h>

int max, min;
int arr[10];

void maxMin(int i, int j){
	int max1, min1;
	if(i == j){
		max = arr[i];
		min = arr[i];
		printf("Single element: MAX = MIN = %d\n",max);
	}
	else if(i == j-1){
		if(arr[i] > arr[j]){
			max = arr[i];
			min = arr[j];
		}
		else{
			max = arr[j];
			min = arr[i];
		}
		printf("Two elements: MAX = %d, MIN = %d\n",max, min);
	}
	else{
		int mid = (i+j)/2;
		printf("Divide: (%d to %d) and (%d to %d)\n",arr[i], arr[mid], arr[mid+1], arr[j]);
		maxMin(i, mid);
		max1 = max;
		min1 = min;
		maxMin(mid+1, j);
		if(max1 > max){
			max = max1;
		}
		if(min1 < min){
			min = min1;
		}
		printf("Conquer: MAX = %d, MIN = %d\n",max, min);
	}
}

int main(){
	int n;
	printf("Enter no of elements: ");
	scanf("%d",&n);
	printf("Enter array elements: \n");
	int i;
	for(i = 0; i<n; i++){
		scanf("%d",&arr[i]);
	}
	maxMin(0, n-1);
	printf("Last Result: MAX = %d, MIN = %d", max, min); 
	return 0;
}
