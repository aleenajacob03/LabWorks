#include <stdio.h>
int large_array(int num,int M[])
{
    int large,i;
    large=M[0];
    for (i=1;i<num;i++)
        if (M[i]>large)
            large=M[i];
    return large;
}
void main()
{
    int m,n,A[10][10],i,j,large;
    printf("Enter no.of rows and columns: ");
    scanf("%d%d",&m,&n);
    printf("Enter the matrix:\n");
    for (i=0;i<m;i++)
        for (j=0;j<n;j++)
            scanf("%d",&A[i][j]);
    printf("Largest elements in each row of matrix are:\n");
    for (i=0;i<m;i++)
    {
        large=large_array(n,A[i]);
        printf("Row %d: %d\n",i+1,large);
    }
}