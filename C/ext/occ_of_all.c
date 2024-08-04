#include <stdio.h>
void main()
{
    int n,A[10],i,j,k,l,C[10],count;
    printf("Enter the nnumbers of terms: ");
    scanf("%d",&n);
    printf("Enter %d numbers: ",n);
    for (i=0;i<n;i++)
        scanf("%d",&A[i]);
    l=0;
    for (i=0;i<n;i++)
    {
        for (j=0;j<l;j++)
            if (C[j]==A[i])
                break;
        if (j==l)   
        {
            count=0;
            for (k=0;k<n;k++)
                if (A[k]==A[i])
                    count++;
            printf("Count of element %d: %d\n",A[i],count);
            C[l]=A[l];
            l++;
        }
    }
}