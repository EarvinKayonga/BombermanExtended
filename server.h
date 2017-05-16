#include <sys/types.h> 
#include <sys/socket.h> 
#include <stdio.h> 
#include <netinet/in.h> 
#include <sys/time.h> 
#include <sys/ioctl.h> 
#include <unistd.h>

#include "request.h"

int server_sockfd;

int client_sockfd; 

int server_len;

int client_len; 

struct sockaddr_in server_address; 

struct sockaddr_in client_address; 

int result; 

fd_set readfds;

fd_set testfds;

server_sockfd = socket(AF_INET, SOCK_STREAM, 0);

server_address.sin_family = AF_INET; 

server_address.sin_addr.s_addr = htonl(INADDR_ANY); 

server_address.sin_port = htons(9734); 

server_len = sizeof(server_address); 

bind(server_sockfd, (struct sockaddr *)&server_address, server_len); 

listen(server_sockfd, 5); 

FD_ZERO(&readfds); 

FD_SET(server_sockfd, &readfds);