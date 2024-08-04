#include <stdio.h>
#include <math.h>
int prime_check(int num)
{
    int fact,sqn;
    sqn=sqrt(num);
    if (num==0 || num==1)
        return 0;
    for (fact=2;fact<=sqn;fact++)
        if (num%fact==0)
            return 0;
    return 1;
}
void main()
{
    int A[10][10],m,n,i,j,present=1;
    printf("Enter the no.of rows and columns: ");
    scanf("%d%d",&m,&n);
    printf("Enter %d elements: ",m*n);
    for (i=0;i<m;i++)
        for (j=0;j<n;j++)
            scanf("%d",&A[i][j]);
    for (i=0;i<m;i++)
        for (j=0;j<n;j++)
            if (prime_check(A[i][j]))
            {
                if (present)
                {
                    printf("Prime numbers in matrix are: ");
                    present=0;
                }
                printf("%d ",A[i][j]);
            }
    if (present)
        printf("No prime numbers in matrix");
    printf("\n");
}