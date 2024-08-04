#include <stdio.h>
void main(int n,int L[])
{
    int small,i;
    small=L[0];
    for (i=0;i<n;i++)
        if (L[i]<small)
            small=L[i];
    printf("Smallest number in list: %d\n",small);
}