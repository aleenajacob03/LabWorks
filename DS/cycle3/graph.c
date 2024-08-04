#include <stdio.h>
#include <stdlib.h>
extern int stack[],queue[],visit[],top,front,rear;
struct node{
	char node;
	struct node* next;
	struct edge* adj;
}*Header;
struct edge{
	char dest;
	struct edge* link;
};
void adj_list()
{
	struct node *ptr;
	struct edge *edge;
	printf("Node  Adjacency list\n");
	for (ptr=Header->next;ptr!=NULL;ptr=ptr->next)
	{
		printf(" %c\t",ptr->node);
		for (edge=ptr->adj;edge!=NULL;edge=edge->link)
			printf("%c ",edge->dest);
		printf("\n");
	}
}
void adj_matrix()
{
	struct node *i,*j;
	struct edge *edge;
	for (i=Header->next;i!=NULL;i=i->next)
	{
		for (j=Header->next;j!=NULL;j=j->next)
		{
			for (edge=i->adj;edge!=NULL;edge=edge->link)
				if (edge->dest==j->node)
				{
					printf("%d ",1);
					break;
				}
			if (edge==NULL)
				printf("%d ",0);
		}
		printf("\n");
	}
}
void push(char item)
{
	top++;
	stack[top]=item;
}
char pop()
{
	char item=stack[top];
	top--;
	return (item);
}
void enqueue(char item)
{
	rear++;
	queue[rear]=item;
	if (front==-1)
		front++;	
}
char dequeue()
{
	char item=queue[front];
	if (front==rear)
		front=rear=-1;
	else
		front++;
	return(item);
}
void BFS(struct node *ptr)
{
	struct edge *edge;
	int i,n=0;
	if (ptr!=NULL)
	{
		enqueue(ptr->node);
		while (front!=-1)
		{
			char item=dequeue();
			for (i=0;i<n;i++)
				if (visit[i]==item)
					break;
			if (i==n)
			{
				printf("%c ",item);
				visit[i]=item;
				n++;
				for (edge=ptr->adj;edge!=NULL;edge=edge->link)
					enqueue(edge->dest);
			}
		}
	}
}
void DFS(struct node *ptr)
{
	struct edge *edge;
	int i,n=0;
	if (ptr!=NULL)
	{
		push(ptr->node);
		while (top!=-1)
		{
			char item=pop();
			for (i=0;i<n;i++)
				if (visit[i]==item)
					break;
			if (i==n)
			{
				printf("%c ",item);
				visit[i]=item;
				n++;
				for (edge=ptr->adj;edge!=NULL;edge=edge->link)
					push(edge->dest);
			}
		}
	}
}
int top=-1,rear=-1,front=-1,stack[20],queue[20],visit[20];
void main()
{
	int cont=1,key,op,n,c,i,j;
    char node,dest;
    struct node *ptr, *ptr1;
	struct edge *eptr;
    Header=(struct node*)malloc(sizeof(struct node));
	Header->next=NULL;
    ptr1=Header;
    printf("Enter no.of nodes: ");
    scanf("%d",&n);
    for (i=0;i<n;i++)
    {
    	printf("\nEnter node %d: ",(i+1));
    	scanf(" %c",&node);
        for (ptr=Header->next;ptr!=NULL && ptr->node!=node;ptr=ptr->next)
            ptr1=ptr;
        if (ptr==NULL)
        {
            struct node *new=(struct node*)malloc(sizeof(struct node));
            ptr1->next=new;
            new->node=node;
			new->next=NULL;
			new->adj=NULL;
			printf("Enter no.of connections: ");
			scanf("%d",&c);
			printf("Enter connectors: ");
			for (j=0;j<c;j++)
			{
				scanf(" %c",&dest);
				struct edge *edge=(struct edge*)malloc(sizeof(struct edge));
				if (new->adj==NULL)
					new->adj=edge;
				else
				{
					for (eptr=new->adj;eptr->link!=NULL;eptr=eptr->link);
					eptr->link=edge;
				}
				edge->dest=dest;
				edge->link=NULL;
			}
        }
		else
		{
			printf("Node already exists.Cannot insert node\n");
			i--;
		}
    }
    printf("\nGraph operations:");
    while (cont)
    {
        printf("\n\nEnter preferred operation\n1.Find adjacency list and matrix\n2.Perform DFS\n3.Perform BFS\n4.Exit\nEnter option: ");
        scanf("%d",&op);
        switch(op)
        {
            case (1):printf("Adjacency List\n");
					adj_list();
					printf("\nAdjacency Matrix\n");
					adj_matrix();
                    break;
            case (2):printf("DFS elements: ");
                    DFS(Header->next);
                    break;
            case (3):printf("BFS elements: ");
                    BFS(Header->next);
                    break;
            case (4):cont=0;
                    break;
            default:printf("Invalid option");
        }
    }
}