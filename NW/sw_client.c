#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <string.h>
#include <arpa/inet.h>
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
    for(int c=1;c<10;c++){
        sprintf(b,"%d",c);
        printf("Sending packet %s\n",b);
        sendto(s,b,1024,0,(struct sockaddr*)&s_add,sizeof(s_add));
        bzero(b,1024);
        recvfrom(s,b,1024,0,(struct sockaddr*)&s_add,&size);
        printf("Received acknowledgement for packet %s\n",b);
        sleep(1);
    }
}