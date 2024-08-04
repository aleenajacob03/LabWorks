#include <stdio.h>
struct stu_det {
    int regno;
    char name[10];
    int mark[4];
}S[60];
void main()
{
    struct stu_det S[60],temp;
    int n,i,j,total[60],ttemp;
    for (i=0;i<n;i++)
        total[i]=0;
    printf("Enter the number of students in class: ");
    scanf("%d",&n);
    printf("Enter student details:\n");
    for (i=0;i<n;i++)
    {
        printf("Student %d:\n",i+1);
        printf("Reg No.: ");
        scanf("%d",&S[i].regno);
        printf("Name: ");
        scanf(" %[^\n]",S[i].name);
        printf("Marks[E,M,S,S]: ");
        for (j=0;j<4;j++)
            scanf("%d",&S[i].mark[j]);
    }
    for (i=0;i<n;i++)
        for (j=0;j<4;j++)
            total[i]+=S[i].mark[j];
    for (i=0;i<n-1;i++)
        for (j=0;j<n-i-1;j++)
            if (total[j]<total[j+1])
            {
                temp=S[j];
                S[j]=S[j+1];
                S[j+1]=temp;
                ttemp=total[j];
                total[j]=total[j+1];
                total[j+1]=ttemp;
            }
    printf("Student Rank List\nReg No.\tName\t\tMarks\n");
    for (i=0;i<n;i++)
    {
        printf("%d\t%s\t",S[i].regno,S[i].name);
        for (j=0;j<4;j++)
            printf("%d ",S[i].mark[j]);
        printf("\n");
    }
}