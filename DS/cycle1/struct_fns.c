#include <stdlib.h>
#include <string.h>
#include <stdio.h>
struct customer{
    char name[3][20];
    int accno;
    char acctype[5];
    int accbal;
};
void cust_det(int n,struct customer *S)
{
    int i;
    for (i=0;i<n;i++)
    {
        printf("Customer %d\n",i+1);
        printf("First name: ");
        scanf("%s",(S+i)->name[0]);
        printf("Middle name: ");
        scanf("%s",(S+i)->name[1]);
        printf("Last name: ");
        scanf("%s",(S+i)->name[2]);
        printf("Account no.: ");
        scanf("%d",&(S+i)->accno);
        printf("Account type(SB,FD,CB): ");
        scanf("%s",(S+i)->acctype);
        printf("Account Balance: Rs.");
        scanf("%d",&(S+i)->accbal);
    }
}
void cust_search(int anum,int n,struct customer *S)
{
    int i;
    for (i=0;i<n;i++)
        if ((S+i)->accno==anum)
        {
            printf("customer Details\nName: %s %s %s\nAcc. Type: %s\nCurr. Balance: %d\n",(S+i)->name[0],(S+i)->name[1],(S+i)->name[2],(S+i)->acctype,(S+i)->accbal);
            return;
        }
    printf("Customer not found\n");
}
void cust_viewbal(int anum,int n,struct customer *S)
{
    int i;
    for (i=0;i<n;i++)
        if ((S+i)->accno==anum)
        {
            printf("Current Balance: %d\n",(S+i)->accbal);
            return;
        }
    printf("Customer not found\n");
}
void cust_sort(int n,struct customer *S)
{
    int i,j;
    struct customer temp;
    for (i=0;i<n;i++)
        for (j=0;j<n-i-1;j++)
            if (strcasecmp((S+j)->name[0],(S+j+1)->name[0])>0)
            {
                temp=*(S+j);
                *(S+j)=*(S+j+1);
                *(S+j+1)=temp;
            }
}
void cust_viewFD(int n,struct customer *S)
{
    int i,found=1;
    for (i=0;i<n;i++)
        if (strcmp((S+i)->acctype,"FD")==0)
        {
            if (found)
            {
                printf("Customer Details\n");
                found=0;
            }
            printf("Name: %s %s %s\nAccount No.: %d\nCurrent Balance: %d\n",(S+i)->name[0],(S+i)->name[1],(S+i)->name[2],(S+i)->accno,(S+i)->accbal);
        }
    if (found) 
        printf("No customers found\n");
}
void main()
{
    int n,i,accno;
    struct customer *C;
    printf("Enter the number of customers: ");
    scanf("%d",&n);
    C=(struct customer*)malloc(n*sizeof(struct customer));
    printf("Enter details:\n");
    cust_det(n,C);
    printf("Search Account\nEnter Account No.: ");
    scanf("%d",&accno);
    cust_search(accno,n,C);
    printf("View Balance\nEnter Account No.: ");
    scanf("%d",&accno);
    cust_viewbal(accno,n,C);
    printf("Customer List\n");
    cust_sort(n,C);
    for (i=0;i<n;i++)
        printf("%s %s %s\n",(C+i)->name[0],(C+i)->name[1],(C+i)->name[2]);
    printf("Account Type: FD\n");
    cust_viewFD(n,C);
}