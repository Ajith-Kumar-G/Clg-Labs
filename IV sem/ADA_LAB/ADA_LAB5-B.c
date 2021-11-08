#include<stdio.h>

void DFS(int);
int g[10][10],visited[10],n;

int main()
{
    int flag;
    printf("\n Enter the Number of Vertices : ");
    scanf("%d",&n);
    printf("\n Enter the Adjacency Matrix of the Graph : \n ");

    for(int i=0;i<n;i++)
    {
       // printf("\n Enter row %d : ",i+1);
        for(int j=0;j<n;j++)
            scanf("%d",&g[i][j]);
        visited[i]=0;
    }
    visited[0]=1;
    for(int i=0;i<n;i++)
    DFS(i);

    for(int i=0;i<n;i++)
        for(int j=i+1;j<n;j++){
    if(visited[i]!=visited[j]){
        printf("\n The Graph is not connected!");
        return 0;
    }

    }
     printf("\n The Graph is connected!");

    return 0;
}

void DFS(int k)
{
    visited[k]++;
  for(int j=0;j<n;j++)
        if(visited[j]==0 && g[k][j]==1)
        {
             DFS(j);
             return;
        }
}

//0 1 0 0 1 1 0 1 1 1 0 1 0 1 0 0 1 1 0 1 1 1 0 1 0 -connected
//0 0 1 0 0 0 0 1 0 0 0 0 0 1 1 0 0 0 0 1 0 0 0 0 0 -not connected
//0 0 0 0 0 0 0 1 1 1 0 1 0 1 0 0 1 1 0 1 0 1 0 1 0 -not connected
