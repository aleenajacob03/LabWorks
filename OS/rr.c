#include <stdio.h>
struct process{
    int pno,at,bt,ct,wt,tat,rt;
}p[10];
int r=0,f=0,rq[20],ct[20],t,n;
void sort()
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n-i-1; j++)
            if (p[j].at>p[j+1].at)
            {
                struct process temp=p[j];
                p[j]=p[j+1];
                p[j+1]=temp;
            }
}
void rr() 
{
    int c=p[0].at,count=1;
    rq[r++]=0;
    while (f!=r)
    {
        int cur=rq[f];
        if (p[cur].rt>t)
        {
            c+=t;
            p[cur].rt-=t;
        }
        else
        {
            c+=p[cur].rt;
            p[cur].rt=0;
        }
        ct[f++]=p[cur].ct=c;
        if (count<n)
            for (int i=count; i<n && p[i].at<=c; i++)
            {
                rq[r++]=i;
                count++;
            }
        if (p[cur].rt>0)
            rq[r++]=cur;
    }
    for (int i=0; i<n; i++)
    {
        p[i].tat=p[i].ct-p[i].at;
        p[i].wt=p[i].tat-p[i].bt;
    }
}
void gantt()
{
    printf("\nGANTT CHART\n ");
    for (int i=0;i<ct[0];i++)
        printf("--");
    printf(" ");
    for (int i=1;i<r;i++)
    {
        for (int j=0;j<ct[i]-ct[i-1];j++)
            printf("--");
        printf(" ");
    }
    printf("\n|");
    for (int i=0;i<r;i++)
    {
        for (int j=0;j<ct[i]-ct[i-1]-1;j++)
            printf(" ");
        printf("P%d",rq[i]+1);
        for (int j=0;j<ct[i]-ct[i-1]-1;j++)
            printf(" ");
        printf("|");
    }
    printf("\n ");
    for (int i=0;i<ct[0];i++)
        printf("--");
    printf(" ");
    for (int i=1;i<r;i++)
    {
        for (int j=0;j<ct[i]-ct[i-1];j++)
            printf("--");
        printf(" ");
    }
    printf("\n%d",p[0].at);
    for (int i=0;i<r;i++)
    {
        if (ct[i]<9)
            for (int j=0;j<ct[i]-ct[i-1];j++)
                printf("  ");
        else
            for (int j=0;j<2*(ct[i]-ct[i-1])-1;j++)
                printf(" ");
        printf("%d",ct[i]);
    }
    printf("\n\n");
}
void avg()
{
    int sumw=0,sumt=0;
    for (int i = 0; i <n;i++)
    {
        sumt+=p[i].tat;
        sumw+=p[i].wt;
    }
    printf("Average TAT: %d\n",sumt/n);
    printf("Average WT: %d\n",sumw/n);
}
void main()
{
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    printf("Enter the arrival time of processes: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &p[i].at);
    printf("Enter the burst time of processes: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &p[i].bt);
        p[i].pno=i+1,p[i].ct=0,p[i].rt=p[i].bt;
    }
    printf("Enter the time quanta: ");
    scanf("%d", &t);
    sort(n);
    rr(n);
    gantt(n);
    printf("--------------------------------------------------------------------------------------\n");
    printf("Process no.  Arrival time  Burst time  Completion time  Waiting time  Turn around time\n");
    printf("--------------------------------------------------------------------------------------\n");
    for (int i = 0; i < n; i++)
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", p[i].pno,p[i].at,p[i].bt,p[i].ct,p[i].wt,p[i].tat);
    printf("--------------------------------------------------------------------------------------\n");
    avg(n);
}