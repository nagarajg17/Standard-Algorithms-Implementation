#include<stdio.h>
#include<stdlib.h>
#define N 10
int visited[N];
int adj[N][N];
void DFS(int s,int n){
	int i;
	visited[s] = 1;
	printf("%d ",s);
    for(i=0;i<n;i++){
    	if(adj[s][i] == 1){
    		if(visited[i] == 0){
    			DFS(i,n);
    		}
    	}
    }
 }

int main(){
	int n,i=0,j=0,s=0;
	printf("Enter the no of vertices:");
	scanf("%d",&n);
	for(i=0;i<n;i++){
		visited[i] = 0;
		printf("\nFill matrix for vertex %d:",i);
		for(j=0;j<n;j++){
			scanf("%d",&adj[i][j]);
		}
	}
	printf("\nEnter the start vertex:");
	scanf("%d",&s);
	DFS(s,n);
	for(i=0;i<n;i++){
        if(visited[i] == 0){
            printf("\nGraph is disconnected at vertex %d",i);
            return 0;
        }
	}
	printf("\ngraph is connected:");
	return 0;
}
