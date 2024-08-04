#include <stdio.h>
void main()
{
    char s[30];
    int l=0,i,j,temp;
    printf("Enter the string: ");
    scanf("%[^\n]",s);
    while (s[l]!='\0')
        l++;
    for (i=0;i<l-1;i++)
        for (j=0;j<l-i-1;j++)
            if (s[j]>s[j+1])
            {
                temp=s[j];
                s[j]=s[j+1];
                s[j+1]=temp;
            }
    printf("Sorted string: '");
    /*for (i=0;s[i]!='\0';i++)
        printf("%c",s[i]);
    printf("'\n");*/
    printf("%s\n'",s);
}