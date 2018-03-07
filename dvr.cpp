#include<stdio.h>
#define N 6
int nexthop[N][N];
int cost[N][N];
int old_value[N][N];
int new_value[N][N];
int hopcount[N][N];
int n;
void printresult(){
	int i,j;
	for(i=0;i<n;i++){
		printf("Router %d\n",i);
		printf("DestinationRouter\t\t\tDistance\t\tNexthop\t\tHopcount\n\n");
		for(j=0;j<n;j++){
            if(cost[i][j]!=1000){
            	printf("%d\t\t\t%d\t\t\t%d\t\t\t%d\t\t\n",j,new_value[i][j],nexthop[i][j],hopcount[i][j]);
            }
        }
        printf("\n");
    }

}
void updatetable(){
	int i,j;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			old_value[i][j] = new_value[i][j];
		}
	}
}
void DVR(){
	int i,j,k,flag;
	do{
		flag = 0;
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				for(k=0;k<n;k++){
					if(old_value[i][j]>old_value[i][k]+old_value[k][j] && cost[i][j]!=1000){
						new_value[i][j] = old_value[i][k] + old_value[k][j];
						flag = 1;
						nexthop[i][j] = k;
						hopcount[i][j] = 1+hopcount[k][j];
					}
				}
			}
		}
		updatetable();
	}while(flag == 1);
}
int main(){
	printf("Enter no of routers:");
	scanf("%d",&n);
	int i,j;
	printf("\nEnter the cost matrix:");
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			scanf("%d",&cost[i][j]);
			old_value[i][j] = new_value[i][j] = cost[i][j];
			nexthop[i][j] = j;
			hopcount[i][j] = 0;
		}
	}
	DVR();
	printresult();
	return 0;

}
