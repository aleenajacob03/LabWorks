#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <string.h>
#include <arpa/inet.h>
#include <time.h>
void main(){
    char b[1024];
    struct sockaddr_in s_add;
    int s=socket(AF_INET,SOCK_DGRAM,0);
    if (s<0){
        perror("Socket error");
        exit(1);
    }
    memset(&s_add,'\0',sizeof(s_add));
    s_add.sin_family=AF_INET;
    s_add.sin_port=htons(8125);
    s_add.sin_addr.s_addr=inet_addr("127.0.0.1");
    socklen_t size=sizeof(s_add);
    int c=1;
    while(c<5){
        sprintf(b,"%d",c);
        printf("Sending packet %s\n",b);
        sendto(s,b,1024,0,(struct sockaddr*)&s_add,sizeof(s_add));
        bzero(b,1024);
        struct timeval t;
        t.tv_sec=5;
        t.tv_usec=0;
        if (setsockopt(s,SOL_SOCKET,SO_RCVTIMEO,&t,sizeof(t))<0)
            printf("Error\n");
        else{
            int r=recvfrom(s,b,1024,0,(struct sockaddr*)&s_add,&size);
            if (r<0)
                printf("Timeout error.Sending packet again\n");
            else{
                printf("Received acknowledgement for packet %s\n",b);
                c++;
            }
            sleep(1);
        }
    }
}