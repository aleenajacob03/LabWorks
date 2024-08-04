#include <stdio.h>
extern int front,rear,size,queue[];
void enqueue_front()
{
    int item;
    if ((front==0 && rear==size-1) || (rear+1==front))
        printf("Overflow\n");
    else
    {
        printf("Enter the element: ");
        scanf("%d",&item);
        if (front==-1 || front==0)
            front=size-1;
        else
            front--;
        queue[front]=item;
        printf("Element updated\n");
    }
}
void enqueue_rear()
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
void dequeue_front()
{
    if (front==-1 && rear==-1)
        printf("Underflow\n");
    else
    {
        printf("Element deleted\nDeleted element: %d\n",queue[rear]);
        if (front==rear)
            front=rear=-1;
        else
            if (rear==0)
                rear=size-1;
            else
                rear--;
    }
}
void dequeue_rear()
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
        printf("Enter preferred operation\n1.Add element at front\n2.Add element at rear\n3.Delete element at front\n4.Delete element at rear\n5.Display queue\n6.Exit\nEnter option: ");
        scanf("%d",&op);
        switch(op)
        {
            case (1):enqueue_front();
                    display();
                    break;
            case (2):enqueue_rear();
                    display();
                    break;
            case (3):dequeue_front();
                    display();
                    break;
            case (4):dequeue_rear();
                    display();
                    break;
            case (5):display();
                    break;
            case (6):cont=0;
                    break;
            default:printf("Invalid option\n");
        }
    }
}