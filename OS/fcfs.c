#include <stdio.h>
struct process
{
int pid, arrival, burst, wait, turn,ct;
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

void fcfs(struct process p[], int n)
{
     
    p[0].ct=p[0].arrival+p[0].burst;
    p[0].turn=p[0].ct-p[0].arrival;
    p[0].wait=p[0].turn-p[0].burst;
    for(int i=1;i<n;i++)
    {
        p[i].ct=p[i-1].ct+p[i].burst;
        p[i].turn=p[i].ct-p[i].arrival;
        p[i].wait=p[i].turn-p[i].burst;
    }

    // int c=p[0].arrival;
    // for(int i=0;i<n;i++)
    // {
    //     p[i].ct=c+p[i].burst;
    //     c=p[i].ct;
    //     p[i].turn=p[i].ct-p[i].arrival;
    //     p[i].wait=p[i].turn-p[i].burst;
    // }
}

void gantt(struct process p[], int n)
{
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
}
sort(p, n);
fcfs(p,n);
printf("\n\nFCFS\n");
printf("\n------------------------------------------------------------------------\n");
printf("Processes Arrival time Burst time Completion Time Waiting time Turnaround time\n");
printf("------------------------------------------------------------------------\n");
for (int i = 0; i < n; i++)
{
printf("P%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",p[i].pid,p[i].arrival, p[i].burst, p[i].ct,p[i].wait,p[i].turn);
}

printf("------------------------------------------------------------------------\n");
gantt(p,n);
average(p, n);
}