#ifndef     __SOCKET_UTIL_H__
#define     __SOCKET_UTIL_H__

#include    <stdio.h>
#include    <unistd.h>
#include    <stdlib.h>
#include    <strings.h>
#include    <sys/types.h>
#include    <sys/select.h>
#include    <fcntl.h>

#ifdef __WIN32__
    #define _BSD_SOURCE
    #define _WIN32_WINNT 0x0501
    #include<ws2tcpip.h>
    #include<winsock2.h>
    #include<winsock.h>
#else
    #include<sys/socket.h>
    #include<netdb.h>
    #include<netinet/in.h>
    #include<arpa/inet.h>
#endif

#include    "../common/exits.h"

#define     bzero(b,len) (memset((b), '\0', (len)), (void) 0)
#define     h_addr h_addr_list[0]

int         create_server(char *hostname, int port);
int         create_client(char *hostname, int port);

#endif
