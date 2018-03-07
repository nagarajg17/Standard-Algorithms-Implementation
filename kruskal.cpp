#include<stdio.h>
#define N 10
int cost[N][N];

void kruskal(int n){
	int i,j,no_of_edges=n-1,min,mincost=0,k=1,compvalue;
	int index1,index2;
	int component[n];
	for(i=0;i<n;i++){
		component[i] = i;
	}
	while(k<=no_of_edges){
		min = 1000;
		index2 = index1 = 0;
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				if(min>cost[i][j] && i!=j){
					min = cost[i][j];
					index1 = i;
					index2 = j;
				}
			}
		}
		compvalue = component[index2];
		if(component[index1]!=component[index2]){
			mincost+=cost[index1][index2];
			for(i=0;i<n;i++){
				if(component[i] == compvalue){
					component[i] = component[index1];
				}
			}
			k++;
		}
		printf("\nmin=%d,%d-%d\n",min,index1+1,index2+1);
		cost[index1][index2] = 1000;
		cost[index2][index1] = 1000;
		for(j=0;j<n;j++){
            printf("%d ",component[j]);
		}
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
	kruskal(n);
	return 0;
}
