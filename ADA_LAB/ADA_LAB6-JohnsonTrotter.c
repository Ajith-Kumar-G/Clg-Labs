#include<stdio.h>
#include<stdlib.h>

int LR = 1;
int RL = 0;
void swap(int *, int *);

int searchArr(int a[], int n, int mobile)
{
    for (int i = 0; i < n; i++)
        if (a[i] == mobile)
           return i + 1;
}


int getMobile(int a[], int dir[], int n)
{
    int prevMobile = 0, mobile = 0;
    for (int i = 0; i < n; i++)
    {
        if (dir[a[i]-1] == RL && i!=0)
        {
            if (a[i] > a[i-1] && a[i] > prevMobile)
            {
                mobile = a[i];
                prevMobile = mobile;
            }
        }

        if (dir[a[i]-1] == LR && i!=n-1)
        {
            if (a[i] > a[i+1] && a[i] > prevMobile)
            {
                mobile = a[i];
                prevMobile = mobile;
            }
        }
    }

    if (mobile == 0 && prevMobile == 0)
        return 0;
    else
        return mobile;
}


int printPermut(int a[], int dir[], int n)
{
    int mobile = getMobile(a, dir, n);
    int pos = searchArr(a, n, mobile);

    if (dir[a[pos - 1] - 1] ==  RL)
       swap(&a[pos-1], &a[pos-2]);

    else if (dir[a[pos - 1] - 1] == LR)
       swap(&a[pos], &a[pos-1]);

    for (int i = 0; i < n; i++)
    {
        if (a[i] > mobile)
        {
            if (dir[a[i] - 1] == LR)
                dir[a[i] - 1] = RL;
            else if (dir[a[i] - 1] == RL)
                dir[a[i] - 1] = LR;
        }
    }

    for (int i = 0; i < n; i++)
        printf("%d",a[i]);
    printf("\n ");
}

void swap(int *x, int *y)
{
    int temp=*x;
    *x=*y;
    *y=temp;
}
int fact(int n)
{
    int r = 1;
    for (int i = 1; i <= n; i++)
        r = r * i;
    return r;
}

void johnsonTrotter(int n)
{
    int a[n];
    int dir[n];

    for (int i = 0; i < n; i++)
    {
        a[i] = i + 1;
        printf("%d",a[i]);
    }
   printf("\n ");

    for (int i = 0; i < n; i++)
        dir[i] =  RL;

    for (int i = 1; i < fact(n); i++)
        printPermut(a, dir, n);
}

int main()
{
    int n ;
    printf("\n Enter the Number: ");
    scanf("%d",&n);
    printf("\n ");
    johnsonTrotter(n);
    return 0;
}
