#ifndef         BOMBERMAN_LINUX_H
#define         BOMBERMAN_LINUX_H

#include        <sys/socket.h>
#include        <sys/time.h>
#include        <netdb.h>
#include        <netinet/in.h>
#include        <arpa/inet.h>
#include        <stdio.h>
#include        <unistd.h>
#include        <stdlib.h>
#include        <strings.h>
#include        <sys/types.h>
#include        <fcntl.h>

#define         bzero(b,len) (memset((b), '\0', (len)), (void) 0)
#define         h_addr h_addr_list[0]

int             create_server(char *hostname, int port);
int             create_client(char *hostname, int port);

#endif

