#include <stdio.h>
void main()
{
    int n,A[20],i,key,pre=0;
    printf("Enter the nnumbers of terms: ");
    scanf("%d",&n);
    printf("Enter %d numbers: ",n);
    for (i=0;i<n;i++)
        scanf("%d",&A[i]);
    printf("Enter the key: ");
    scanf("%d",&key);
    for (i=0;i<n;i++)
        if (A[i]==key)
        {
            printf("Present in list at position %d\n",i+1);
            pre=1;
            break;
        } 
    if (!pre)
        printf("Not present in list\n");          
}