#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void main()
{
    FILE *f1;
    f1=fopen("absin.txt","r");
    int start,length,l,i;
    char in[100];
    printf("Address\t\tContent\n");
    fscanf(f1,"%s",in);
    while(strcmp(in,"E")!=0)
        if (strcmp(in,"T")==0)
        {
            fscanf(f1,"%x %x %s",&start,&length,in);
            while(strcmp(in,"T")!=0 && strcmp(in,"E")!=0)
            {
                l=strlen(in);
                for (i=0;i<l;i=i+2)
                {
                    printf("%x\t\t%c%c\n",start,in[i],in[i+1]);
                    start++;
                }
                fscanf(f1,"%s",in);
            }
        }
        else
            fscanf(f1,"%s",in);
}