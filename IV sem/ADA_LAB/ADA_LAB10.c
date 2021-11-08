#include<stdio.h>
#include<conio.h>
#include<math.h>

int max(int,int);

void warshall(int A[10][10],int n) {
	for (int k=0;k<n;k++)
	  for (int i=0;i<n;i++)
	   for (int j=0;j<n;j++)
	    A[i][j]=max(A[i][j],A[i][k]&&A[k][j]);
}
int max(int a,int b) {
	return a>b?a:b;
}
void main() {
	int p[10][10];
	int n;

    printf("\n Enter the Number of Vertices : ");
    scanf("%d",&n);
    printf("\n Enter the adjacency matrix:\n");
	for(int i=0;i<n;i++)
    {
		//printf("\n Enter row %d : ",i+1);
		for(int j=0;j<n;j++)
			scanf("%d",&p[i][j]);
	}

	printf("\n Matrix of input data: \n");
	for (int i=0;i<n;i++) {
		for (int j=0;j<n;j++)
		   printf(" %d\t",p[i][j]);
		printf("\n");
	}
	warshall(p,n);
	printf("\n Transitive closure: \n");
	for (int i=0;i<n;i++) {
		for (int j=0;j<n;j++)
		   printf(" %d\t",p[i][j]);
		printf("\n");
	}

}

//0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 1 0 0 0 0 1 1 0 0 0 0 1 0 1 0 0 0
// 0 1 0 0 0 0 1 0 1 0 0 1 0 0 0 0
