#include <stdio.h>
void read_matrix(int r,int c,int M[][10])
{
    int i,j;
    printf("Enter the matrix:\n");
    for (i=0;i<r;i++)
        for (j=0;j<c;j++)
            scanf("%d",&M[i][j]);
}
int mult_matrix(int n,int r, int c,int M1[][10],int M2[][10],int R[][10])
{
    int i,j,k,pro;
    printf("The matrix A*B is:\n");
    for (i=0;i<r;i++)
        for (j=0;j<c;j++)
        {
            pro=0;
            for (k=0;k<n;k++)
                pro+=M1[i][k]*M2[k][j];
            R[i][j]=pro;
        }
}
void dspl_matrix(int r,int c,int M[][10])
{
    int i,j;
    for (i=0;i<r;i++)
        {
            for (j=0;j<c;j++)
                printf("%d ",M[i][j]);
        printf("\n");
        }
}
void main()
{
    int m,n,p,q,A[10][10],B[10][10],R[10][10];
    printf("Enter no.of rows and columns of matrix A: ");
    scanf("%d%d",&m,&n);
    read_matrix(m,n,A);
    printf("Enter no.of rows and columns of matrix B: ");
    scanf("%d%d",&p,&q);
    read_matrix(p,q,B);
    if (n==p)
    {
        mult_matrix(n,m,q,A,B,R);
        dspl_matrix(m,q,R);
    }
    else
        printf("The given matrices cannot be multiplied\n");
}