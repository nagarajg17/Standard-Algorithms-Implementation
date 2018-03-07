#include<stdio.h>
#include<limits.h>

#define N 10
int cost[N][N];
void prim(int n,int s){
	int visited[n];
	int distance[n];
	int parent[n];
	int i,j,min,index,mincost=0;
	for(i=0;i<n;i++){
		visited[i] = 0;
		distance[i] = 1000;
		parent[i] = -1;
	}
	distance[s] = 0;

	for(i=0;i<n;i++){
		/*finding minimum vertex in graph*/
		min = 1000;
		index = 0;
		for(j=0;j<n;j++){
			if(min>distance[j] && visited[j] == 0){
				index = j;
				min = distance[j];
			}
		}

		visited[index] = 1;
        /*updating edge weights*/
		for(j=0;j<n;j++){
			if(cost[index][j]!=1000 && visited[j] == 0){
				if(distance[j]>cost[index][j]){
					distance[j] = cost[index][j];
					parent[j] = index;
				}
            }
		}
		for(j=0;j<n;j++){
		   printf("%d ",distance[j]);
       }
       printf("\n");
	}
	for(i=n-1;i>0;i--){
		printf("parent of %d is %d\n",i+1,parent[i]+1);
		mincost+=distance[i];
    }
    printf("Minimum cost of spanning tree is:%d\n",mincost);


}

int main(){
	int n,i=0,j=0,s=0;
	printf("Enter the no of vertices:");
	scanf("%d",&n);
	//printf("%d",INT_MAX);
	printf("\nEnter the cost matrix:");
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			scanf("%d",&cost[i][j]);
		}
	}
	printf("\nEnter the start vertex:");
	scanf("%d",&s);
	prim(n,s);
	return 0;
}

