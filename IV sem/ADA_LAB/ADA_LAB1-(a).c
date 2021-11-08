#include<stdio.h>
#include<math.h>

void towerSolver(char,char,char,int);

int main()
{
    int noOfDisks;
    char pegA='S',pegB='B',pegC='C';

    printf("\n Enter the Number of Disks: ");
    scanf("%d",&noOfDisks);
    if(noOfDisks<=0)
    {
        printf("\n No of Disks Must be Positive Number!!");
        return 0;
    }
    else
    {

        printf("\n The  Min-no of Steps Required = %d",(int)pow(2,noOfDisks)-1);
        towerSolver(pegA,pegB,pegC,noOfDisks);
        return 0;
    }
}

void towerSolver(char source,char dest,char aux,int n)
{
    if(n==1)
    {
        printf("\n Move Disk-1 from Peg-%c to Peg-%c",source,dest);
    }

    else
    {
        towerSolver(source,aux,dest,n-1);
        printf("\n Move Disk-%d from Peg-%c to Peg-%c",n,source,dest);
        towerSolver(aux,dest,source,n-1);
    }
}
