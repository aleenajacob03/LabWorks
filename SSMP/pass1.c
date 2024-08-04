#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void main()
{
    FILE *f1,*f2,*f3,*f4;
    f1=fopen("input.txt","r");
    f3=fopen("symtab.txt","w+");
    f4=fopen("inter.txt","w+");
    int locctr,start,obj,opri;
    char name[20],opc[10],opr[10],lb[10],op[10];
    fscanf(f1,"%s %s %x",name,opc,&start);
    if (strcmp(opc,"START")==0)
        locctr=start;
    else
        locctr=0;
    printf("\t%s\t%s\t%x\n",name,opc,locctr);
    fprintf(f4,"\t%s\t%s\t%x\n",name,opc,locctr);
    fscanf(f1,"%s %s %s",lb,opc,opr);
    while(strcmp(opc,"END")!=0)
    {
        printf("%x\t%s\t%s\t%s\n",locctr,lb,opc,opr);
        fprintf(f4,"%x\t%s\t%s\t%s\n",locctr,lb,opc,opr);
        if (strcmp(lb,"-")!=0)
            fprintf(f3,"%x\t%s\n",locctr,lb);
        f2=fopen("optab.txt","r");
        fscanf(f2,"%s %x",op,obj);
        while (!feof(f2))
        {
            if (strcmp(opc,op)==0)
            {
                locctr+=3;
                break;
            }
            fscanf(f2,"%s %x",op,obj);
        }
        if (strcmp(opc,"WORD")==0)
            locctr+=3;
        else if (strcmp(opc,"RESW")==0)
            locctr+=3*(atoi(opr));
        else if (strcmp(opc,"RESB")==0)
            locctr+=atoi(opr);
        else if (strcmp(opc,"BYTE")==0)
            locctr+=strlen(opr)-2;
        fscanf(f1,"%s %s %s",lb,opc,opr);
    }
    printf("Program Length: %x\n",locctr-start);
    fclose(f1);
    fclose(f2);
    fclose(f3);
    fclose(f4);
}