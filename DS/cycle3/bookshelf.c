#include <stdio.h>
struct minilib{
    int id;
    char[] title;
    char[] author;
    int edition;
}*Header;
void insert_book()
{
    struct minilib *new=get_node(),*ptr,*j;
    if (new==NULL)
        printf("Space not initialised.Cannot insert item\n");
    else
    {
        printf("Enter book name: ");
        scanf("%d",&new->data)
        printf("Enter edition no: ");
        scanf("%d",&new->data);
        printf("Enter : ");
        scanf("%d",&new->data);
        ptr1=Header;
        for (ptr=Header->link;strcasecmp(ptr->title,new->title)<0;ptr=ptr->link)
            ptr1=ptr;
        if (strcasecmp(ptr->title,new->title)>0)
            {
                new->link=ptr1->link;
                ptr1->link=new;
            }
        else if (strcasecmp(ptr->title,new->title)==0)
        {
            for (i=ptr;i->edition<title->edition && strcasecmp(ptr->title,new->title)==0;i=i->link)
                ptr2=i;
            new->link=ptr2->link;
            ptr2->link=new;
        }
    }
}
void main()
{
    int cont=1,key,op;
    Header=(struct minilib*)malloc(sizeof(struct minilib));
    Header->data=Header->link=NULL;
    printf("Minilibrary functions:");
    while (cont)
    {
        printf("\nEnter preferred operation\n1.Add book\n2.Search book\n3.Exit\nEnter option: ");
        scanf("%d",&op);
        switch(op)
        {
            case (1):insert_book();
                    break;
            case (2):search_book();
                    break;
            case (3):cont=0;
                    break;
            default:printf("Invalid option\n");
        }
    }
}