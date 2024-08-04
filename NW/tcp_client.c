#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>
void main(){
    char b[1024];
    struct sockaddr_in c_add;
    //socklen_t size;
    int c=socket(AF_INET,SOCK_STREAM,0);
    if (c<0){
        perror("Socket error");
        exit(1);
    }
    printf("Socket created\n");
    memset(&c_add,'\0',sizeof(c_add));
    c_add.sin_family=AF_INET;
    c_add.sin_port=htons(6433);
    c_add.sin_addr.s_addr=inet_addr("127.0.0.1");
    connect(c,(struct sockaddr*)&c_add,sizeof(c_add));
    printf("Connected\n");
    while(1){
        bzero(b,1024);
        printf("Enter chat: ");
        scanf(" %[^\n]",b);
        send(c,b,strlen(b),0);
        if (strcmp(b,"Exit")==0){
            close(c);
            printf("Client exited\n");
            exit(0);
        }
        bzero(b,1024);
        recv(c,b,sizeof(b),0);
        if (strcmp(b,"Exit")==0){
            close(c);
            printf("Client exited\n");
            exit(0);
        }
        printf("Client:%s\n",b);
    }
}