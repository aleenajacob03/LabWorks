#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>
void main(){
    char b[1024],w[20];
    struct sockaddr_in c_add,s_add;
    int s=socket(AF_INET,SOCK_STREAM,0);
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
    listen(s,10);
    printf("Listening\n");
    socklen_t ad_size=sizeof(c_add);
    int c=accept(s,(struct sockaddr*)&c_add,&ad_size);
    printf("Client connected\n");
    while(1){
        bzero(b,1024);
        recv(c,b,sizeof(b),0);
        if (strcmp(b,"Exit")==0){
            close(c);
            printf("Client exited\n");
            exit(0);
        }
        printf("Client:%s\n",b);
        bzero(b,1024);
        printf("Chat:");
        scanf(" %[^\n]",w);
        strcpy(b,w);
        send(c,b,strlen(b),0);
        if (strcmp(b,"Exit")==0){
            close(c);
            printf("Server exited\n");
            exit(0);
        }
    }
}