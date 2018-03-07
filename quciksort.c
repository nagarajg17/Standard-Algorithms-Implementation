#include<stdio.h>
#include<stdlib.h>
int partition(int *arr,int start,int end){
	int i,j,pivot,temp;
	pivot = arr[start];
	i = start+1;
	j = end;
	while(1){
		while(arr[i]<=pivot && i<end){
			i++;
		}
		while(arr[j]>pivot && j>start){
			j--;
		}
		if(i<j){
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
		else{
			temp = arr[start];
			arr[start] = arr[j];
			arr[j] = temp;
			return j;
		}
	}
}
void quick_sort(int *arr,int start,int end){
	int p;
	if(start<end){
		p = partition(arr,start,end);
		//printf("-----%d------\n",p);
		quick_sort(arr,start,p-1);
		quick_sort(arr,p+1,end);
	}
}
int main(){
	int n,i,j;
	printf("Enter no of elements:");
	scanf("%d",&n);
	int arr[n];
	printf("Enter the array elements:");
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	quick_sort(arr,0,n-1);
	printf("sorted elements are: ");
	for(i=0;i<n;i++){
		printf("%d ",arr[i]);
	}
    return 0;
}
