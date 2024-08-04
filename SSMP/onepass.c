#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void main()
{
    FILE *f1,*f2,*f3,*f4,*f5;
    f1=fopen("input.txt","r");
    f3=fopen("onesymtab.txt","w+");
    f4=fopen("onesymtab1.txt","w+");
    f5=fopen("oneout.txt","w+");
    int start,locctr,i=0,j,len,l[10],count=0;
    char name[10],opc[10],lb[10],opr[10],op[10],obj[10],ob[4];
    fscanf(f1,"%s %s %x",name,opc,&start);
    if (strcmp(opc,"START")==0)
        locctr=start;
    else
        locctr=0;
    fscanf(f1,"%s %s %s",lb,opc,opr);
    while(strcmp(opc,"END")!=0)
    {
        f2=fopen("optab.txt","r");
        fscanf(f2,"%s %s",op,obj);
        while (!feof(f2))
        {
            if (strcmp(opc,op)==0)
            {
                fprintf(f3,"%s *\n",opr);
                fprintf(f5,"%s 0000\n",obj);
                locctr+=3;
            }
            fscanf(f2,"%s %s",op,obj);
        }
        fseek(f3,SEEK_SET,0);
        fscanf(f3,"%s %s",op,ob);
        while(!feof(f3))
        {
            if (strcmp(op,lb)==0)
            {
                fprintf(f4,"%s %x\n",op,locctr);
                l[i++]=locctr;
                count+=3;
            }
            fscanf(f3,"%s %s",op,ob);
        }
        if (strcmp(opc,"WORD")==0)
        {
            fprintf(f5,"%s #\n",opr);
            locctr+=3;
            count+=strlen(opr);
        }
        else if (strcmp(opc,"BYTE")==0)
        {
            fprintf(f5,"%s -\n",opr);
            locctr+=strlen(opr)-2;
            count+=strlen(opr)-2;
        }
        else if (strcmp(opc,"RESW")==0)
            locctr+=3*(atoi(opr));
        else if (strcmp(opc,"RESB")==0)
            locctr+=atoi(opr);
        fscanf(f1,"%s %s %s",lb,opc,opr);
    }
    i=0;
    printf("H^%-6s^%06x^%06x\nT^%06x^%06x",name,start,(locctr-start),start,count);
    fseek(f5,SEEK_SET,0);
    fscanf(f5,"%s %s",opc,opr);
    while(!feof(f5))
    {
        if (strcmp(opr,"0000")==0)
            printf("^%s%x",opc,l[i++]);
        if (strcmp(opr,"#")==0)
            printf("^%s",opc);
        if (strcmp(opr,"-")==0)
        {
            printf("^");
            len=strlen(opc);
            for (j=2;j<len;j++)
                printf("%x",opc[j]);
        }
        fscanf(f5,"%s %s",opc,opr);
    }
    printf("\nE^%06x\n",start);
}