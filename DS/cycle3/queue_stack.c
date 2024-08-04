#include <stdio.h>
int top1=-1,top2=-1,size,stack1[30],stack2[30];
void enqueue()
{
    if (top1<size-1)
    {
        printf("Enter the element: ");
        scanf("%d",&stack1[++top1]);
    }
    else
        printf("Overflow\n");
}
void push1(int item)
{
    stack1[++top1]=item;
}
int pop1()
{
    return stack1[top1--];
}
void push2(int item)
{
    stack2[++top2]=item;
}
int pop2()
{
    return stack2[top2--];
}
void dequeue()
{
    if (top1==-1)
        printf("Underflow\n");
    else
    {
        while (top1!=-1)
            push2(pop1());
        printf("Element deleted\nDeleted element: %d\n",pop2());
        while (top2!=-1)
            push1(pop2());
    }
}
void display()
{
    int i;
    if (top1==-1)
        printf("Queue empty\n");
    else
    {
        printf("Queue elements: ");
        for (i=0;i<=top1;i++)
            printf("%d ",stack1[i]);
        printf("\n");
    }
}
void main()
{
    int op,cont=1;
    printf("Enter no.of elements in queue: ");
    scanf("%d",&size);
    while (cont)
    {
        printf("\n");
        printf("Enter preferred operation\n1.Add element\n2.Delete first element\n3.Display queue\n4.Exit\nEnter option: ");
        scanf("%d",&op);
        switch(op)
        {
            case (1):enqueue();
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