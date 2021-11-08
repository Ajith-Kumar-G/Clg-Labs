#include<stdio.h>

void DFS(int,int,int);
int g[10][10],visited[10],n,pivot;

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
	}
	for(int i=0;i<n;i++)
    {
      for(int j=0;j<n;j++)
      visited[j]=0;
      DFS(i,i,0);
    }
    display(1);

    return 0;
}

void DFS(int p,int k,int flag)
{
    pivot=p;
    visited[k]=1;

    for(int j=0;j<n;j++)
    {
        if(g[k][j]==1)
        {
            if(visited[j]==0){
             //printf("\n pivot:%d k=%d and j=%d ",pivot,k,j);
             DFS(pivot,j,1);
            }
            if(pivot==j)
                display(-1);
        }
    }
}

void display(int flag)
{
    if(flag==1)
        printf("\n The graph is free from cycles!");
    else
        {
             printf("\n The graph has cycles!");
             exit(0);
        }
}

//0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 1 0 0 0 0 1 1 0 0 0 0 1 0 1 0 0 0
//0 0 1 0 0 0 0 1 0 0 0 0 0 1 1 0 0 0 0 1 0 0 0 0 0
//0 1 0 0 0 0 0 0 1 0 0 1 0 0 0 0 0 1 0 0 0 0 0 1 0
