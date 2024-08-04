#include <stdio.h>
int pal_check(char s[])
{
    int i=0,l=0;
    while (s[l]!='\0')
        l++;
    while (i<l)
    {
        if (s[i]!=s[l-1])
            return 0;
        i++;
        l--;
    }
    return 1;
}
void main()
{
    char l[30],w[10];
    int i=0,j,present=1;
    printf("Enter line of text: ");
    scanf("%[^\n]",l);
    while (l[i]!='\0')
    {
        j=0;
        while (l[i]!=' ' && l[i]!='\0')
        {
            w[j]=l[i];
            j++;
            i++;
        }
        w[j]='\0';
        if (pal_check(w))
        {
            if (present)
            {
                printf("Pallindrome words in line are:\n");
                present=0;
            }
            printf("%s\n",w);
        }
        i++;
    }
    if (present)
        printf("No pallindrome words in line of text\n");
}