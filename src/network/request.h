#include    "socket.h"

#ifndef     __REQUEST_H__
#define     __REQUEST_H__

#define     BLOCK_BOMB_1    'b'
#define     BLOCK_PATH      ' '
#define     BLOCK_FIRE      '*'
#define     BLOCK_STEEL     's'
#define     BLOCK_BRICK     'w'

#define     OK              1
#define     KO              0

#define     P_CONNECT       1
#define     P_MOVE          2
#define     P_UPDATE        3
#define     P_POSE_BOMB     4
#define     P_GAME_OVER     5

/*          Protocol        */
#define     LEFT            1
#define     RIGHT           2
#define     DOWN            3
#define     UP              4
#define     NOTHING         5

#define     MAP_ROW         10
#define     MAP_COL         10
#define     MAX_CLIENTS     10

#include    <stdlib.h>
#include    <stdio.h>
#include    <unistd.h>
#include    "../common/exits.h"

typedef struct client_s
{
  int       id;
  int       alive;
  int       posx;
  int       posy;
  int       direction;
  int       next_direction;
  int       pose_bomb;
}           client_t;

typedef struct	request_s
{
  int		id;
  int		protocol;
  int		direction;
  int		response;
  char		map[MAP_ROW][MAP_COL];
  client_t	clients[MAX_CLIENTS];
}           request_t;


void        init_request(request_t *source, char *filename);
void        copy_request(request_t source, request_t *destination);
void        reset_client(client_t *client);
int         set_client(request_t *source, int client);

#endif
