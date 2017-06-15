#ifndef         BOMBERMAN_WINDOWS_H
#define         BOMBERMAN_WINDOWS_H

#define         _BSD_SOURCE
#ifndef         _WIN32_WINNT
#define         _WIN32_WINNT 0x0501
#endif

#include        <winsock2.h>
#include        <winsock.h>
#include        <windows.h>
#include        <ws2tcpip.h>
#include        <stdio.h>

int             create_server(char *hostname, int port);
int             create_client(char *hostname, int port);

#endif          /* BOMBERMAN_WINDOWS_H */
