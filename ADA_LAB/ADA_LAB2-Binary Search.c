#include<time.h>
#include<stdio.h>
#include<stdlib.h>

int binarySearch(int [],int,int,int);
void delay(unsigned int);
int main()
{
    int key=-99,index,n=500;
    clock_t t;
    for(n;n<=5000;n=n+500)
    {
    int list[n];
    for(int i=0;i<n;i++)
        list[i]=i;
    t=clock();
    index=binarySearch(list,key,0,n-1);
    t=clock()-t;
    if(index>=0)
    printf("\n Key was found at index = %d",index);
    else
    printf("\n Key was not found in List");

    double time_taken = ((double)t)/CLOCKS_PER_SEC;
    printf("\n Time of Execution for N=%d is  %f ",n,time_taken);
    }
    return 0;
}
int binarySearch(int list[],int key,int beG,int enD)
{
    int miD=(beG+enD)/2;
    delay(1);

    if(beG>enD)
        return -1;

    if(list[miD]==key)
        return miD;
    if(list[miD]>key)
    return binarySearch(list,key,beG,miD-1);
    else
    return binarySearch(list,key,miD+1,enD);

}
void delay(unsigned int mseconds)
{
    clock_t goal = mseconds + clock();
    while (goal > clock());
}
