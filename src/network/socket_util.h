#ifndef     __SOCKET_UTIL_H__
#define     __SOCKET_UTIL_H__

#include    <stdio.h>
#include    <unistd.h>
#include    <stdlib.h>
#include    <string.h>
#include    <sys/types.h>

#include    <netdb.h>
#include    <netinet/in.h>

#ifdef __WIN32__
# include <winsock2.h>
#else
# include <sys/socket.h>
#endif

#include    <arpa/inet.h>
#include    "../common/exits.h"

int         create_server(char *hostname, int port);
int         create_client(char *hostname, int port);

#endif
