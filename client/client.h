#include    "../common/socket_util.h"
#include    "../common/request.h"
#include    "sdl/sdl.h"


#ifndef         BOMBERMAN_ARGS_H
#define         BOMBERMAN_ARGS_H

#include        <stdlib.h>
#include        <stdio.h>
#include        <string.h>
#include        <ctype.h>

typedef struct  config_s
{
    char        *hostname;
    int         port;
}               config_t;

config_t        from_arguments(int argc, char **args);
void            intro();
int             window_loop(int);
int             game_loop(SDL_Surface*, int, int, client_t, fd_set, struct timeval);

#endif          //BOMBERMAN_ARGS_H
