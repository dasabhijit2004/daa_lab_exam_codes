#include<stdio.h>
#include<limits.h>
#define MAX 10

void printTable(int m[][MAX], int s[][MAX], int n){
	int i, j;
	printf("M Table: \n");
	for(i = 1; i<n; i++){
		for(j = 1; j<n; j++){
			if(i <= j){
				printf("%d\t",m[i][j]);
			}
			else{
				printf("\t");
			}
		}
		printf("\n");
	}
	printf("S Table: \n");
	for(i = 1; i<n; i++){
		for(j = 1; j<n; j++){
			if(i < j){
				printf("%d\t",s[i][j]);
			}
			else{
				printf("\t");
			}
		}
		printf("\n");
	}
}

void parenthesis(int s[][MAX], int i, int j){
	if(i == j){
		printf("A%d",i);
	}
	else{
		printf("(");
		parenthesis(s, i, s[i][j]);
		parenthesis(s, s[i][j]+1, j);
		printf(")");
	}
}

int matrixChain(int p[], int n){
	int m[MAX][MAX];
	int s[MAX][MAX];
	int i, j, k, l, q;
	for(i = 1; i<n; i++){
		for(j = 1; j<n; j++){
			if(i == j){
				m[i][j] = 0;
			}
			else{
				m[i][j] = INT_MAX;
			}
		}
	}
	for(l = 2; l<n; l++){
		for(i = 1; i<n-l+1; i++){
			j = i+l-1;
			for(k = i; k<j; k++){
				q = m[i][k]+m[k+1][j]+p[i-1]*p[j]*p[k];
				if(q < m[i][j]){
					m[i][j] = q;
					s[i][j] = k;
				}
			}
		}
	}
	printTable(m, s, n);
	parenthesis(s, 1, n-1);
	printf("\n");
	return m[1][n-1];
}

int main(void){
	int m;
	printf("Enter no of matrices: ");
	scanf("%d",&m);
	int n = m+1;
	printf("Array size: %d\n",n);
	int arr[n];
	printf("Enter array elements: \n");
	int i;
	for(i = 0; i<n; i++){
		scanf("%d",&arr[i]);
	}
	int res = matrixChain(arr, n);
	printf("Multiplications required: %d",res);
	return 0;
}
