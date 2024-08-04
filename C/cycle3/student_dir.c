#include <stdio.h>
#include <string.h>
void main()
{
    char S[50][30],temp[30];
    int n,i,j;
    printf("Enter the number of studemts in class: ");
    scanf("%d",&n);
    printf("Enter student names:\n");
    for (i=0;i<n;i++)
        scanf("%[ ^\n]",S[i]);
    for (i=0;i<n-1;i++)
        for (j=i+1;j<n;j++)
            if (strcasecmp(S[i],S[j])>0)
            {
                strcpy(temp,S[i]);
                strcpy(S[i],S[j]);
                strcpy(S[j],temp);
            }
    printf("Sorted list is:\n");
    for (i=0;i<n;i++)
        printf("%s\n",S[i]);
}