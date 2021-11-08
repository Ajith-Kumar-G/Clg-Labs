#include<stdio.h>
#include<limits.h>
#define MAX 10000

int n;
void printSolution(int [][n]);

void floydSolution(int graph[][n])
{
    int d[n][n], i, j, k;

    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++){
               if(graph[i][j]==-1)
                    d[i][j]=MAX;
               else
                    d[i][j]=graph[i][j];
        }
    printf (" Matrix: D(0) \n");
    printSolution(d);
    for (k=0;k<n;k++)
    {
        for (i=0;i<n;i++)
        {
            for (j=0;j<n;j++)
            {
               if(d[i][j] > d[i][k] + d[k][j])
                 d[i][j]=d[i][k] + d[k][j];
            }
        }
    printf ("\n Solution Matrix: D(%d) \n",k+1);
    printSolution(d);
    }



}

void printSolution(int d[][n])
{

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (d[i][j]==MAX)
                printf("%6s", "INF");
            else
                printf ("%6d", d[i][j]);
        }
        printf("\n");
    }
}

int main()
{

    printf("\n Enter the Number of Vertices : ");
    scanf("%d",&n);
    int D[n][n];
    printf("\n Enter the adjacency matrix:(enter -1 if no direct path)\n");
	for(int i=0;i<n;i++)
    {
		//printf("\n Enter row %d : ",i+1);
		for(int j=0;j<n;j++){
			scanf("%d",&D[i][j]);
		}
	}
	floydSolution(D);

    return 0;
}

//0 -1 3 -1 2 0 -1 -1 -1 7 0 1 6 -1 -1 0
