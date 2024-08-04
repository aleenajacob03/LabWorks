#include <stdio.h>
int nf,ref[100],n,hit=0,fault=0,count=0,stack[50],top=-1;
int search(int x)
{
    int i;
    for(i=0;i<=top;i++)
        if(stack[i]==x)
            return i;
    return -1;
}

void push(int x)
{
    top++;
    stack[top] = x;
    count++;
}
void pop_bottom()
{
    int i;
    for(i=0;i<top;i++)
        stack[i]=stack[i+1];
    top--;
    count--;
    
}
void main()
{
    int i,j;
    printf("Enter no of frames: ");
    scanf("%d",&nf);
    printf("Enter length of reference string : ");
    scanf("%d",&n);
    printf("Enter Reference string : " );
    for(i=0;i<n;i++)
        scanf("%d",&ref[i]);
    
    for(i=0;i<n;i++)
    {
        int index=search(ref[i]);
        if(index==-1)
        {
            fault++;
            if(count<nf)
            {
                push(ref[i]);
            }
            else{
                pop_bottom();
                push(ref[i]);
            }
        }
        else{
            hit++;
            int temp=stack[index];
            for(j=index;j<top;j++)
                stack[j]=stack[j+1];
            stack[top]=temp;
        }
        for(j=0;j<=top;j++)
            printf("%d ",stack[j]);
        printf("\n");
    }
    printf("hit %d  fault %d\n",hit,fault);

}
