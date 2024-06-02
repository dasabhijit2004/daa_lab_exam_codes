#include<stdio.h>
#include<stdbool.h>

int graph[10][10];
int visited[10] = {0};

int queue[10];
int front = -1, rear = -1;

bool isEmpty(){
	return front == rear;
}

void enqueue(int n){
	queue[rear++] = n;
}

int dequeue(){
	int x = queue[front++];
	return x;
}

int readGraph(){
	FILE *fp;
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

void bfs(int v, int n){
	visited[v] = 1;
	enqueue(v);
	while(!isEmpty()){
		int x = dequeue();
		printf("%c\t",65+x);
		int i;
		for(i = 0; i<n; i++){
			if(graph[x][i] == 1 && visited[i] == 0){
				enqueue(i);
				visited[i] = 1;
			}
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
		bfs(v,n);
	}
	
	return 0;
}
