#include<stdio.h>
#define N 10
int cost[N][N];
int minimum(int a,int b){
    return(a>b?b:a);
}
void floydwarshall(int n){
	int w[n+1][n][n];
	int i,j,k;
	/*Initialize first weight array as infinity*/
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			w[0][i][j] = 1000;
		}
	}
	/*k=0 step initialize directly connected edges*/
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(cost[i][j]!=1000){
				w[0][i][j] = cost[i][j];
			}
		}
	}
	/*run n times n^2 updates*/
	printf("All pair shortest path is:\n");
	for(k=1;k<=n;k++){
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				w[k][i][j] = minimum(w[k-1][i][j],w[k-1][i][k-1]+w[k-1][k-1][j]);
			}
		}
		for(i=0;i<n;i++){
            for(j=0;j<n;j++){
			    printf("%d ",w[k][i][j]);
            }
		    printf("\n");
        }
        printf("\n");
    }





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

	floydwarshall(n);
	return 0;
}
