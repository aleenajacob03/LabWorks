#include <stdio.h>
struct node{
    int dist[10],from[10];
}N[10];
void main(){
    int n,i,j,d[10][10];
    printf("Enter no.of nodes:");
    scanf("%d",&n);
    printf("Enter matrix:\n");
    for (i=0;i<n;i++)
        for (j=0;j<n;j++){
            scanf("%d",&d[i][j]);
            d[i][i]=0;
            N[i].dist[j]=d[i][j];
            N[i].from[j]=j;
        }
    for (i=0;i<n;i++)
        for (j=0;j<n;j++)
            for (int k=0;k<n;k++)
                if (N[i].dist[j]>N[i].dist[k]+N[k].dist[j]){
                    N[i].dist[j]=N[i].dist[k]+N[k].dist[j];
                    N[i].from[j]=N[i].from[k];
                }
    for (i=0;i<n;i++){
        printf("Table of %c:\nDest\tDist\tNxt hop\n",i+65);
        for (j=0;j<n;j++){
            printf("%c\t%d\t%c\n",j+65,N[i].dist[j],N[i].from[j]+65);
        }
    }
}