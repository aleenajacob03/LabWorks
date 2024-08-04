#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>
void main(){
    srand(time(0));
    int i,pkt[10],r,s,rem=0,t,c,op;
    for (i=0;i<10;i++)
        pkt[i]=(rand()%6+1)*10;
    printf("Rate:");
    scanf("%d",&r);
    printf("Size:");
    scanf("%d",&s);
    i=0;
    while(i<10 || rem>0){
        if (i<10){
            if (pkt[i]+rem>s)
                printf("Overflow\n");
            else{
                rem+=pkt[i];
                printf("Packet %d added to bucket\nRemaining size:%d\n\n",pkt[i],rem);
            }
            i++;
        }
        t=(rand()%4+1)*10;
        printf("Time left:%d\n\n",t);
        for (c=10;c<=t;c+=10){
            sleep(1);
            if (rem){
                if (r>rem){
                    op=rem;
                    rem=0;
                }
                else{
                    op=r;
                    rem-=r;
                }
                printf("packet %d processed\nRemaining size:%d\n\n",op,rem);
            }
            else{
                printf("No more packets. Remaining time:%d\n\n",t-c);
                break;
            }
        }
    }
}