#include <stdio.h>
#include <string.h>
void main()
{
    char strtab[20][20],*s,temp[20];
    int n,i,j,k=0,l,p;
    printf("Enter the number of strings in table: ");
    scanf("%d",&n);
    printf("Enter the strings:\n");
    for (i=0;i<n;i++)
        scanf(" %[^\n]",strtab[i]);
    for (i=0;i<n;i++)
    {
        s=strtab[i];
        l=strlen(s);
        for (j=l-1;j>=0;j--)
        {
            temp[k]=*(s+j);
            k++;
        }
        strcpy(strtab[i],temp);
    }
    printf("Enter sorting preference\n1.Alphabetical order\n2.Reverse alphabetical order\nEnter option: ");
    scanf("%d",&p);
    if (p==1)
    {
        for (i=0;i<n;i++)
            for (j=0;j<n-i-1;j++)
                if (strcasecmp(strtab[j],strtab[j+1])>0)
                {
                    strcpy(temp,strtab[j]);
                    strcpy(strtab[j],strtab[j+1]);
                    strcpy(strtab[j+1],temp);
                }
        for (i=0;i<n;i++)
            printf("%s\n",strtab[i]);     
    }
    else if (p==2)
    {
        for (i=0;i<n;i++)
            for (j=0;j<n-i-1;j++)
                if (strcasecmp(strtab[j],strtab[j+1])<0)
                {
                    strcpy(temp,strtab[j]);
                    strcpy(strtab[j],strtab[j+1]);
                    strcpy(strtab[j+1],temp);
                }
        for (i=0;i<n;i++)
            printf("%s\n",strtab[i]);  
    }
    else
        printf("Invalid option\n");
}