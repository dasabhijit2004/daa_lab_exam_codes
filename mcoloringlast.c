#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int graph[10][10];
int n, m;
int x[10];

bool readGraph(){
	FILE *fp;
	fp = fopen("graph.txt","r");
	if(fp == NULL){
		printf("Graph reading failed\n");
		return false;
	}
	fscanf(fp,"%d",&n);
	int i, j;
	for(i = 0; i<n; i++){
		for(j = 0; j<n; j++){
			fscanf(fp,"%d",&graph[i][j]);
		}
	}
	return true;
}

void showGraph(){
	int i, j;
	for(i = 0; i<n; i++){
		printf("%c: ",65+i);
		for(j = 0; j<n; j++){
			if(graph[i][j] == 1){
				printf("%c\t",65+j);
			}
		}
		printf("\n");
	}
}

void print(){
	int i; 
	for(i = 0; i<n; i++){
		printf("%3d",x[i]);
	}
	printf("\n");
}

void nextValue(int k){
	int j;
	do{
		x[k] = (x[k]+1)%(m+1);
		if(x[k] == 0){
			return;
		}
		for(j = 0; j<n; j++){
			if(graph[k][j] != 0 && x[j] == x[k]){
				break;
			}
		}
		if(j == n){
			return;
		}
	}while(1);
}

void mcoloring(int k){
	do{
		nextValue(k);
		if(x[k] == 0){
			return;
		}
		if(k == n-1){
			print();
		}
		else{
			mcoloring(k+1);
		}
	}while(1);
}

int main(){
	if(readGraph()){
		showGraph();
		printf("Enter the no of colors: ");
		scanf("%d",&m);
		int i;
		for(i = 0; i<n; i++){
			x[i] = 0;
		}
		if(m > 1){
			mcoloring(0);
		}
		else{
			printf("Coloring not possible");
		}
	}
	else{
		printf("Graph read failed");
	}	
	return 0;
}
