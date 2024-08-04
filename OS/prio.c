
#include <stdio.h>
typedef struct
{
    int pid,at,bt,ct,tt,wt,p,v;
}process;
process p[50];
int n;
void sort()
{
    int i,j;
    for(i=0;i<n;i++)
        for(j=0;j<n-i-1;j++)
            if(p[j].at>p[j+1].at)
            {
                process temp=p[j];
                p[j]=p[j+1];
                p[j+1]=temp;
            }
}
void prinonpre()
{
    int i,min,index=-1,count=1,c;
    c=p[0].ct=p[0].at+p[0].bt;
    p[0].tt=p[0].ct-p[0].at;
    p[0].wt=p[0].tt-p[0].bt;
    p[0].v=1;
    while(count<n)
    {
        for(i=1;i<n&& p[i].at<=c;i++)
        {
            if(p[i].v==0)
            {
                min=p[i].p,index=i;
                break;
            }
        }
        for(i=1;i<n && p[i].at<=c;i++)
        {
            if(p[i].v==0 && p[i].p<min)
            {
                min=p[i].p,index=i;
            }
        }

        if(index!=-1)
        {
            c=p[index].ct=c+p[index].bt;
            p[index].tt=p[index].ct-p[index].at;
            p[index].wt=p[index].tt-p[index].bt;
            count++;
            p[index].v=1;
        }
        else
            c++;
    }

}

void gantt()
{
    int i,j;
    for(i=0;i<n;i++)
        for(j=0;j<n-i-1;j++)
            if(p[j].ct>p[j+1].ct)
            {
                process temp=p[j];
                p[j]=p[j+1];
                p[j+1]=temp;
            }
    printf(" ");
    for(i=0;i<n;i++)
    {
        for(j=0;j<p[i].bt;j++)
            printf("--");
        printf(" ");
    }
    printf("\n|");
    for(i=0;i<n;i++)
    {
        for(j=0;j<p[i].bt-1;j++)
            printf(" ");
        printf("P%d",p[i].pid);
        for(j=0;j<p[i].bt-1;j++)
            printf(" ");
        printf("|");
    }
    printf("\n ");
    for(i=0;i<n;i++)
    {
        for(j=0;j<p[i].bt;j++)
            printf("--");
        printf(" ");
    }
    printf("\n%d",p[0].at);
    for(i=0;i<n;i++)
    {
        for(j=0;j<2*p[i].bt;j++)
            printf(" ");
        if(p[i].ct>9)
            printf("\b");
        printf("%d",p[i].ct);
    }
}

void average()
{
    float sumw = 0, sumt = 0;
    for (int i = 0; i < n; i++)
    {
        sumw += p[i].wt;
        sumt += p[i].tt;
    }
    printf("\n\nAverage Waiting Time = %0.3f", sumw / n);
    printf("\nAverage Turnaround Time = %0.3f\n", sumt / n);
}

void main()
{
    int i,j;
    printf("Enter no of process:");
    scanf("%d",&n);
    printf("Enter arrival time:");
    for(i=0;i<n;i++)
        scanf("%d",&p[i].at);
    printf("Enter burst time:");
    for(i=0;i<n;i++)
        scanf("%d",&p[i].bt);
    printf("Enter priority:");
    for(i=0;i<n;i++)
    {
        scanf("%d",&p[i].p);
        p[i].pid=i;
        p[i].v=0;
    }

    sort();
    prinonpre();
    printf("\nPRIORITY NON PREEMPTIVE SHCEDULING\n");
    printf("-------------------------------------------------------\n");
    printf("Pid\tAt\tBt\tCT\tTT\tWT\tPri\n");
    printf("-------------------------------------------------------\n");
    for(i=0;i<n;i++)
    {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n",p[i].pid,p[i].at,p[i].bt,p[i].ct,p[i].tt,p[i].wt,p[i].p);
    }
    printf("-------------------------------------------------------\n\nGANTT CHART\n");
    gantt();
    average();
}