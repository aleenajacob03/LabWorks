#include <stdio.h>
#include <stdlib.h>

void main()
{
    int req[50],vis[50],n,head,i,j,max;
    printf("Enter length of request array :");
    scanf("%d",&n);
    printf("Enter request array :");
    for(i=0;i<n;i++)
        scanf("%d",&req[i]);
    printf("Enter current head position :");
    scanf("%d",&head);
    printf("Enter max track no :");
    scanf("%d",&max);
    printf("Seek sequence :");
    // printf("Enter length :");
    int seek=0;
    // for(i=0;i<=max;i++)
    // {
        for(j=0;j<n;j++)
        // if(req[j]==i && vis[j]==0)
        {
            // count++;
            // vis[j]=1;
            printf("%d ",req[j]);
            seek+=abs(head-req[j]);
            head=req[j];
        }
    // }
    printf("\nSeek count : %d",seek);

}
