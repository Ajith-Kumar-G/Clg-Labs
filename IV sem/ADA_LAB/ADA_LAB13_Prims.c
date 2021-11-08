#include<stdio.h>
#define MAX 10000
int n;

int mKey(int key[], int mstSet[])
{
    int min = MAX, minIN;
    for (int v = 0; v < n; v++)
        if (!mstSet[v] && key[v]<min)
            min = key[v], minIN = v;

    return minIN;
}


int printMST(int parent[], int graph[][n])
{
    int sum=0;
    printf("\n Edge \tWeight\n");
    for (int i = 1; i < n; i++){
        printf("(%d,%d) =%5d\n",parent[i], i, graph[i][parent[i]]);
        sum+=graph[i][parent[i]];
    }
    printf("\n The Total Weight= %d \n",sum);
}

void primMinSpanTree(int graph[][n])
{
    int parent[n],key[n];

    int mstSet[n];


    for (int i = 0; i < n; i++)
    {
        key[i] = MAX;
        mstSet[i] = 0;
    }

    key[0] = 0;
    parent[0] = -1;
    for (int count = 0; count < n - 1; count++)
    {
        int u = mKey(key, mstSet);
        mstSet[u] = 1;
        for (int v = 0; v < n; v++)
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v])
                parent[v] = u, key[v] = graph[u][v];
    }
    printMST(parent, graph);
}

int main()
{
    printf("\n Enter the Number of Vertices : ");
    scanf("%d",&n);
    int graph[n][n];
    printf("\n Enter the adjacency matrix:\n");
	for(int i=0;i<n;i++)
    {
		//printf("\n Enter row %d : ",i+1);
		for(int j=0;j<n;j++){
			scanf("%d",&graph[i][j]);
		}
	}

    primMinSpanTree(graph);
	return 0;

}
//0 2 0 6 0 2 0 3 8 5 0 3 0 0 7 6 8 0 0 9 0 5 7 9 0
