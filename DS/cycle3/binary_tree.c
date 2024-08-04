#include <stdio.h>
#include <stdlib.h>
struct tree{
    int data;
    struct tree *RC;
    struct tree *LC;
}*Header,*position;
struct tree *get_node()
{
    return (struct tree*)malloc(sizeof(struct tree));
}
void insert(struct tree *ptr)
{
    int pos;
    if (ptr==Header || ptr->LC==NULL || ptr->RC==NULL)
    {
        struct tree *new=get_node();
        if (ptr==Header)
            Header->RC=new;
        else
        {
            printf("Enter if left child(1) or right child(2): ");
            scanf("%d",&pos);
            if (pos==1)
            {
                if (ptr->LC==NULL)
                    ptr->LC=new;
                else
                {
                    printf("Left child already exists.Cannot insert item\n");
                    return;
                }
            }
            else if (pos==2)
            {
                if (ptr->RC==NULL)
                    ptr->RC=new;
                else
                {
                    printf("Right child already exists.Cannot insert item\n");
                    return;
                }
            }
        }
        printf("Item: ");
        scanf("%d",&new->data);
        new->LC=new->RC=NULL;
    }
    else
        printf("Both children exist.Cannot insert item\n");
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
void delete(struct tree *ptr,struct tree *prnt)
{
    if (ptr->LC==NULL && ptr->RC==NULL)
        if (ptr==Header->RC)
            Header->RC=NULL;
        else if (prnt->LC==ptr)
                prnt->LC=NULL;
        else
                prnt->RC=NULL;
    else
        printf("Not a leaf node.Cannot delete\n");
    
}
void find(int p,struct tree *ptr,struct tree *prnt,int key)
{
    if (ptr!=NULL)
    {
        if (ptr->data==key)
            if (p==1)
                insert(ptr);
            else if (p==2)
                delete(ptr,prnt);
        find(p,ptr->LC,ptr,key);
        find(p,ptr->RC,ptr,key);
    }
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
            case (1):if (Header->RC==NULL)
                        insert(Header);
                    else
                    {
                        printf("Enter the item before to insert: ");
                        scanf("%d",&key);
                        find(1,Header->RC,NULL,key);
                    }
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
            case (5):if (Header->RC==NULL)
                        printf("Underflow\n");
                    else
                    {
                        printf("Enter the item to delete: ");
                        scanf("%d",&key);
                        find(2,Header->RC,NULL,key);
                    }
                    printf("Binary tree elements: ");
                    inorder(Header->RC);
                    break;
            case (6):cont=0;
                    break;
            default:printf("Invalid option");
        }
    }
}