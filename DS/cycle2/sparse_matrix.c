#include <stdio.h>
struct matrix{
    int row;
    int col;
    int value;
}M[20],N[20],Mt[20],Nt[20],A[20];
void main()
{
    int i,j,l=1,val,terms[10],start[10];
    printf("Enter no.of rows of matrix: ");
    scanf("%d",&M[0].row);
    printf("Enter no.of columns of matrix: ");
    scanf("%d",&M[0].col);
    printf("Enter matrix:\n");
    for (i=0;i<M[0].row;i++)
        for (j=0;j<M[0].col;j++)
        {
            scanf("%d",&val);
            if (val!=0)
            {
                M[l].row=i;
                M[l].col=j;
                M[l].value=val;
                l++;
            }
            M[0].value=l-1;
        }
    l=1;
    printf("Enter no.of rows of matrix: ");
    scanf("%d",&N[0].row);
    printf("Enter no.of columns of matrix: ");
    scanf("%d",&N[0].col);
    printf("Enter matrix:\n");
    for (i=0;i<N[0].row;i++)
        for (j=0;j<N[0].col;j++)
        {
            scanf("%d",&val);
            if (val!=0)
            {
                N[l].row=i;
                N[l].col=j;
                N[l].value=val;
                l++;
            }
            N[0].value=l-1;
        }
    for (i=0;i<=M[0].value;i++)
        printf("%d %d %d\n",M[i].row,M[i].col,M[i].value);
    printf("\n");
    for (i=0;i<=N[0].value;i++)
        printf("%d %d %d\n",N[i].row,N[i].col,N[i].value);
    printf("\n");
    Mt[0].row=M[0].col;
    Mt[0].col=M[0].row;
    Mt[0].value=M[0].value;
    for (i=0;i<M[0].col;i++)
        terms[i]=0;
    for (i=1;i<=M[0].value;i++)
        terms[M[i].col]++;
    start[0]=1;
    for (i=1;i<M[0].col;i++)
        start[i]=start[i-1]+terms[i-1];
    for (i=1;i<=M[0].value;i++)
    {
        j=start[M[i].col]++;
        Mt[j].row=M[i].col;
        Mt[j].col=M[i].row;
        Mt[j].value=M[i].value;
    }
    for (i=0;i<=Mt[0].value;i++)
        printf("%d %d %d\n",Mt[i].row,Mt[i].col,Mt[i].value);
    printf("\n");
    {
        i=j=l=1;
        while (i<=M[0].value && j<=N[0].value)
        {
            if ((M[i].row<N[j].row) || (M[i].row==N[j].row && M[i].col<N[j].col))
            {
                A[l]=M[i];
                i++;
            }
            else if ((M[i].row>N[j].row) || (M[i].row==N[j].row && M[i].col>N[j].col))
            {
                A[l]=N[j];
                j++;
            }
            else
            {
                A[l].row=M[j].row;
                A[l].col=M[j].col;
                A[l].value=M[j].value+N[j].value;
                i++;
                j++;
            }
            l++;
        }
        while (i<=M[0].value)
        {
            A[l]=M[i];
            l++;
            i++;
        }
        while (j<=N[0].value)
        {
            A[l]=N[j];
            l++;
            j++;
        }

        
        A[0].value=l-1;
        for (i=0;i<=A[0].value;i++)
            printf("%d %d %d\n",A[i].row,A[i].col,A[i].value);
    }
}