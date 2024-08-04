#include <stdio.h>
#include <math.h>
void main()
{
    int n,count=0,fact,num=2,sqnum,r,pre;
    printf("Enter the number of primes required: ");
    scanf("%d",&n);
    printf("The first %d prime numbers are ",n);
    while (count<n)
    {
        pre=0;
        fact=2;
        sqnum=sqrt(num);
        while (fact<=sqnum)
        {
            r=num%fact;
            if (r==0)
            {
                pre=1;
                break;
            }
            else
                fact++;
        }
        if (!pre)
        {
            printf("%d ",num);
            count++;
        }
        num++;
    }
    printf("\n");
}