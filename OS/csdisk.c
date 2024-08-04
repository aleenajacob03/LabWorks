#include <stdio.h>
#include <stdlib.h>
int req[50],vis[50];

void main()
{
    int n,i,j,head,count=0,max,seek=0;
    printf("Enter length of request array :");
    scanf("%d",&n);
    printf("Enter request array :");
    for(i=0;i<n;i++)
    {
        scanf("%d",&req[i]);
        vis[i]=0;
    }
    printf("Enter current head position :");
    scanf("%d",&head);
    printf("Enter max track no :");
    scanf("%d",&max);
    int headorg=head;
    printf("Seek sequence :");
    for(i=head;i<=max;i++)
    {
        for(j=0;j<n;j++)
            if(req[j]==i && vis[j]==0)
            {
                printf("%d ",i);
                seek+=abs(i-head);
                head=i;
                vis[j]=1;
                count++;
                break;
                
            }

    }
    if(count!=n)
    {   
        printf("%d %d ",max,0);
        seek+=(abs(max-head)+max);
        head=0;
        for(i=0;i<=headorg;i++)
        {
            for(j=0;j<n;j++)
                if(req[j]==i && vis[j]==0)
                {
                    printf("%d ",i);
                    seek+=abs(i-head);
                    head=i;
                    vis[j]=1;
                    count++;
                    break;
                    
                }

        }

    }

    printf("\nSeek count : %d\n",seek);


}
