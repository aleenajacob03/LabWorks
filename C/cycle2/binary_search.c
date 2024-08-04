#include <stdio.h>
void main()
{
    int n,A[20],i,key,top,bot,mid,pre=0;
    printf("Enter the numbers of terms: ");
    scanf("%d",&n);
    printf("Enter the sorted array: ");
    for (i=0;i<n;i++)
        scanf("%d",&A[i]);
    printf("Enter the key: ");
    scanf("%d",&key);
    top=0;
    bot=n-1;
    while (top<=bot)
    {
        mid=(top+bot)/2;
        if (A[mid]==key)
        {
            printf("Present in list at postion %d\n",mid+1);
            pre=1;
            break;
        }
        else if (key<A[mid])
            bot=mid-1;
        else   
            top=mid+1;
    }
    if (!pre)
        printf("Not present in list\n"); 
}