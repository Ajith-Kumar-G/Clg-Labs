#include<stdio.h>

void DFS(int,int);
int g[10][10],visited[10],deadend[10],d=-1,n;
int sortedOrder[10],o,count=0;

int main()
{
    printf("\n Enter the Number of Vertices : ");
    scanf("%d",&n);
    o=n;
    printf("\n Enter the adjacency matrix:\n");
	for(int i=0;i<n;i++)
    {
		//printf("\n Enter row %d : ",i+1);
		for(int j=0;j<n;j++)
			scanf("%d",&g[i][j]);
        visited[i]=0;
	}
	printf("\n");
	for(int i=0;i<n;i++)
    {
      DFS(i,0);
    }

    printf("\n\n Topology Order: ");
    for(int i=0;i<n;i++)
    {
        printf(" %d ",sortedOrder[i]);
    }

    return 0;
}

void DFS(int k,int flag)
{
    if(flag==0 && visited[k]==0)
    {
        printf("\n %d ",k);
        sortedOrder[--o]=k;
    }
    else if(flag==0 && visited[k]!=0)
    printf("");
    else
    {
        printf(" %d ",k);
        deadend[++d]=k;
    }
    visited[k]=1;

    for(int j=0;j<n;j++)
        if(visited[j]==0 && g[k][j]==1)
        {
             DFS(j,1);
        }

    if(d>=0){
    int temp=sortedOrder[o++];
    for(int k=d;k>=0;k--,--d)
    {
        sortedOrder[--o]=deadend[k];
    }
    sortedOrder[--o]=temp;
    }

}

//0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 1 0 0 0 0 1 1 0 0 0 0 1 0 1 0 0 0
//0 0 1 0 0 0 0 1 0 0 0 0 0 1 1 0 0 0 0 1 0 0 0 0 0
