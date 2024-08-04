#include <stdio.h>
#include <stdlib.h>
struct poly{
    int coef;
    int exp;
    struct poly *link;
}Phead,Qhead,Rhead;
struct poly *get_node()
{
    return (struct poly*)malloc(sizeof(struct poly));
}
void insert(struct poly)
{
    struct poly *new=get_node(),*ptr;
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
void display()
{
    struct poly *ptr;
    if (Header->link==NULL)
        printf("Empty poly\n");
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
    int p,q,cont=1,op;
    Phead=(struct poly*)malloc(sizeof(struct poly));
    Phead->data=Phead->link=NULL;
    printf("Enter the no.of terms in polynomial 1: ");
    scanf("%d",&p);
    for (i=0;i<p;i++)
    
    Qhead=(struct poly*)malloc(sizeof(struct poly));
    Qhead->data=Qhead->link=NULL;
    Rhead=(struct poly*)malloc(sizeof(struct poly));
    Rhead->data=Rhead->link=NULL;
    printf("Polynomial operations:");
    while (cont)
    {
        printf("\nEnter preferred operation\n1.Add polynomials\n2.Multiply polynomials\n3.Exit\nEnter option: ");
        scanf("%d",&op);
        switch(op)
        {
            case (1):add();
                    display();
                    break;
            case (2):multiply();
                    display();
                    break;
            case (3):cont=0;
                    break;
            default:printf("Invalid option\n");
        }
    }
}