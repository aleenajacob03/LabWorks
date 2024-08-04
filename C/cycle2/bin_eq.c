#include <stdio.h>
void main()
{
    int dno,bno[20],i,j;
    printf("Enter decimal number: ");
    scanf("%d",&dno);
    for (i=0;dno!=0;i++)
    {
        bno[i]=dno%2;
        dno=dno/2;
    }
    printf("Binary equvalent of the number is ");
    for (j=i-1;j>=0;j--)
        printf("%d",bno[j]);
    printf("\n");
}