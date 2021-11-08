#include <stdio.h>
#define MAX 10000
int V;

int minDistance(int dist[], int sptSet[])
{
    int min = MAX, min_index;

    for (int v = 0; v < V; v++)
        if (sptSet[v] == 0 && dist[v] <= min)
            min = dist[v], min_index = v;

    return min_index;
}

void printSolution(int dist[])
{
    printf("\nVertex \t\tDistance from Source\n");
    for (int i = 0; i < V; i++)
        printf("%d \t\t %d\n", i, dist[i]);
}

void dijkstra(int graph[V][V], int src)
{
    int dist[V];

    int sptSet[V];
    for (int i = 0; i < V; i++)
        dist[i] = MAX, sptSet[i] = 0;
    dist[src] = 0;

    for (int count = 0; count < V - 1; count++)
        {
        int u = minDistance(dist, sptSet);
        sptSet[u] = 1;
        for (int v = 0; v < V; v++)
            if (!sptSet[v] && graph[u][v] && dist[u] != MAX
                && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }
    printSolution(dist);
}

int main()
{

    printf("\n Enter the Number of Vertices : ");
    scanf("%d",&V);
    int graph[V][V];
    printf("\n Enter the adjacency matrix:\n");
	for(int i=0;i<V;i++)
    {
		//printf("\n Enter row %d : ",i+1);
		for(int j=0;j<V;j++){
			scanf("%d",&graph[i][j]);
		}
	}

    dijkstra(graph, 0);

    return 0;
}
