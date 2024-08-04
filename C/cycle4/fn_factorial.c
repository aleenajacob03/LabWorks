#include <stdio.h>
int fact(int num)
{
    if (num==0 || num==1)
        return 1;
    else
        return (num*fact(num-1));
}
void main()
{
    int n,r,n_fact,r_fact,nr_fact;
    float nCr;
    printf("Enter the values of n and r: ");
    scanf("%d%d",&n,&r);
    n_fact=fact(n);
    r_fact=fact(r);
    nr_fact=fact((n-r));
    nCr=n_fact/(r_fact*nr_fact);
    printf("nCr=%ld\n",nCr);
}