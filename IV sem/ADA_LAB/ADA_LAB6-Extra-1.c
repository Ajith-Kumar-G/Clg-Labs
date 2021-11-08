#include<stdio.h>
#include<stdlib.h>
int binarySearch(int [],int ,int ,int);
int main()
{
    int a[] = { 1, 2, 2, 2, 2, 3, 4, 7, 8, 8 },n=10;
    int key,firstOcc=-1,lastOcc=-1,count=0;
    printf("\n Enter the Key: ");
    scanf("%d",&key);
    int beg=0,end=n-1;
    firstOcc=binarySearch(a,key,n,1);
    lastOcc=binarySearch(a,key,n,0);
    count=lastOcc-firstOcc+1;
    if(firstOcc>0 && lastOcc>0)
    printf("\n Key: %d\n First Occurrence: %d  last Occurrence: %d  Count: %d",key,firstOcc,lastOcc,count);
    else
    printf("\n The Key is not present!");

}
int binarySearch(int a[],int x,int n,int flag)
{
    int low = 0, high = n - 1, r = -1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (a[mid] > x)
            high = mid - 1;
        else if (a[mid] < x)
            low = mid + 1;

        else
        {
            if(flag==1)
            {
                r = mid;
                high = mid - 1;
            }
            else
                if(flag==0)
            {
                r = mid;
                low = mid + 1;
            }
        }

    }
    return r;
}
