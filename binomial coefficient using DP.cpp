#include<stdio.h>
inline int min(int a,int b){
	return(a<=b?a:b);
}
void binomial_coefficient(int n,int k){
	int c[n+1][k+1],i,j;
	for(i=0;i<=n;i++){
		for(j=0;j<=min(i,k);j++){
			if(j==0 ||j==i){
				c[i][j] = 1;
			}
			else{
				c[i][j] = c[i-1][j-1]+c[i-1][j];
			}

		}
	}
	printf("C(%d,%d)=%d",n,k,c[n][k]);
}

int main(){
	int n = 10;
	int k = 7;
	binomial_coefficient(n,k);
	return 0;
}
