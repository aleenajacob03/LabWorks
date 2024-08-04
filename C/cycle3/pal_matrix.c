#include <stdio.h>
void main()
{
    int m,n,A[10][10],i,j,rev,dig,temp,pre=0;
    printf("Enter no.of rows and columns: ");
    scanf("%d%d",&m,&n);
    printf("Enter %d values: ",(m*n));
    for (i=0;i<m;i++)
        for (j=0;j<n;j++)
            scanf("%d",&A[i][j]);
    for (i=0;i<m;i++)
        for (j=0;j<n;j++)
        {
            rev=0;
            temp=A[i][j];
            while (temp!=0)
            {
                dig=temp%10;
                rev=(rev*10)+dig;
                temp=temp/10;
            }
            if (rev==A[i][j])
            {
                if (!pre)
                {
                    printf("The pallimdrome numbers in matrix are:");
                    pre=1;
                }
                printf(" %d",A[i][j]);
            }
        }
    if (!pre)
        printf("No pallindrome numbers in matrix\n");
}