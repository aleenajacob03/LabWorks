#include <stdio.h>
#include <string.h>
void main()
{
    int i=0;
    char s1[10]="Ardra",s2[10]="Jovita";
    printf("%d\n",strcmp(s1,s2));
    while (s1[i]!='\0' && s2[i]!='\0' && s1[i]==s2[i])
        i++;
    printf("%d\n",s1[i]-s2[i]);
}