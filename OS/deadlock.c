#include <stdio.h>
int allo[10][10],max[10][10],avail[10][10],need[10][10],safe_sq[10],finish[10];
void main() 
{
    int n,r,i,j;
    printf("Enter no.of processes: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        finish[i]=0;
    printf("Enter no.of resources: ");
    scanf("%d", &r);
    printf("Enter allocated resources\n");
    for (int i=0; i<n; i++)
    {
        printf("Process %d: ", i+1);
        for (int j=0; j<r; j++)
            scanf("%d", &allo[i][j]);
    }
    printf("Enter maximum resources\n");
    for (int i=0; i<n; i++)
    {
        printf("Process %d: ", i+1);
        for (int j=0; j<r; j++)
        {
            scanf("%d", &max[i][j]);
            need[i][j]=max[i][j]-allo[i][j];
        }
    }
    printf("Enter available resources\n");
    for (int j=0; j<r; j++)
            scanf("%d", &avail[0][j]);
    int count=0,flag,k=0,dl=0;
    while (count<n)
    {
        flag=0;
        for (int i=0; i<n; i++)
        {
            if (finish[i]==1)
                continue;
            for (j=0; j<r; j++)
                if (avail[k][j]<need[i][j])
                    break;
            if (j==r)
            {
                for (int j=0; j<r; j++)
                    avail[k+1][j]=avail[k][j]+allo[i][j];
                k++;
                flag=1;
                safe_sq[count++]=i;
                finish[i]=1;
            }
        }
        if (flag==0)
        {
            printf("Deadlock detected");
            break;
        }
    }
    if (flag==1)
    {
        printf("No deadlock\nAllocation Matrix\n");
        printf("--------------------------------------------------\n");
        printf("Process No   Allocation   Maximum   Available   Need\n");
        printf("----------------------------------------------------\n");
        for (i=0; i<n; i++)
        {
            printf("P%d\t\t",i+1);
            for (int j=0; j<r; j++)
                printf("%d ",allo[i][j]);
            printf("\t");
            for (int j=0; j<r; j++)
                printf("%d ",max[i][j]);
            printf("\t");
            for (int j=0; j<r; j++)
                printf("%d ",avail[i][j]);
            printf("\t");
           for (int j=0; j<r; j++)
                printf("%d ",need[i][j]);
            printf("\n");
        }
        printf("----------------------------------------------------\n");
        printf("Available: ");
        for (int j=0; j<r; j++)
            printf("%d ",avail[i][j]);
        printf("\nSafe Sequence: P%d",safe_sq[0]);
        for (int i=1; i<n; i++)
            printf("-->P%d",safe_sq[i]);
        printf("\n");
    }
}