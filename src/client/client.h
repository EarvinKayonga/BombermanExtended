#include    "../network/socket_util.h"
#include    "../network/request.h"
#include    "../common/args.h"
#include    "../common/exits.h"


#ifndef         BOMBERMAN_CLIENT_H
#define         BOMBERMAN_CLIENT_H

void            intro();
void            send_command(char , int, request_t);
int             init_loop(int);
int             game_loop(int, int, client_t, fd_set);

#define         LEFT_KEY        'q'
#define         RIGHT_KEY       'd'
#define         DOWN_KEY        's'
#define         UP_KEY          'z'

#define         BOMB_KEY        'b'

#define         QUIT_KEY        '.'

const char      KEYS[] = { LEFT_KEY, RIGHT_KEY, DOWN_KEY, UP_KEY, BOMB_KEY };
int             KEYS_COUNT = sizeof(KEYS) / sizeof(char);
#endif
