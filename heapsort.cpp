#include<stdio.h>
int n;
void max_heapify(int *arr,int parent){
	int largest,l,r,temp;
	l = 2*parent+1;
	r = 2*parent+2;
	if(l<n && arr[l]>arr[parent]){
		largest = l;
	}
	else{
		largest = parent;
	}
	if(r<n && arr[r]>arr[largest]){
		largest = r;
	}
	if(largest!=parent){
		temp = arr[parent];
		arr[parent] = arr[largest];
		arr[largest] = temp;
		max_heapify(arr,largest);
	}
}

void build_heap(int *arr){
	int i;
	for(i=(n/2)-1;i>=0;i--){
		max_heapify(arr,i);
	}
}

void heap_sort(int *arr){
	int max,i;
	for(i=n-1;i>=0;i--){
		max = arr[0];
		arr[0] = arr[n-1];
		n--;
		max_heapify(arr,0);
		printf("%d ",max);
	}
}

int main(){
	printf("Enter no of elements:");
	scanf("%d",&n);
	int arr[n],i;
	printf("\nEnter the array elements:");
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	build_heap(arr);
	printf("\nHeap after building:");
	for(i=0;i<n;i++){
        printf("%d ",arr[i]);
	}
	printf("\nSorted elements are:");
	heap_sort(arr);
}
