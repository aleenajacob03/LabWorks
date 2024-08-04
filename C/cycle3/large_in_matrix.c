#include <stdio.h>
void main()
{
    int m,n,A[10][10],i,j,large;
    printf("Enter no.of rows and columns: ");
    scanf("%d%d",&m,&n);
    printf("Enter %d values: ",(m*n));
    for (i=0;i<m;i++)
        for (j=0;j<n;j++)
            scanf("%d",&A[i][j]);
    printf("Largest element in matrix is ");
    large=A[0][0];
    for (i=0;i<m;i++)
        for (j=0;j<n;j++)
            if (A[i][j]>large)
                large=A[i][j];
    printf("%d at positions",large);
    for (i=0;i<m;i++)
        for (j=0;j<n;j++)
            if (A[i][j]==large)
                printf(", Row %d  Column %d",i+1,j+1);
    printf("\n");
}