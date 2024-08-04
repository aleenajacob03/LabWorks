#include <stdio.h>
#include <stdlib.h>
struct tree{
    int data;
    struct tree *RC;
    struct tree *LC;
}*Header;
struct tree *get_node()
{
    return (struct tree*)malloc(sizeof(struct tree));
}
void insert(int item)
{
    struct tree *ptr,*ptr1=ptr=Header->RC;
    while (ptr!=NULL)
    {
        ptr1=ptr;
        if (item<ptr->data)
            ptr=ptr->LC;
        else if (item>ptr->data)
            ptr=ptr->RC;
        else
        {
            printf("Item already exists in tree.Cannot insert item\n");
            return;
        }
    }
    struct tree *new=get_node();
    if (ptr1==NULL)
        Header->RC=new;
    else if (item<ptr1->data)
        ptr1->LC=new;
    else
        ptr1->RC=new;
    new->data=item;
    new->RC=new->LC=NULL;
}
void preorder(struct tree *ptr)
{
    if (ptr!=NULL)
    {
        printf("%d ",ptr->data);
        preorder(ptr->LC);
        preorder(ptr->RC);
    }
}
void inorder(struct tree *ptr)
{
    if (ptr!=NULL)
    {
        inorder(ptr->LC);
        printf("%d ",ptr->data);
        inorder(ptr->RC);
    }
}
void postorder(struct tree *ptr)
{
    if (ptr!=NULL)
    {
        postorder(ptr->LC);
        postorder(ptr->RC);
        printf("%d ",ptr->data);
    }
}
void return_node(struct tree *ptr)
{
    ptr->LC=ptr->RC=NULL;
}
void delete(int item)
{
    struct tree *ptr=Header->RC,*ptr1,*prnt;
    int value;
    while (ptr!=NULL)
    {
        if (item<ptr->data)
        {
            prnt=ptr;
            ptr=ptr->LC;
        }
        else if (item>ptr->data)
        {
            prnt=ptr;
            ptr=ptr->RC;
        }
        else
        {
            if (ptr->LC==NULL && ptr->RC==NULL)
            {
                if (prnt->LC==ptr)
                    prnt->LC=NULL;
                else
                    prnt->RC=NULL;
            }
            else if (ptr->LC!=NULL && ptr->RC!=NULL)
            {
                for (ptr1=ptr->RC;ptr1->LC!=NULL;ptr1=ptr1->LC);
                value=ptr1->data;
                delete(value);
                ptr->data=value;
            }
            else
                if (prnt->LC==ptr)
                {
                    if (ptr->LC==NULL)
                        prnt->LC=ptr->RC;
                    else
                        prnt->LC=ptr->LC;
                }
                else
                {
                    if (ptr->LC==NULL)
                        prnt->RC=ptr->RC;
                    else
                        prnt->RC=ptr->LC;
                }
            return;
        }
    }
    printf("Item does not exist in tree.Cannot delete item\n");
}
void main()
{
    int cont=1,key,op;
    Header=(struct tree*)malloc(sizeof(struct tree));
    Header->LC=Header->RC=NULL;
    printf("Binary tree operations:");
    while (cont)
    {
        printf("\nEnter preferred operation\n1.Insert node\n2.Preorder traversal\n3.Inorder traversal\n4.Postorder traversal\n5.Delete node\n6.Exit\nEnter option: ");
        scanf("%d",&op);
        switch(op)
        {
            case (1):printf("Enter the item to insert: ");
                    scanf("%d",&key);
                    insert(key);
                    printf("Binary tree elements: ");
                    inorder(Header->RC);
                    break;
            case (2):printf("Preorder traversal elements: ");
                    preorder(Header->RC);
                    break;
            case (3):printf("Inorder traversal elements: ");
                    inorder(Header->RC);
                    break;
            case (4):printf("Postorder traversal elements: ");
                    postorder(Header->RC);
                    break;
            case (5):printf("Enter the item to delete: ");
                    scanf("%d",&key);
                    delete(key);
                    printf("Binary tree elements: ");
                    inorder(Header->RC);
                    break;
            case (6):cont=0;
                    break;
            default:printf("Invalid option");
        }
    }
}