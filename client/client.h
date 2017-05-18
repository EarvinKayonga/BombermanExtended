#include    "../common/socket_util.h"
#include    "../common/request.h"


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

#endif          //BOMBERMAN_ARGS_H
