#include <stdio.h>
#include <stdlib.h>
extern int L[],n,Hash[];
struct table{
    int key;
    struct table *link;
}*Header[10];
struct table *get_node()
{
    return (struct table*)malloc(sizeof(struct table));
}
void chain()
{
    int i,hv;
    struct table *ptr,*ptr1;
    for (i=0;i<n;i++)
    {
        hv=L[i]%10;
        ptr1=Header[hv];
        for (ptr=Header[hv]->link;ptr!=NULL;ptr=ptr->link)
            ptr1=ptr;
        struct table *new=get_node();
        ptr1->link=new;
        new->key=L[i];
        new->link=NULL;
    }
    printf("Collision resolution by chaining method-Hash table:\nIndex  Elements\n");
    for (i=0;i<10;i++)
    {
        printf("%d\t",i);
        for (ptr=Header[i]->link;ptr!=NULL;ptr=ptr->link)
            printf("%d ",ptr->key);
        printf("\n");
    }
}
void linear_probing()
{
    int i,hv;
    for (i=0;i<n;i++)
    {
        for (hv=(L[i]+1)%10;Hash[hv]!=NULL && hv<10;hv++);
        if (Hash[hv]==NULL)
            Hash[hv]=L[i];
        else
        {
            for(hv=0;Hash[hv]!=NULL && hv<(L[i]+1)%10;hv++);
            if (Hash[hv]==NULL)
                Hash[hv]=L[i];
            else
            {
                printf("Table overflow\n");
                break;
            }
        }
    }
    printf("Collision resolution by linear probing-Hash table:\nIndex  Element\n");
    for (i=0;i<10;i++)
    {
        printf("%d\t",i);
        if (Hash[i]!=NULL)
            printf("%d\n",Hash[i]);
        else
            printf("\n");
    }
}
int L[20],n,Hash[10];
void main()
{
    int cont=1,op,i;
    for (i=0;i<10;i++)
    {
        Header[i]=(struct table*)malloc(sizeof(struct table));
        Header[i]->link=NULL;
    }
    printf("Enter no.of terms in list: ");
    scanf("%d",&n);
    printf("Enter elements: ");
    for (i=0;i<n;i++)
        scanf("%d",&L[i]);
	printf("\nCollision resolution techniques:");
    while (cont)
    {
        printf("\nEnter preferred operation\n1.Chaining\n2.Linear probing\n3.Exit\nEnter option: ");
        scanf("%d",&op);
        switch(op)
        {
            case(1):chain();
                    break;
            case(2):linear_probing();
                    break;
            case(3):cont=0;
                    break;
            default:printf("Invalid option");
        }
    }
}