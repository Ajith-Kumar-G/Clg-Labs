#include<stdio.h>
#include<math.h>
int gcd(int,int);

int main()
{
    int a,b;
    printf("\n Enter the Two Numbers: ");
    scanf("%d%d",&a,&b);
    printf("\n The GCD(HCF) of %d and %d is %d ",a,b,abs(gcd(a,b)));
    return 0;
}
int gcd(int x,int y)
{
    if(y!=0)
        return gcd(y, x%y);
    else
        return x;
}
