#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char bitmask[12],bit[12];
void convert(char h[])
{
    int i,l;
    strcpy(bit,"");
    l=strlen(h);
    for (i=0;i<l;i++)
    {
        switch (h[i])
        {
            case '0':strcat(bit,"0");
                break;
            case '1':strcat(bit,"1");
                break;
            case '2':strcat(bit,"10");
                break;
            case '3':strcat(bit,"11");
                break;
            case '4':strcat(bit,"100");
                break;
            case '5':strcat(bit,"101");
                break;
            case '6':strcat(bit,"110");
                break;
            case '7':strcat(bit,"111");
                break;
            case '8':strcat(bit,"1000");
                break;
            case '9':strcat(bit,"1001");
                break;
            case 'A':strcat(bit,"1010");
                break;
            case 'B':strcat(bit,"1011");
                break;
            case 'C':strcat(bit,"1100");
                break;
            case 'D':strcat(bit,"1101");
                break;
            case 'E':strcat(bit,"1110");
                break;
            case 'F':strcat(bit,"1111");
                break;
        }
    }
}
void main()
{
    FILE *f1,*f2;
    f1=fopen("relin.txt","r");
    f2=fopen("relout.txt","w+");
    int start,length,reloc,len,i,opc,add;
    char in[20],name[10];
    printf("Enter starting address: ");
    scanf("%x",&reloc);
    fscanf(f1,"%s",in);
    while(strcmp(in,"E")!=0)
    {
        if (strcmp(in,"H")==0)
        {
            fscanf(f1,"%s %x %x",name,&start,&length);
            printf("H^%s^%06x^%06x\n",name,reloc,length);
        }
        else if (strcmp(in,"T")==0)
        {
            fscanf(f1,"%x %x %s",&start,&length,bitmask);
            printf("T^%06x^%06x",start+reloc,length);
            convert(bitmask);
            len=strlen(bit);
            if (len>=11)
                len=10;
            for (i=0;i<len;i++)
            {
                fscanf(f1,"%x %x",&opc,&add);
                if (bit[i]=='1')
                    add+=reloc;
                printf("^%02x%04x",opc,add);
            }
            printf("\n");
        }
        fscanf(f1,"%s",in);
    }
    printf("E^%06x\n",reloc);
}