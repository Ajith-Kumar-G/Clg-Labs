#include<stdio.h>
#include<time.h>
#include<stdlib.h>

void selectionSort(int [],int);
void funct(int n)
{
    clock_t t;
    int list[n];
    for(int i=0;i<n;i++)
        list[i]=rand();
    t=clock();
    selectionSort(list,n);
    t=clock()-t;

    double time_taken = ((double)t)/CLOCKS_PER_SEC;
    printf("\n Time of Execution For N=%d is  %f ",n,time_taken);

    if(n<=5000)
    {
        n+=500;
        funct(n);
    }
    else

    return;
}

int main()
{
    int n=500;
    funct(n);
    return 0;
}

void selectionSort(int list[], int n)
{
    int i, j, min;
    for (i = 0; i < n-1; i++)
    {
        min = i;
        for (j = i+1; j < n; j++)
        {
        if (list[j] < list[min])
        min = j;
        }
        int temp=list[i];
        list[i]=list[min];
        list[min]=temp;
    }
}

