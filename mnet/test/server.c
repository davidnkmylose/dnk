#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/shm.h>

#define DEFAULT_PORT 13113
#define DEFAULT_IP 127.0.0.1
#define DEFAULT_BUFFER_SIZE 4096


int main(){
    printf("entry main function;\n");
    //socket 
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0){
        printf("sock fd error %d\n", sockfd);
    }
    return 0;
}

