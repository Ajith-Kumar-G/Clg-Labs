#include <stdio.h>
#include <stdlib.h>
#include<time.h>

void swap(int* x, int* y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

int partition(int a[], int l, int r)
{
    int pivot = a[l];
    int i = l, j = r;

    while (1) {
        while (a[i] < pivot)
            i++;
        while (a[j] > pivot)
            j--;
        if (i >= j)
            return j;
        swap(&a[i], &a[j]);
    }
}

void quickSort(int a[], int l, int r)
{
    if (l < r)
    {
        int pI = partition(a, l, r);
        quickSort(a, l, pI - 1);
        quickSort(a, pI + 1, r);
    }
}

void func(int a[], int l, int r,int n,int flag)
{
    clock_t t;
    if(flag!=1){
    int list[n];
    l=0;r=n-1;
    for(int i=0;i<n;i++)
        list[i]=rand();
    t=clock();
    quickSort(list,l,r);
    t=clock()-t;
    }
    else{
    t=clock();
    quickSort(a,l,r);
    t=clock()-t;
    }

    double time_taken = ((double)t)/CLOCKS_PER_SEC;
    printf("\n Time of Execution For N=%d is  %f ",n,time_taken);
    if(flag==1){
    printf("\n Sorted array is \n");
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    }
    if(n<=5000 && flag!=1)
    {
        n+=500;
         func(a, 0, n - 1,n,flag);
    }
    else

    return;
}

int main()
{
    int n,flag;
    printf("\n Manual Entry or Random: Enter 1 for Manual :");
    scanf("%d",&flag);
    if(flag==1)
    {
        printf("\n Enter the size: ");
        scanf("%d",&n);
        int a[n];
        printf("\n Enter %d Elements: ",n);
        for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
        func(a, 0, n - 1, n, flag);
    }
    else{
        n=500;
        int a[0];
        func(a, 0, n - 1, n, flag);
    }

    return 0;
}


