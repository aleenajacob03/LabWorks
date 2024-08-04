#include <stdio.h>
struct process
{
int pid, arrival, burst, wait, turn,ct,s;
};

void sort(struct process p[], int n)
{
    for (int i = 0; i < n ; i++)    
        for (int j = 0; j < n-i-1; j++)        
            if (p[j].arrival > p[j+1].arrival)
            {
                struct process temp = p[j];
                p[j] = p[j+1];
                p[j+1] = temp;
            }
}

void sjf(struct process p[], int n)
{
    int c=p[0].ct=p[0].arrival+p[0].burst,count=1;
    p[0].turn=p[0].ct-p[0].arrival,p[0].wait=p[0].turn-p[0].burst,p[0].s=1;
    while(count<n)
    {
        int i,min,index;
        for (i=1; i<n; i++)
            if (p[i].s!=1)
            {
                min=p[i].burst,index=i;
                break;
            }
        for (int j=i + 1; p[j].arrival<=c && j<n; j++)
            if (min>p[j].burst && p[j].s!=1)
            {
                min=p[j].burst;
                index=j;
            }
        c=p[index].ct=c+min;
        p[index].s=1;
        p[index].turn=p[index].ct-p[index].arrival;
        p[index].wait=p[index].turn-p[index].burst;
        count++;
    }
}

void gantt(struct process p[], int n)
{
    for (int i = 0; i < n ; i++)    
        for (int j = 0; j < n-i-1; j++)        
            if (p[j].ct > p[j+1].ct)
            {
                struct process temp = p[j];
                p[j] = p[j+1];
                p[j+1] = temp;
            }
    printf("Gantt chart\n");
    printf(" ");
    for(int i=0; i<n; i++)
    {
        for(int  j=0;j<p[i].burst;j++)
            printf("--");
        printf(" ");
    }
    printf("\n");

    for(int i=0; i<n; i++)
    {
        printf("|");
        for(int  j=0;j<p[i].burst-1;j++)
            printf(" ");
        printf("P%d",p[i].pid);
        for(int  j=0;j<p[i].burst-1;j++)
            printf(" ");
    }
    printf("|");
    printf("\n");

    printf(" ");
    for(int i=0; i<n; i++)
    {
        for(int  j=0;j<p[i].burst;j++)
            printf("--");
        printf(" ");
    }
    printf("\n");

    printf("%d",p[0].arrival);
    for(int i=0; i<n; i++)
    {
        if (p[i].ct>9)
            for(int  j=0;j<(2*p[i].burst)-1;j++)
                printf(" ");
        else
            for(int  j=0;j<p[i].burst;j++)
                printf("  ");
        printf("%d",p[i].ct);
    
    }
    printf("\n");
}

void average(struct process p[],int n)
{
    float sumw = 0, sumt = 0;
    for (int i = 0; i < n; i++)
    {
        sumw += p[i].wait;
        sumt += p[i].turn;
    }
    printf("\n\nAverage Waiting Time = %0.3f", sumw / n);
    printf("\nAverage Turnaround Time = %0.3f\n", sumt / n);
}

void main()
{
int n ;
printf("Enter the number of processes: ");
scanf("%d",&n);
struct process p[10];
printf("Enter the arrival times of Processes:");
for (int i = 0; i < n; i++)
scanf("%d", &p[i].arrival);
printf("Enter the burst times of Processes:");
for (int i = 0; i < n; i++)
{
scanf("%d", &p[i].burst);
p[i].pid = i + 1;
p[i].s =0;
}
sort(p, n);
sjf(p,n);
printf("\n\nSJF\n");
printf("\n------------------------------------------------------------------------\n");
printf("Processes Arrival time Burst time Completion Time Waiting time Turnaround time\n");
printf("------------------------------------------------------------------------\n");
for (int i = 0; i < n; i++)
{
printf("P%d\t%d\t%d\t%d\t%d\t%d\n",p[i].pid,p[i].arrival, p[i].burst, p[i].ct,p[i].wait,p[i].turn);
}

printf("------------------------------------------------------------------------\n");
gantt(p,n);
average(p, n);
}