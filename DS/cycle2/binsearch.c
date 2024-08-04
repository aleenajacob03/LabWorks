#include <stdio.h>
void main()
{
    FILE *f;
    int n=0,first=0,last,mid;
    char ch,word[10];
    f=fopen("","r");
    while (ch=fgetc(f)!=EOF)
    {
        if 
    }
    last=n-1;
    printf("Enter string to search: ");
    scanf("%s",word);
    while (first<=last)
    {
        mid=(first+last)/2;
        if (strcmp(word,A[mid])>0)
            first=mid+1;
        else if (strcmp(word,A[mid])<0)
            last=mid-1;
        else
            printf("String found at position %d/n",mid+1);
    }
    if (first>last)
        printf("String not found\n");
    fclose(f);
}