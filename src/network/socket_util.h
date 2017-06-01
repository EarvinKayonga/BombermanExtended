#ifndef     __SOCKET_UTIL_H__
#define     __SOCKET_UTIL_H__

#include    <stdio.h>
#include    <unistd.h>
#include    <stdlib.h>
#include    <strings.h>
#include    <sys/types.h>

#ifdef __WIN32__
    #include<winsock2.h>
#else
    #include<sys/socket.h>
    #include<netdb.h>
    #include<netinet/in.h>
    #include<arpa/inet.h>
#endif

#include    "../common/exits.h"

int         create_server(char *hostname, int port);
int         create_client(char *hostname, int port);

#endif
