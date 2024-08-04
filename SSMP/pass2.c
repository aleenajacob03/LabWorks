#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void main()
{
    FILE *f1,*f2,*f3,*f4;
    f1=fopen("inter.txt","r");
    f4=fopen("output.txt","w+");
    int start,locctr,i,l,count=0;
    char name[10],opc[10],lb[10],opr[10],op[10],obj[4],ob[4],temp[4],rec[20],textrec[100]="";
    fscanf(f1,"%s %s %x",name,opc,&start);
    fscanf(f1,"%x %s %s %s",&locctr,lb,opc,opr);
    while(!feof(f1))
    {
        if (strcmp(opc,"WORD")==0)
        {
            strcat(textrec,"^");
            strcat(textrec,opr);
            count+=strlen(opr);
        }
        else if (strcmp(opc,"BYTE")==0)
        {
            strcat(textrec,"^");
            l=strlen(opr);
            for(i=2;i<l;i++)
            {
                sprintf(rec,"%x",opr[i]);
                strcat(textrec,rec);
            }
            count+=(l-2);
        }
        else if (strcmp(opc,"RESB")!=0 && strcmp(opc,"RESW")!=0)
        {
            f2=fopen("optab.txt","r");
            fscanf(f2,"%s %s",op,obj);
            while(!feof(f2))
            {
                if (strcmp(op,opc)==0)
                {
                    strcpy(temp,obj);
                    break;
                }
                fscanf(f2,"%s %s",op,obj);
            }
            f3=fopen("symtab.txt","r");
            fscanf(f3,"%s %s",ob,op);
            while (!feof(f3))
            {
                if (strcmp(op,opr)==0)
                    break;
                fscanf(f3,"%s %s",ob,op);
            }
            sprintf(rec,"^%s%s",temp,ob);
            strcat(textrec,rec);
            count+=3;
        }
        fscanf(f1,"%x %s %s %s",&locctr,lb,opc,opr);
    }
    printf("H^%s^%06x^%06x\nT^%06x^%06x%s\nE^%x\n",name,start,(locctr+3-start),start,count,textrec,start);
    fprintf(f4,"H^%s^%06x^%06x\nT^%06x^%06x%s\nE^%x\n",name,start,(locctr+3-start),start,count,textrec,start);
    fclose(f1);
    fclose(f2);
    fclose(f3);
    fclose(f4);
}