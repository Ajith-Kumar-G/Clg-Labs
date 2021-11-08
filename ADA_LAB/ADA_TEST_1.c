#include<stdio.h>
#include<time.h>
#include<stdlib.h>

void delay(unsigned int);
void insertionSort(int [],int);

int main()
{
    int n,flag;
    printf("\n Enter the size: ");
    scanf("%d",&n);
    int arr[n];
    printf("\n Manual or Automatic(1): ");
    scanf("%d",&flag);
    if(flag!=1){
    printf("\n Enter the Elements: ",n);
    for(int i=0;i<n;i++)
    scanf("%d",&arr[i]);
    }
    else{
        for(int i=0;i<n;i++)
            arr[i]=rand();
    }
    clock_t t=clock();
    insertionSort(arr,n);
    t=clock()-t;

    double time_taken = ((double)t)/CLOCKS_PER_SEC;
    printf("\n Time of Execution :  %f \n ",time_taken);

    for(int i=0;i<n;i++)
        printf("%d ",arr[i]);

    return 0;
}

void insertionSort(int arr[], int n)
{
    int i, j,temp;
    for (i = 1; i < n; i++)
    {
        temp = arr[i];
        j=i-1;
        while (j >= 0 && arr[j] > temp) {
            arr[j + 1] = arr[j];
            //delay(100);
            j = j - 1;

        }
        arr[j + 1] = temp;
    }

}

void delay(unsigned int mseconds)
{
    clock_t goal = mseconds + clock();
    while (goal > clock());
}


