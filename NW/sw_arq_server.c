#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <string.h>
#include <time.h>
#include <arpa/inet.h>
void main(){
    char b[1024];
    srand(time(0));
    struct sockaddr_in s_add,c_add;
    int s=socket(AF_INET,SOCK_DGRAM,0);
    if (s<0){
        perror("Socket error");
        exit(1);
    }
    memset(&s_add,'\0',sizeof(s_add));
    s_add.sin_family=AF_INET;
    s_add.sin_port=htons(8125);
    s_add.sin_addr.s_addr=inet_addr("127.0.0.1");
    int z=bind(s,(struct sockaddr*)&s_add,sizeof(s_add));
    if (z<0){
        perror("Bind error");
        exit(1);
    }
    socklen_t size=sizeof(c_add);
    int x=0;
    while(1){
        bzero(b,1024);
        recvfrom(s,b,1024,0,(struct sockaddr*)&c_add,&size);
        if (atoi(b)==x)
            printf("Received packet %s(duplicate)\n",b);
        else{
            printf("Received packet %s\n",b);
            x=atoi(b);
        }
        sleep(1);
        if (rand()%2==0){
            printf("Sending acknowledgement for packet %s\n",b);
            sendto(s,b,1024,0,(struct sockaddr*)&c_add,sizeof(c_add));
        }
    }
}