#include    "../network/socket_util.h"
#include    "../network/request.h"
#include    "../common/args.h"
#include    "../common/exits.h"

#ifndef         BOMBERMAN_CLIENT_H
#define         BOMBERMAN_CLIENT_H

void            intro();

void            send_command(char , int);
void            assign_client(request_t request, client_t* client);
void            paint(request_t *request, client_t *client);

int             init_loop(int);
int             game_loop(int, int, client_t, fd_set);

#define         LEFT_KEY        'q'
#define         RIGHT_KEY       'd'
#define         DOWN_KEY        's'
#define         UP_KEY          'z'

#define         BOMB_KEY        'b'

#define         QUIT_KEY        '.'

#endif
