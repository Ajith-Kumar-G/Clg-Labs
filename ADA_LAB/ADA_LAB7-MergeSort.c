#include <stdio.h>
#include <stdlib.h>
#include<time.h>

void mergeThem(int a[], int l, int m, int r)
{
    int i, j, k, n1 = m - l + 1, n2 = r - m;

    int LA[n1], RA[n2];
    for (i = 0; i < n1; i++)
        LA[i] = a[l + i];
    for (j = 0; j < n2; j++)
        RA[j] = a[m + 1 + j];
    i = 0; j = 0; k = l;
    while (i < n1 && j < n2) {
        if (LA[i] <= RA[j]) {
            a[k] = LA[i];
            i++;
        }
        else {
            a[k] = RA[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        a[k] = LA[i];
        i++;
        k++;
    }
    while (j < n2) {
        a[k] = RA[j];
        j++;
        k++;
    }
}

void mergeSort(int a[], int l, int r)
{
    if (l < r)
    {
        int m = ( l + r) / 2;
        mergeSort(a, l, m);
        mergeSort(a, m + 1, r);
        mergeThem(a, l, m, r);
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
    mergeSort(list,l,r);
    t=clock()-t;
    }
    else{
    t=clock();
    mergeSort(a,l,r);
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
        printf("\n Enter %d Elements: ");
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
