#ifndef         BOMBERMAN_ARGS_H_H
#define         BOMBERMAN_ARGS_H_H

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

#endif
