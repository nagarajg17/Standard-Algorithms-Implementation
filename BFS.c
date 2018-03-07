#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
struct qnode{
	int v;
	struct qnode *next;
};
struct qnode *front = NULL,*rear = NULL,*temp;
struct qnode* create_node(int k){
    struct qnode *node = (struct qnode *)malloc(sizeof(struct qnode));
	node->v = k;
	node->next = NULL;
	return node;
}
int main(){
	int n,i=0,j=0,s=0;
	struct qnode *node;
	printf("Enter the no of vertices:");
	scanf("%d",&n);
	int visited[n];
	int adj[n][n];
	for(i=0;i<n;i++){
		visited[i] = 0;
		printf("\nFill matrix for vertex %d:",i);
		for(j=0;j<n;j++){
			scanf("%d",&adj[i][j]);
		}
	}
	printf("\nEnter the start vertex:");
	scanf("%d",&s);
	node = create_node(s);
	front = node;
	rear = node;
	visited[s] = 1;
	while(rear!=NULL){
        s = rear->v;
        printf("%d ",s);
        for(i=0;i<n;i++){
        	if(adj[s][i] == 1){
        		if(visited[i] == 0){
        			visited[i] = 1;
        			//printf("\n------%d-----\n",i);
        			node = create_node(i);
                    front->next = node;
                    front = node;
        		}
        	}
        }
        temp = rear;
        rear = rear->next;
        free(temp);
	}

}
