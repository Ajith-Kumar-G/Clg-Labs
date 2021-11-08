#include <stdio.h>

int arrayMedian(int a1[], int a2[], int n)
{

int i=0, j=0, count, m1=-1, m2=-1;

for (count = 0; count <= n; count++)
{
    if (i == n)
    { m1 = m2;
    m2 = a2[0];
    break;
    }
    else if (j == n)
    { m1 = m2;
    m2 = a1[0];
    break;
    }
    if (a1[i] <= a2[j])
    { m1 = m2;
    m2 = a1[i];
    i++;
    }
    else
    { m1 = m2;
    m2 = a2[j];
    j++;
    }
}
return (m1 + m2)/2;
}
int main()

{
    int n;
    printf("\n Enter the Size of Array : ");
    scanf("%d",&n);
    int A[n],B[n];
    printf(" Enter Array 1:\n");
    for(int i=0;i<n;i++)
    scanf("%d",&A[i]);
    printf(" Enter Array 2:\n");
    for(int i=0;i<n;i++)
    scanf("%d",&B[i]);
    printf(" Median is : %d", arrayMedian(A, B, n));

 return 0;
}
