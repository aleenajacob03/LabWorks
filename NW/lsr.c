#include <stdio.h>
int n,g[10][10];
void lsr(int d){
    int i,dist[10],prev[10],vis[10];
    for (i=0;i<n;i++){
        dist[i]=9999;
        vis[i]=0;
    }
    dist[d]=0;
    prev[d]=-1;
    for (i=0;i<n;i++){
        int dmin=9999,min;
        for (i=0;i<n;i++){
            if (!vis[i] && dist[i]<dmin){
                min=i;
                dmin=dist[i];
            }
        }
        vis[min]=1;
        for (i=0;i<n;i++){
            if (!vis[i] && g[min][i] && dist[i]>g[min][i]+dmin){
                dist[i]=g[min][i]+dmin;
                prev[i]=min;
            }
        }
    }
    printf("Table of %c\nDest\tDist\tNxt hop\n",d+65);
    for (i=0;i<n;i++){
        if (i!=d)
            printf("%c\t%d\t%c\n",i+65,dist[i],prev[i]+65);
    }
}
void main(){
    int i,j,l,s,d,c;
    printf("Enter no.of nodes:");
    scanf("%d",&n);
    for (i=0;i<n;i++){
        for (j=0;j<n;j++)
            g[i][j]=9999;
        g[i][i]=0;
    }
    printf("Enter no.of links:");
    scanf("%d",&l);
    for (i=0;i<l;i++){
        printf("Enter s,d,c of link:");
        scanf("%d%d%d",&s,&d,&c);
        g[s][d]=c;
        g[d][s]=c;
    }
    for (i=0;i<n;i++)
        lsr(i);
}