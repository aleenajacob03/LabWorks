#include <stdio.h>
#include <stdlib.h>
struct list{
    int data;
    struct list *link;
}*Header;
struct list *get_node()
{
    return (struct list*)malloc(sizeof(struct list));
}
void insert_front()
{
    struct list *new=get_node();
    if (new==NULL)
        printf("Space not initialised.Cannot insert item\n");
    else
    {
        new->link=Header->link;
        printf("Enter data item: ");
        scanf("%d",&new->data);
        Header->link=new;
    }
}
void insert_end()
{
    struct list *new=get_node(),*ptr;
    if (new==NULL)
        printf("Space not initialised.Cannot insert item\n");
    else
    {
        for (ptr=Header;ptr->link!=NULL;ptr=ptr->link);
        ptr->link=new;
        printf("Enter data item: ");
        scanf("%d",&new->data);
        new->link=NULL;
    }
}
void insert_position(int key)
{
    struct list *new=get_node(),*ptr;
    if (new==NULL)
        printf("Space not initialised.Cannot insert item\n");
    else
    {
        for (ptr=Header;ptr->data!=key;ptr=ptr->link);
        new->link=ptr->link;
        printf("Enter data item: ");
        scanf("%d",&new->data);
        ptr->link=new;
    }
}
void return_node(struct list *ptr)
{
    ptr->data=ptr->link=NULL;
}
void delete_front()
{
    struct list *ptr=Header->link;
    if (Header->link==NULL)
        printf("Empty list.Cannot delete item\n");
    else
    {
        Header->link=ptr->link;
        return_node(ptr);
    } 
}
void delete_end()
{
    struct list *ptr,*ptr1;
    if (Header->link==NULL)
        printf("Empty list.Cannot delete item\n");
    else
    {
        for (ptr=Header;ptr->link!=NULL;ptr=ptr->link)
            ptr1=ptr;  
        ptr1->link=NULL;
        return_node(ptr);
    }
}
void delete_position(int key)
{
    struct list *ptr,*ptr1;
    if (Header->link==NULL)
        printf("Empty list.Cannot delete item\n");
    else
    {
        for (ptr=Header;ptr->data!=key;ptr=ptr->link) 
            ptr1=ptr;  
        ptr1->link=ptr->link;
        return_node(ptr);
    }
}
void display()
{
    struct list *ptr;
    if (Header->link==NULL)
        printf("Empty list\n");
    else
    {
        printf("List elements: ");
        for (ptr=Header->link;ptr!=NULL;ptr=ptr->link)
            printf("%d ",ptr->data);
        printf("\n");
    }
}
void main()
{
    int cont=1,key,op;
    Header=(struct list*)malloc(sizeof(struct list));
    Header->data=Header->link=NULL;
    printf("Linked list operations:");
    while (cont)
    {
        printf("\nEnter preferred operation\n1.Add element at front\n2.Add element at end\n3.Add element at position\n4.Delete element at front\n5.Delete element at end\n6.Delete element at position\n7.Exit\nEnter option: ");
        scanf("%d",&op);
        switch(op)
        {
            case (1):insert_front();
                    display();
                    break;
            case (2):insert_end();
                    display();
                    break;
            case (3):printf("Enter the element after which data is to be inserted: ");
                    scanf("%d",&key);
                    insert_position(key);
                    display();
                    break;
            case (4):delete_front();
                    display();
                    break;
            case (5):delete_end();
                    display();
                    break;nbj
            case (6):printf("Enter the item to delete: ");
                    scanf("%d",&key);
                    delete_position(key);
                    display();
                    break;
            case (7):cont=0;
                    break;
            default:printf("Invalid option\n");
        }
    }
}