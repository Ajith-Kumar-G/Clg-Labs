#include<stdio.h>

void DFS(int);
int g[10][10],visited[10],n;

int main()
{
    printf("\n Enter the Number of Vertices : ");
    scanf("%d",&n);
    printf("\n Enter the Adjacency Matrix of the Graph : ");

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            scanf("%d",&g[i][j]);
        visited[i]=0;
    }

    DFS(0);

    return 0;
}

void DFS(int k)
{
    printf("\n %d",k);
    visited[k]=1;
    for(int j=0;j<n;j++)
        if(!visited[j] && g[k][j]==1)
            DFS(j);
}
