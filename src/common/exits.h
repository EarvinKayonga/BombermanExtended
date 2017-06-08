#ifndef     __EXIST_H__
#define     __EXIST_H__

#include    <stdlib.h>
#include    <stdio.h>
#include    <string.h>
#include    "../network/socket_util.h"

void        panic(char*);
void        graceful_exit();
void        lost_connection(char*, int);
void        gameover(int socket);

#endif
