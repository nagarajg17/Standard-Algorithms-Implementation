#include<stdio.h>
#include<stdlib.h>
void horner_rule(int *arr,int n,int x){
	int result = arr[0],i;
	for(i=1;i<n;i++){
		result = result*x+arr[i];
	}
    printf("Answer = %d",result);
}

int main(){
	int arr[]={2,0,3,1};
	int n = (sizeof(arr)/sizeof(arr[0]));
	int x = 2;
	horner_rule(arr,n,x);
	return 0;
}
