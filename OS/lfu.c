#include <stdio.h>
struct pages{
    int pgno,count;
}p[10];
int n=0,miss=0,ind=0;
void add(int pg)
{
    p[n].pgno=pg;
    p[n].count=1;
    n++;
}
void replace(int pg)
{
    int i,min=ind;
    for (i=0;i<n;i++)
        if (p[i].count<p[min].count)
            min=i;
    if (min==ind)
        ind=(ind+1)%n;
    p[min].pgno=pg;
    p[min].count=1;
}
int search(int pg)
{
    int i;
    for (i=0;i<n;i++)
        if (p[i].pgno==pg)
        {
            p[i].count++;
            return 1; 
        }
    return 0;
}
void main()
{
    int f,l,i,j,pg[10];
    printf("No.of frames: ");
    scanf("%d",&f);
    printf("Length of string: ");
    scanf("%d",&l);
    printf("String: ");
    for (i=0;i<l;i++)
        scanf("%d",&pg[i]);
    for (i=0;i<l;i++)
    {
        if (!search(pg[i]))
        {
            miss++;
            if (i<f)
                add(pg[i]);
            else
                replace(pg[i]);
        }
        for (j=0;j<n;j++)
            printf("%d ",p[j].pgno);
        printf("\n");
    }
    printf("No.of page faults: %d\n",miss);
}