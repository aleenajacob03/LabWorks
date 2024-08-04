//read string from file, store in alpha,sort bubble,bin s , two fns 
#include <stdio.h>
#include <stdlib.h>
struct employee{
    int empid;
    char name[3][20];
    int sal;
};
void main()
{
    int n,i,eid;
    struct employee *P;
    printf("Enter the number of employees: ");
    scanf("%d",&n);
    P=(struct employee*)malloc(n*sizeof(struct employee));
    printf("Enter details:\n");
    for (i=0;i<n;i++)
    {
        printf("Employee %d\n",i+1);
        printf("First name: ");
        scanf("%s",(P+i)->name[0]);
        printf("Middle name: ");
        scanf("%s",(P+i)->name[1]);
        printf("Last name: ");
        scanf("%s",(P+i)->name[2]);
        printf("Employee ID: ");
        scanf("%d",&(P+i)->empid);
        printf("Salary: ");
        scanf("%d",&(P+i)->sal);
    }
    printf("Search Employee\nEnter Employee ID: ");
    scanf("%d",&eid);
    for (i=0;i<n;i++)
        if ((P+i)->empid==eid)
        {
            printf("Employee found\nName: %s %s %s\n",(P+i)->name[0],(P+i)->name[1],(P+i)->name[2]);
            break;
        }
    if (i==n)
        printf("Employee not found\n");
}