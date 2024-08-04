#include <stdio.h>
void main()
{
    int m,n,i,j,l,A[10],B[10],C[10];
    printf("Enter no.of elements in array 1: ");
    scanf("%d",&m);
    printf("Enter sorted array: ");
    for (i=0;i<m;i++)
        scanf("%d",&A[i]);
    printf("Enter no.of elements in array 2: ");
    scanf("%d",&n);
    printf("Enter sorted array: ");
    for (i=0;i<n;i++)
        scanf("%d",&B[i]);
    i=j=l=0;
    while (i<m && j<n)
    {
        if (A[i]<B[j])
        {
            C[l]=A[i];
            i++;
        }
        else
        {
            C[l]=B[j];
            j++;
        }
        l++;
    }
    while (i<m)
    {
        C[l]=A[i];
        l++;
        i++;
    }
    while (j<n)
    {
        C[l]=B[j];
        l++;
        j++;
    }
    printf("Merge Sorted array: ");
    for (i=0;i<l;i++)
        printf("%d ",C[i]);
    printf("\n");
}