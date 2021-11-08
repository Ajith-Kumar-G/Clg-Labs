
#include<stdio.h>

void bfs(int);

int g[10][10],visited[10],n,src;
int count=0,queue[10],rear=-1,front=0;

int main()
{
    printf("\n Enter the Number of Vertices : ");
    scanf("%d",&n);
    printf("\n Enter the adjacency matrix:\n");
	for(int i=0;i<n;i++)
    {
		//printf("\n Enter row %d : ",i+1);
		for(int j=0;j<n;j++)
			scanf("%d",&g[i][j]);
        visited[i]=0;
        queue[i]=0;
	}

    printf("\n Enter the Source vertex : ");
    scanf("%d",&src);
	bfs(src);

	printf("\n The Nodes reachable from vertex %d are : ",src);
	for(int i=0;i<=n;i++)
    if(visited[i])
        printf(" %d ",i);
    return 0;
}

void bfs(int k)
{
    for(int i=0;i<n;i++)
    {
        if(g[k][i]==1 && visited[i]==0)
            queue[++rear]=i;
    }
    if(front<=rear){
        visited[queue[front]]=1;
        bfs(queue[front++]);
    }
}
//0 1 1 1 0 0 0 1 0 0 0 0 0 0 1 0
//0 0 1 0 0 0 0 1 0 0 0 0 0 1 1 0 0 0 0 1 0 0 0 0 0 --tb example
