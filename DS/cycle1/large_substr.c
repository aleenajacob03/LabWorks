#include <stdio.h>
#include <string.h>
void main()
{
    char s[20],temps[20]="",maxs[20]="";
    int i,j,k,l=0,n;
    printf("Enter the string: ");
    scanf("%s",s);
    for (i=0;s[i]!='\0';i++)
    {
        for(j=0;j<l;j++)
            if (temps[j]==s[i])
            {
                if (strlen(temps)>strlen(maxs))
                    strcpy(maxs,temps);
                break;
            }
        if (j==l)
        {
            temps[l]=s[i];
            l++;
        }
        else
        {
            n=0;
            for (k=j+1;k<l;k++)
            {
                temps[n]=s[k];
                n++;
            }
            l=n;
        }
    }
    printf("The longest substring is %s of length %d\n",maxs,strlen(maxs));
}