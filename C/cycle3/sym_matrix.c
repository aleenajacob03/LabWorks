#include <stdio.h>
void main()
{
    int n,A[10][10],i,j;
    printf("Enter the order of matrix: ");
    scanf("%d",&n);
    printf("Enter %d values: ",(n*n));
    for (i=0;i<n;i++)
        for (j=0;j<n;j++)
            scanf("%d",&A[i][j]);
    for (i=0;i<n;i++)
    {
        for (j=n-1;j>i;j--)
            if (A[i][j]!=A[j][i])
                break;
        if (j!=i)
            break;
    }
    if (i==n)
        printf("The square matrix is symmetric\n");
    else
    {
        printf("The square matrix is not symmetric\nTranspose of matrix is:\n");
        for (i=0;i<n;i++)
        {
            for (j=0;j<n;j++)
                printf("%d ",A[j][i]);
        printf("\n");
        }
    }
}