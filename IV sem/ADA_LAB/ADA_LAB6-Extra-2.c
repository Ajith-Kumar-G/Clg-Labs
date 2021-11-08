#include <stdio.h>

int findPivot(int[], int, int);
int bSearch(int[], int, int, int);

int pBinSearch(int arr[], int n, int key)
{
    int pivot = findPivot(arr, 0, n - 1);
    if (pivot == -1)
        return bSearch(arr, 0, n - 1, key);
    if (arr[pivot] == key)
        return pivot;
    if (arr[0] <= key)
        return bSearch(arr, 0, pivot - 1, key);
    return bSearch(arr, pivot + 1, n - 1, key);
}
int findPivot(int arr[], int beg, int end)
{

    if (end < beg)
        return -1;
    if (end == beg)
        return beg;

    int mid = (beg + end) / 2;
    if (mid < end && arr[mid] > arr[mid + 1])
        return mid;
    if (mid > beg && arr[mid] < arr[mid - 1])
        return (mid - 1);
    if (arr[beg] >= arr[mid])
        return findPivot(arr, beg, mid - 1);
    return findPivot(arr, mid + 1, end);
}

int bSearch(int arr[], int beg, int end, int key)
{
    if (end < beg)
        return -1;
    int mid = (beg + end) / 2;
    if (key == arr[mid])
        return mid;
    if (key > arr[mid])
        return bSearch(arr, (mid + 1), end, key);
    return bSearch(arr, beg, (mid - 1), key);
}


int main()
{
    int n,key;
    printf("\n Enter the Length of Array:  ");
    scanf("%d",&n);
    int a[n];
    printf("\n Enter %d Elements: ",n);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    printf("\n Enter the Key:  ");
    scanf("%d",&key);

    printf("\n Index of the element %d is : %d",key, pBinSearch(a, n, key));
    return 0;
}

//8 9 10 1 2 3 4
