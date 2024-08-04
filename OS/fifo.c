#include <stdio.h>
int nf,l,ref[100],q[10],fault=0,hit=0,count=0,f=-1,r=-1;
int search(int x)
{
    int i;
    for(i=f;i<=r;i++)
        if(q[i]==x)
            return 1;
    return 0;
}

void enq(int x)
{
    if(f==-1)
    {
        f=0;
        r=0;
        q[r]=x;
    }
    else{
        r++;
        q[r]=x;       
    }
    count++;
}
void deq()
{
    f++;
    count--;
}
void main()
{
    int i,j;
    printf("Enter no of frames:");
    scanf("%d",&nf);
    printf("Enter length of reference string :");
    scanf("%d",&l);
    printf("Enter Reference string :");
    for(i=0;i<l;i++)
        scanf("%d",&ref[i]);

    for(i=0;i<l;i++)
    {
        if(search(ref[i])==0)
        {
            fault++;
            if(count<nf)
            {
                enq(ref[i]);
            }
            else{
                deq();
                enq(ref[i]);
            }
        }
        else
            hit++;

        for(j=f;j<=r;j++)
        {
            printf("%d ",q[j]);
        }
        printf("\n");

    }      
    printf("hit %d fault %d\n",hit,fault);

    
}
