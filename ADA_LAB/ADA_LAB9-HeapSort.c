#include <stdio.h>
#include <stdlib.h>
#include<time.h>

  void swap(int *a, int *b)
  {
    int temp = *a;
    *a = *b;
    *b = temp;
  }

  void heapit(int A[], int n, int i)
  {
    int largest = i;
    int lChild = 2 * i + 1;
    int rChild = lChild+1;

    if (lChild < n && A[lChild] > A[largest])
      largest = lChild;

    if (rChild < n && A[rChild] > A[largest])
      largest = rChild;

    if (largest != i)
     {
        swap(&A[i], &A[largest]);
        heapit(A, n, largest);
     }
  }

  void heapSort(int A[], int n)
  {
    for (int i = n / 2 - 1; i >= 0; i--)
      heapit(A, n, i);

    for (int i = n - 1; i >= 0; i--)
    {
      swap(&A[0], &A[i]);
      heapit(A, i, 0);
    }
  }

  void func(int A[],int n,int flag)
{
    clock_t t;
    if(flag!=1)
    {
        int list[n];
        for(int i=0;i<n;i++)
            list[i]=rand();
        t=clock();
        heapSort(list,n);
        t=clock()-t;
    }

    else{
    t=clock();
    heapSort(A, n);
    t=clock()-t;
    }

    double time_taken = ((double)t)/CLOCKS_PER_SEC;
    printf("\n Time of Execution For N=%d is  %f ",n,time_taken);
    if(flag==1){
    printf("\n Sorted array is \n");
    for (int i = 0; i < n; i++)
        printf(" %d ", A[i]);
    }
    if(n<=5000 && flag!=1)
    {
        n+=500;
         func(A,n,flag);
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
        int A[n];
        printf("\n Enter %d Elements: ",n);
        for(int i=0;i<n;i++)
        scanf("%d",&A[i]);
        func(A,n,flag);
    }
    else{
        n=500;
        int A[0];
        func(A,n,flag);
    }

    return 0;
}


  //5 23 1 2 6 10
