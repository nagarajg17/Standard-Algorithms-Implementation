#include<stdio.h>
inline int max(int a,int b){
	return(a>=b?a:b);
}
void knapsack(int *weight,int *values,int w,int n){
	int v[n+1][w+1];
	int i,j,wt;
	for(i=0;i<=w;i++){
		v[0][i] = 0;
	}
	for(i=1;i<=n;i++){
		v[i][0] = 0;
	}
	for(i=1;i<=n;i++){
		for(j=1;j<=w;j++){
			if(weight[i-1]>j){
				v[i][j] = v[i-1][j];
			}
			else if(weight[i-1]<=j){
				v[i][j] = max(v[i-1][j],values[i-1]+v[i-1][j-weight[i-1]]);
			}
		}
	}
	printf("Max profit = %d",v[n][w]);
	i = n;
	wt = w;
	printf("\nItems selected are = ");
	while(i>0 && wt>0){
        if(v[i][wt]!=v[i-1][wt]){
            printf("%d,",i);
            i = i-1;
            wt = wt-weight[i];
        }
        else{
            i = i-1;
        }

	}
}
int main(){
	int weights[]={3,2,4,1};
	int values[]={100,20,60,40};
	int n = sizeof(weights)/sizeof(weights[0]);
	knapsack(weights,values,5,n);
	return 0;
}
