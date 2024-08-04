#include <stdio.h>
int StringLengh(char *s)
{
    int l;
    for (l=0;*s!='\0';l++);
    return l;
}
void StringCopy(char *s1, char *s2)
{
    int i;
    for (i=0;*s1!='\0';i++)
        *s1=*s2;
}
int StringCompare (char *s1, char *s2)
{
    int i;
    if (*s1>*s2)
        return 1;
    else if (*s1<*s2)
        return -1;
    return 0;
}
void StringConcat(char *s1, char *s2)
{
    int i;
    for (i=0;*s1!='\0';i++);
    while (*s2!='\0')
    {
        *s1=*s2;
        s1++;s2++;
    }
    *s1='\0';
}
void main()
{
    int n;
    char str1[20],str2[20];
    printf("1.Length of string\n2.String Copying\n3.String Comparison\n4.String Concatenation\nSelect option: ");
    scanf("%d",&n);
    switch(n)
    {
        case 1:printf("Enter string: ");
               scanf(" [^\n]",str1);
               printf("Length of string: %d\n",StringLengh(str1));
               break;
        case 2:printf("Enter string: ");
               scanf(" [^\n]",str1);
               StringCopy(str1,str2);
               printf("String 2 after copying: %s\n",str2);
               break;
        case 3:printf("Enter string 1: ");
               scanf(" [^\n]",str1);
               printf("Enter string 2: ");
               scanf(" [^\n]",str2);
               if (StringCompare(str1,str2)>0)
                    printf("String 1 is greater\n");
               else if (StringCompare(str1,str2)<0)
                    printf("String 2 is greater\n");
               else
                    printf("Both strings are equal\n");
               break;
        case 4:printf("Enter string 1: ");
               scanf(" [^\n]",str1);
               printf("Enter string 2: ");
               scanf(" [^\n]",str2);
               StringConcat(str1,str2);
               printf("Concatenated string: %s",str1);
               break;
        default:printf("Invalid option\n");
                break;
    }
}