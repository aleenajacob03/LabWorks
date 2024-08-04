#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct modrec{
    int add,len;
};
void main()
{
    struct modrec m[20];
    FILE *f1;
    f1=fopen("modint.txt","r");
    int modloc,count=-1,i=0,l=0,j,val;
    char in[10],rec[10],name[10],start[10],length[10],len[10];
    printf("Enter relocation address: ");
    scanf("%x",&modloc);
    fscanf(f1,"%s",in);
    while(strcmp(in,"E")!=0)
    {
        if (strcmp(in,"M")==0)
            fscanf(f1,"%x %x",&m[i].add,&m[i++].len);
        fscanf(f1,"%s",in);
    }
    i=0;
    fseek(f1,SEEK_SET,0);
    fscanf(f1,"%s",in);
    while(strcmp(in,"E")!=0)
    {
        if (strcmp(in,"H")==0)
        {
            fscanf(f1,"%s %s %s %s",name,start,length,in);
            printf("H^%s^%s^%s\n",name,start,length);
        }
        else if(strcmp(in,"T")==0)
        {
            fscanf(f1,"%s %s",start,len);
            printf("T^%s^%s",start,len);
            fscanf(f1,"%s",in);
            while (strcmp(in,"T")!=0 && strcmp(in,"M")!=0)
            {
                count+=(strlen(in)/2);
                if(count>m[i].add)
                {
                    val=(int)strtol(in,NULL,16);
                    printf("^%x",(val+modloc));
                    i++;
                }   
                else
                    printf("^%s",in);
                fscanf(f1,"%s",in);
            }
            printf("\n");
        }
        else
            fscanf(f1,"%s",in);
    }
    fscanf(f1,"%s",start);
    printf("E^%s",start);
}
