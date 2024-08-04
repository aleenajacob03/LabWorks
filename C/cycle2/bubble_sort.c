#include <stdio.h>
void main()
{
    int n,A[20],i,j,temp;
    printf("Enter the no.of terms in list: ");
    scanf("%d",&n);
    printf("Enter %d numbers: ",n);
    for (i=0;i<n;i++)
        scanf("%d",&A[i]);
    for (i=0;i<n-1;i++)
        for (j=0;j<n-i-1;j++)
            if (A[j]>A[j+1])
            {
                temp=A[j];
                A[j]=A[j+1];
                A[j+1]=temp;
            }
    printf("The sorted list is: ");
    for (i=0;i<n;i++)
        printf("%d ",A[i]);
    printf("\n");
}