#include <stdio.h>
char names[10][10];
int n=0;
void sort()
{
    int x,i,j,k;
    char temp[10];
    for (x=0;x<n;x++)
        for (i=0;i<n-x-1;i++)
        {
            for (j=0;names[i][j]!='\0' && names[i+1][j]!='\0';j++)
                if (names[i][j]!=names[i+1][j])
                    break;
            if ((names[i][j]>names[i+1][j]) || (names[i][j]!='\0' && names[i+1][j]=='\0'))
            {
                for (k=0;temp[k]=names[i][k];k++);
                for (k=0;names[i][k]=names[i+1][k];k++);
                for (k=0;names[i+1][k]=temp[k];k++);
            }
        }
    printf("\nAfter sort:\n");
    for (i=0;i<n;i++)
        printf("%s ",names[i]);
}
void search()
{
    int i,j,f=0,l=n-1,m;
    char strq[10];
    printf("\nEnter word to search: ");
    scanf("%s",strq);
    while (f<l)
    {
        m=(f+l)/2;
        for (j=0;names[m][j]!='\0' && strq[j]!='\0';j++)
            if (names[m][j]<strq[j])
            {
                f=m+1;
                break;
            }
            else if (names[m][j]>strq[j])
            {
                l=m-1;
                break;
            }
        if (names[m][j]=='\0' && strq[j]=='\0')
        {
            printf("Found at position %d\n",m+1);
            return;
        }
        else if (names[m][j]!='\0' && strq[j]=='\0')
            l=m;
    }
    printf("Not found\n");
}
void main()
{
    FILE *fp;
    char ch,strq[50];
    int i;
    fp=fopen("file1.txt","r");
    for (n=0,i=0;(ch=getc(fp))!=EOF;i++)
    {
        if (ch==' ' || ch=='\n')
        {
            names[n++][i]='\0';
            i=-1;
        }
        else
            names[n][i]=ch;
    }
    names[n++][i]='\0';
    for (i=0;i<n;i++)
        printf("%s ",names[i]);
    sort();
    search();
    fclose(fp);
}