#include <stdio.h>
extern int front,rear,size,queue[];
void enqueue()
{
    int item;
    if ((front==0 && rear==size-1) || (rear+1==front))
        printf("Overflow\n");
    else
    {
        printf("Enter the element: ");
        scanf("%d",&item);
        rear=((rear+1)%size);
        queue[rear]=item;
        if (front==-1)
            front++;
        printf("Element updated\n");
    }
}
void dequeue()
{
    if (front==-1 && rear==-1)
        printf("Underflow\n");
    else
    {
        printf("Element deleted\nDeleted element: %d\n",queue[front]);
        if (front==rear)
            front=rear=-1;
        else
            front=((front+1)%size);
    }
}
void display()
{
    int i;
    if (front==-1 && rear==-1)
        printf("Queue empty\n");
    else
    {
        printf("Queue elements: ");
        if (front<=rear)
            for (i=front;i<=rear;i++)
                printf("%d ",queue[i]);
        else
        {
            for (i=front;i<size;i++)
                printf("%d ",queue[i]);
            for (i=0;i<=rear;i++)
                printf("%d ",queue[i]);
        }
        printf("\n");
    }
}
int front=-1;
int rear=-1;
int size,queue[50];
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