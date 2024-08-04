#include <stdio.h>
struct poly {
    int coef;
    int exp;
};
struct poly read_poly(int n,struct poly P[])
{
    int i,t;
    printf("Enter polynomial %d\nNumber of terms: ",n);
    scanf("%d",&t);
    for (i=t-1;i>=0;i--)
    {
        P[i].exp=i;
        printf("Coefficient of x^%d: ",i);
        scanf("%d",&P[i].coef);
    }
}
void main()
{
    struct poly P1[10],P2[10];
    int m,n,i,sum[10];
    printf("Sum of polynomials is: ");
    for (i=n-1;i>=0;i--)
    {
        sum[i]=P1[i].coef+P2[i].coef;
        if (i==0)
            printf("%dx^%d\n",sum[i],P1[i].exp);
        else
            printf("%dx^%d+",sum[i],P1[i].exp);
    }
}