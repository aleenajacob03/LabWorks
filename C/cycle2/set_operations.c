#include <stdio.h>
void main()
{
    int m,n,l,A[20],B[20],C[50],i,j;
    printf("Enter no.of terms in set A: ");
    scanf("%d",&m);
    printf("Enter the set: ");
    for (i=0;i<m;i++)
        scanf("%d",&A[i]);
    printf("Enter no.of terms in set B: ");
    scanf("%d",&n);
    printf("Enter the set: ");
    for (i=0;i<n;i++)
        scanf("%d",&B[i]);
    
    for (l=0;l<m;l++)
        C[l]=A[l];
    for (i=0;i<n;i++)
    {
        for (j=0;j<l;j++)
            if (C[j]==B[i])
                break;
        if (j==l)
        {
            C[l]=B[i];
            l++;
        }
    }    
    printf("A or B: { ");
    for (i=0;i<l;i++)
        printf("%d ",C[i]);
    printf("}\n");

    l=0;
    for (i=0;i<m;i++)
        for (j=0;j<n;j++)
            if (A[i]==B[j])
            {
                C[l]=A[i];
                l++;
            }
    printf("A and B: { ");
    for (i=0;i<l;i++)
        printf("%d ",C[i]);
    printf("}\n");

    l=0;
    for (i=0;i<m;i++)
    {
        for (j=0;j<n;j++)
            if (A[i]==B[j])
                break;
            if (j==n)
            {
                C[l]=A[i];
                l++;
            }
    }
    printf("A-B: { ");
    for (i=0;i<l;i++)
        printf("%d ",C[i]);
    printf("}\n");
}