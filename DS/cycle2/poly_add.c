#include <stdio.h>
extern int avail;
struct poly {
    int coef;
    int exp;
}P[50];
struct poly read_poly(int start,int finish)
{
    for (avail=start;avail<finish;avail++)
    {
        printf("Coefficient: ");
        scanf("%d",&P[avail].coef);
        printf("Exponent: ");
        scanf("%d",&P[avail].exp);
    }
    printf("\n");
}
int avail=0;
void main()
{
    int n1,n2,startA=0,finishA,startB,finishB,i,j;
    printf("Enter polynomial 1\nNumber of terms: ");
    scanf("%d",&n1);
    finishA=startB=n1;
    read_poly(startA,finishA);
    printf("Enter polynomial 2\nNumber of terms: ");
    scanf("%d",&n2);
    finishB=n1+n2;
    read_poly(startB,finishB);
    i=startA;
    j=startB;
    while (i<finishA && j<finishB)
    {
        if (P[i].exp<P[j].exp)
        {
            P[avail]=P[j];
            j++;
        }
        else if (P[i].exp>P[j].exp)
        {
            P[avail]=P[i];
            i++;
        }
        else
        {
            P[avail].coef=P[i].coef+P[j].coef;
            P[avail].exp=P[i].exp;
            i++;
            j++;
        }
        avail++;
    }
    while (i<finishA)
    {
        P[avail]=P[i];
        avail++;
        i++;
    }
    while (j<finishB)
    {
        P[avail]=P[j];
        avail++;
        j++;
    }
    printf("Polynomial 1: ");
    for (i=startA;i<finishA-1;i++)
        printf("%dx^%d+",P[i].coef,P[i].exp);
    printf("%dx^%d\n",P[i].coef,P[i].exp);
    printf("Polynomial 2: ");
    for (i=startB;i<finishB-1;i++)
        printf("%dx^%d+",P[i].coef,P[i].exp);
    printf("%dx^%d\n",P[i].coef,P[i].exp);
    printf("Sum of polynomials: ");
    for (i=finishB;i<avail-1;i++)
        printf("%dx^%d+",P[i].coef,P[i].exp);
    printf("%dx^%d\n",P[i].coef,P[i].exp);
}