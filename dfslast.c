#include<stdio.h>

int graph[10][10];
int visited[10] = {0};

int readGraph(){
	FILE* fp;
	fp = fopen("graph.txt","r");
	if(fp == NULL){
		printf("File open failed\n");
		return -1;
	}
	int n;
	fscanf(fp,"%d",&n);
	int i, j;
	for(i = 0; i<n; i++){
		for(j = 0; j<n; j++){
			fscanf(fp,"%d",&graph[i][j]);
		}
	}
	return n;
}

void showGraph(int n){
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

void dfs(int v, int n){
	visited[v] = 1;
	printf("%c\t",65+v);
	int i;
	for(i = 0; i<n; i++){
		if(graph[v][i] == 1 && visited[i] == 0){
			dfs(i,n);
		}
	}
}

int main(){
	int n;
	n = readGraph();
	showGraph(n);
	int v;
	printf("Enter source vertex: ");
	scanf("%d",&v);
	if(v>=0 && v<n){
		dfs(v,n);
	}
	
	return 0;
}
