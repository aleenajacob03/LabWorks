#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>
void main(){
    struct sockaddr_in s_add,c_add;
    char b[1024];
    int s=socket(AF_INET,SOCK_DGRAM,0);
    if (s<0){
        perror("Socket error");
        exit(1);
    }
    printf("Socket created\n");
    memset(&s_add,'\0',sizeof(s_add));
    s_add.sin_family=AF_INET;
    s_add.sin_port=htons(6433);
    s_add.sin_addr.s_addr=inet_addr("127.0.0.1");
    int n=bind(s,(struct sockaddr*)&s_add,sizeof(s_add));
    if (n<0){
        perror("Bind error");
        exit(1);
    }
    printf("Binded\n");
    while(1){
        bzero(b,1024);
        socklen_t ad_size=sizeof(c_add);
        recvfrom(s,b,sizeof(b),0,(struct sockaddr*)&c_add,&ad_size);
        if (strcmp(b,"Exit")==0){
            printf("Server exited\n");
            exit(0);
        }
        printf("Client:%s\n",b);
        bzero(b,1024);
        printf("Chat:");
        scanf(" %[^\n]",b);
        sendto(s,b,strlen(b),0,(struct sockaddr*)&c_add,sizeof(c_add));
        if (strcmp(b,"Exit")==0){
            printf("Client exited\n");
            exit(0);
        }
    }
}