#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <string.h>
#include <arpa/inet.h>
void main(){
    char b[1024];
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
    while(1){
        bzero(b,1024);
        recvfrom(s,b,1024,0,(struct sockaddr*)&c_add,&size);
        printf("Received packet %s\n",b);
        sleep(1);
        printf("Sending acknowledgement for packet %s\n",b);
        sendto(s,b,1024,0,(struct sockaddr*)&c_add,sizeof(c_add));
    }
}