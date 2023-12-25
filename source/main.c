#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <signal.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <sys/wait.h>
#include "../header/fonc_ser.h"



int main(int argc,char *argv[]){
    if(argc!=2){
        printf("La connection a échoué!");
        exit(0);
    }
    int socketServer,sockerClient;
    struct sockaddr_in serverAddr,clientAddr;
    //int len,bind;
    int port=atoi(argv[1]);
    struct sigaction ac;
    socklen_t sizead;

    ac.sa_handler=end_child;
    ac.sa_flags=SA_RESTART;
    sigaction(SIGCHLD,&ac,NULL);

    socketServer=socket(AF_INET,SOCK_STREAM,0);
    if(socketServer==-1){
        printf("La connection a échoué!");
        exit(0);
    }else{
        //printf("114514");
    }
    //memset(&serverAddr,0,sizeof(serverAddr));
    serverAddr.sin_family=AF_INET;
    serverAddr.sin_port=htons(port);
    serverAddr.sin_addr.s_addr=htonl(INADDR_ANY);

    //bind=bind(socketServer,(struct sockaddr)&serverAddr,sizeof(sockaddr));
    if(bind(socketServer,(struct sockaddr*)&serverAddr,sizeof(serverAddr))==-1){
        printf("La connection a échoué!");
        exit(0);
    }else{
        //printf("1145141919810");
    }

    if(listen(socketServer,5)==-1){
        printf("La connection a échoué!");
        exit(0);
    }else{
        //printf("114514");
    }

    int n=1;
    sizead=sizeof(struct sockaddr_in );
    while(n==1){
        sockerClient=accept(socketServer,(struct sockaddr*)&clientAddr,&sizead);
        if(sockerClient==-1){
            printf("La connection a échoué!");
            exit(0);
        }
        fils(socketServer,sockerClient);
        printf("fin");
    }
    return 0;
}