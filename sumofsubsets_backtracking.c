#include<stdio.h>
#include<stdlib.h>
#define N 10
int n,j;
int w[N],x[N];
int sum_req = 0;
void sum_of_subset(int cur_sum,int k,int balance){
      if(k<n || cur_sum == sum_req){

        if(cur_sum == sum_req){
            for(j=0;j<k;j++){
                if(x[j] == 1){
                    printf("%d ",w[j]);

                }
            }
            //printf("sum = %d \n",cur_sum);
            printf("\n");
        }
        else{

             if(cur_sum+w[k]<=sum_req){
                 x[k] = 1;
                 sum_of_subset(cur_sum+w[k],k+1,balance-w[k]);
             }
             x[k] = 0;
             if(cur_sum+balance-w[k]>=sum_req && cur_sum+w[k+1]<=sum_req){

                sum_of_subset(cur_sum,k+1,balance-w[k]);
             }

        }
      }
      else{
        printf("sum = %d \n",cur_sum);
		return;
      }



}
int main(){
	int i,j,sum=0;
	printf("Enter no of elements:");
	scanf("%d",&n);
	printf("\nEnter the elements of matrix:");
	for(i=0;i<n;i++){
		scanf("%d",&w[i]);
		x[i] = -1;
		sum+=w[i];
	}
	printf("\nEnter the sum of elements required:");
	scanf("%d",&sum_req);
	if(sum<sum_req){
		printf("\nSolution does not exist");
	}
	else{
		sum_of_subset(0,0,sum);
	}


}

