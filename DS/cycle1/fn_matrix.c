#include <stdio.h>
#include <stdlib.h>
void read_matrix(int n,int **M)
{
    int i,j;
    for (i=0;i<n;i++)
        for (j=0;j<n;j++)
            scanf("%d",&M[i][j]);
}
void sum_matrix(int n,int **M1,int **M2)
{
    int i,j,**R;
    R=(int**)malloc(n*sizeof(int));
    for (i=0;i<n;i++)
        R[i]=(int*)malloc(n*sizeof(int));
    for (i=0;i<n;i++)
    {
        for (j=0;j<n;j++)
        {
            R[i][j]=M1[i][j]+M2[i][j];
            printf("%d ",R[i][j]);
        }
        printf("\n");
    }
}
void multiply_matrix(int n,int **M1,int **M2)
{
    int i,j,k,**R;
    R=(int**)malloc(n*sizeof(int));
    for (i=0;i<n;i++)
        R[i]=(int*)malloc(n*sizeof(int));
    for (i=0;i<n;i++)
        for (j=0;j<n;j++)
        {  
            R[i][j]=0;
            for (k=0;k<n;k++)
                R[i][j]+=M1[i][k]*M2[k][j];
            printf("%d ",R[i][j]);
        }
    printf("\n");
}
void transpose_matrix(int n,int **M)
{
    int i,j,temp;
    for (i=0;i<n;i++)
        for (j=n-1;j>i;j--)
        {
            temp=M[i][j];
            M[i][j]=M[j][i];
            M[j][i]=temp;
        }
    for (i=0;i<n;i++)
    {
        for (j=0;j<n;j++)
            printf("%d ",M[i][j]);
        printf("\n");
    }
}
void up_triangular(int n,int **M)
{
    int i,j;
    for (i=0;i<n;i++)
    {
        for (j=0;j<n;j++)
            if (i<=j)
                printf("%d ",M[i][j]);
            else
                printf("  ");
        printf("\n");
    }
}
void dig_matrix(int n,int **M)
{
    int i,j;
    for (i=0;i<n;i++)
        printf("%d ",M[i][i]);
    printf("\n");
}
void main()
{
    int n,**A,**B,i,j,k;
    printf("Enter the order of matrix: ");
    scanf("%d",&n);
    A=(int**)malloc(n*sizeof(int));
    for (i=0;i<n;i++)
        A[i]=(int*)malloc(n*sizeof(int));
    printf("Enter the matrix A:\n");
    read_matrix(n,A);
    B=(int**)malloc(n*sizeof(int));
    for (i=0;i<n;i++)
        B[i]=(int*)malloc(n*sizeof(int));
    printf("Enter the matrix B:\n");
    read_matrix(n,B);
    printf("Sum of matrices:\n");
    sum_matrix(n,A,B);
    printf("Product of matrices:\n");
    multiply_matrix(n,A,B);
    printf("Transpose of matrix A:\n");
    transpose_matrix(n,A);
    printf("Upper triangular matrix of B:\n");
    up_triangular(n,B);
    printf("Diagonal elements of A: ");
    dig_matrix(n,A);
}