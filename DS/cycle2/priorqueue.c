#include <stdio.h>
extern int size,maxprior,queue[10][30],end[10][2];
void enqueue(int p)
{
    int item;
    if ((end[p][0]==0 && end[p][1]==size-1) || (end[p][1]+1==end[p][0]))
        printf("Overflow\n");
    else
    {
        printf("Enter the element: ");
        scanf("%d",&item);
        end[p][1]=((end[p][1]+1)%size);
        queue[p][end[p][1]]=item;
        if (end[p][0]==-1)
            end[p][0]++;
        printf("Element updated\n");
    }
}
void dequeue()
{
    int n;
    for (n=0;n<maxprior;n++)
        if (end[n][0]==-1 && end[n][1]==-1)
            continue;
        else
        {
            printf("Element deleted\nDeleted element: %d\n",queue[n][end[n][0]]);
            if (end[n][0]==end[n][1])
                end[n][0]=end[n][1]=-1;
            else
                end[n][0]=((end[n][0]+1)%size);
            break;
        }
}
void display()
{
    int n,i;
    printf("Priority\tQueue elements\n");
    for (n=0;n<maxprior;n++)
    {
        printf("%d\t\t",n);
        if (end[n][0]==-1 && end[n][1]==-1)
            printf("Empty\n");
        else
        {
            if (end[n][0]<=end[n][1])
                for (i=end[n][0];i<=end[n][1];i++)
                    printf("%d ",queue[n][i]);
            else
            {
                for (i=end[n][0];i<size;i++)
                    printf("%d ",queue[n][i]);
                for (i=0;i<=end[n][1];i++)
                    printf("%d ",queue[n][i]);
            }
            printf("\n");
        }
    }
}
int size,maxprior,queue[10][30],end[10][2];
void main()
{
    int i,j,op,item,prior,cont=1;
    printf("Enter maximum priority: ");
    scanf("%d",&maxprior);
    for (i=0;i<maxprior;i++)
        for (j=0;j<2;j++)
            end[i][j]=-1;
    printf("Enter maximum size of stack: ");
    scanf("%d",&size);
    while (cont)
    {
        printf("\n");
        printf("Enter preferred operation\n1.Add element\n2.Delete first element\n3.Display queue\n4.Exit\nEnter option: ");
        scanf("%d",&op);
        switch(op)
        {
            case (1):printf("Enter priority: ");
                    scanf("%d",&prior);
                    if (prior<maxprior)
                        enqueue(prior);
                    else
                        printf("Outside maximum priority.Cannot input element\n");
                    display();
                    break;
            case (2):dequeue();
                    display();
                    break;
            case (3):display();
                    break;
            case (4):cont=0;
                    break;
            default:printf("Invalid option\n");
        }
    }
}