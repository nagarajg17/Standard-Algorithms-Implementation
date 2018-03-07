#include<stdio.h>
#include<stdlib.h>

int main(){
	int n,i=0,j=0,s=0;
	printf("Enter the no of vertices:");
	scanf("%d",&n);
	int adj[n][n];
	int indegree[n];
	for(i=0;i<n;i++){
		indegree[i] = 0;
		printf("\nFill matrix for vertex %d:",i);
		for(j=0;j<n;j++){
			scanf("%d",&adj[i][j]);
		}
	}
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			indegree[i]+=adj[j][i];
		}
	}
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(indegree[j] == 0){
				s = j;
				break;
			}
		}
		indegree[s] = -1;
		printf("%d ",s+1);
		for(j=0;j<n;j++){
			if(adj[s][j] == 1){
				indegree[j]-=1;
			}
		}
	}

}
