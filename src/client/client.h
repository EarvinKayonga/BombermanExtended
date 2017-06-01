#include    "../network/socket_util.h"
#include    "../network/request.h"
#include    "../common/args.h"
#include    "../common/exits.h"


#ifndef         BOMBERMAN_CLIENT_H
#define         BOMBERMAN_CLIENT_H

void            intro();
int             init_loop(int);
int             game_loop(int, int, client_t, fd_set);

#endif
