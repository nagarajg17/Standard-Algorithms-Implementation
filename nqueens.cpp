#include<stdio.h>
#include<stdlib.h>
#define N 8
int board[N][N];
int n;

void printresult(){
	int i,j;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			printf("%d ",board[i][j]);

		}
		printf("\n");
	}
}

bool issafe(int row2,int col2){
	int i,j;
	for(j=0;j<col2;j++){
		for(i=0;i<n;i++){
			if(board[i][j] == 1){
				if(i == row2 || j == col2){
					return false;
				}
				if(abs(i-row2) == abs(j-col2)){
					return false;
				}
			}
		}
	}
	return true;
}

bool nqueen(int col){
	int i,j;
	if(col>=n){
		return true;
	}
	for(i=0;i<n;i++){
		if(issafe(i,col)){
			board[i][col] = 1;
			if(nqueen(col+1)){
				return true;
			}
			board[i][col] = 0;
		}
	}
	return false;
}

int main(){
	int i,j;
	bool result;
	printf("Enter no of queens:");
	scanf("%d",&n);
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			board[i][j] = 0;
		}
	}
	result = nqueen(0);
	if(result){
		printresult();
	}
	else{
		printf("Solution does not exist");
	}
	return 0;
}
