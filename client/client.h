#include    "../common/socket_util.h"
#include    "../common/request.h"
#include    "../common/args.h"
#include    "sdl/sdl.h"


#ifndef         BOMBERMAN_ARGS_H
#define         BOMBERMAN_ARGS_H

void            intro();
int             window_loop(int);
int             game_loop(SDL_Surface*, int, int, client_t, fd_set, struct timeval);

#endif          //BOMBERMAN_ARGS_H
