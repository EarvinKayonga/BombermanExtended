#include        "client.h"

#ifndef         BOMBERMAN_HELPERS_H
#define         BOMBERMAN_HELPERS_H

#ifdef __WIN32__
#include        <conio.h>
#endif

const char      KEYS[] = { LEFT_KEY, RIGHT_KEY, DOWN_KEY, UP_KEY, BOMB_KEY };
int             KEYS_COUNT = sizeof(KEYS) / sizeof(char);

#endif          /* //BOMBERMAN_HELPERS_H */
