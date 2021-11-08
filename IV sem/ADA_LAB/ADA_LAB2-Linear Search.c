#include<time.h>
#include<stdio.h>
#include<stdlib.h>

int linearSearch(int [], int, int);
void delay(unsigned int);

int main()
{
    int key,index,n=500;
    clock_t t;
    for(n;n<=5000;n=n+500)
    {
    int list[n];
    for(int i=0;i<n;i++)
        list[i]=rand();
    key=-1;
    t=clock();
    index=linearSearch(list,key,n);
    t=clock()-t;
    if(index>=0)

    printf("\n Key was found at index=%d",index);
    else
    printf("\n Key element Not found in List!\n");

    double time_taken = ((double)t)/CLOCKS_PER_SEC;
    printf(" Time of Execution for n=%d : %f ",n,time_taken);
    }

    return 0;
}

int linearSearch(int a[], int key,int s)
{
    if(s<0)
        return -1;

    if(key==a[s])
        return s;
    delay(1);
    return linearSearch(a,key,s-1);

}
void delay(unsigned int mseconds)
{
    clock_t goal = mseconds + clock();
    while (goal > clock());
}

