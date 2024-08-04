#include <stdio.h>
void main()
{
    int m,n,l,A[20],B[20],C[50],i,j,k;
    printf("Enter no.of terms in A: ");
    scanf("%d",&m);
    printf("Enter the sorted list: ");
    for (i=0;i<m;i++)
        scanf("%d",&A[i]);
    printf("Enter no.of terms in B: ");
    scanf("%d",&n);
    printf("Enter the sorted list: ");
    for (i=0;i<n;i++)
        scanf("%d",&B[i]);
    
    for (l=0;l<m;l++)
        C[l]=A[l];
    for (i=0;i<n;i++)
    {
        for (j=0;j<l;j++)
            if (C[j]<B[i])
                continue;
            else if (C[j]==B[i])
                break;
            else
            {
                for (k=l;k>j;k--)
                    C[k]=C[k-1];
                C[j]=B[i];
                l++;
                break;
            }
        if (j==l)
        {
            C[l]=B[i];
            l++;
        }
    }    
    printf("Merged list: ");
    for (i=0;i<l;i++)
        printf("%d ",C[i]);
    printf("\n");
}