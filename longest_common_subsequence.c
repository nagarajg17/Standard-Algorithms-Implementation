#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 30
void longest_common_subword(char *x,char *y,int m,int n){
	int r,c,len = 0;
	char sub[r];
	int lcs[m][n];
	for(c=0;c<=n;c++){
		lcs[0][c] = 0;
	}
	for(r=1;r<=m;r++){
		lcs[r][0] = 0;
	}
	for(r=0;r<m;r++){
		for(c=0;c<=n;c++){
			if(x[r] == y[c]){
				lcs[r+1][c+1] = 1+lcs[r][c];
			}
			else{
				lcs[r+1][c+1] = lcs[r][c+1]>lcs[r+1][c]?lcs[r][c+1]:lcs[r+1][c];
			}

		}
	}
	printf("longest_common_subword=%d\n",lcs[m][n]);
	printf("Commonsubsequence = ");
	r = m;c = n;
	len = 0;
	while(r>0 && c>0){
		if(lcs[r][c]>lcs[r-1][c] && lcs[r][c]>lcs[r][c-1]){
			//printf("%c",x[r-1]);
			sub[len] = x[r-1];
			r = r-1;
			c = c-1;
			len++;
		}
		else{
			if(lcs[r-1][c]>=lcs[r][c-1]){
				r = r-1;

			}
			else{
				c = c-1;
			}

		}

	}
	for(r=len-1;r>=0;r--){
        printf("%c",sub[r]);
	}
	/*for(r=0;r<=m;r++){
		lcs[r][n+1] = 0;
	}
	for(c=0;c<=n;c++){
		lcs[m+1][c] = 0;
	}
	lcs[m+1][n+1] = 0;
	for(c=n;c>=0;c--){
		for(r=m;r>=0;r--){
			if(x[r] == y[c]){
				lcs[r][c] = 1+lcs[r+1][c+1];
			}
			else{
				lcs[r][c] = lcs[r+1][c]>=lcs[r][c+1]?lcs[r+1][c]:lcs[r][c+1];
			}
		}
	}
	printf("longest_common_subword=%d\n",lcs[0][0]);
	printf("Commonsubsequence = ");
    */



}
int main(){
	int m,n;
	char x[N],y[N];
	printf("Enter first word:");
	scanf("%s",x);
	printf("Enter second word:");
	scanf("%s",y);
	m = strlen(x);
	n = strlen(y);
	longest_common_subword(x,y,m,n);

}

