#include<stdio.h>
#include<time.h>
#include<stdlib.h>

void insertionSort(int [],int);
void funct(int n)
{
    int list[n];
    clock_t t;
    t=0;
    for(int i=0;i<n;i++)
        list[i]=rand();
    t=clock();
    insertionSort(list,n);
    t=clock()-t;

    double time_taken = ((double)t)/CLOCKS_PER_SEC;
    printf("\n Time of Execution For N= %d is %f ",n,time_taken);

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
    clock_t t;

    funct(n);

    return 0;
}

void insertionSort(int list[], int n)
{
    int i, j,raw;
    for (i = 1; i < n; i++)
    {
        raw = list[i];
        j=i-1;
        while (j >= 0 && list[j] > raw) {
            list[j + 1] = list[j];
            j = j - 1;

        }
        list[j + 1] = raw;
    }

}

