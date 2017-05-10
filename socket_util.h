#ifndef __SOCKET_UTIL_H__
#define __SOCKET_UTIL_H__

#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <netinet/in.h>
#include <string.h>

void die(char *message);
int create_server(char *hostname, int port);
int create_client(char *hostname, int port);

#endif
