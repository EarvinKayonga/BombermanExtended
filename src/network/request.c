/**
 * \file common/request.c
 * \brief Client Request Handling.
 * \version 0.1
 * \date June 2017, 1
 *
 * Client Request Handling
 *
 */

#include    "request.h"

int         posx = 1;

/**
 * \fn void   init_request(request_t *source, char *filename)
 * \brief Functions to get the Map
 * \param source request
 * \param filename the file that contains the map
 */
void        init_request(request_t *source, char *filename)
{
    int     row, col, i;
    char    c;
    FILE    *file;

    for (i = 0; i < MAX_CLIENTS; i++)
    {
        source->clients[i].id = -1;
        source->clients[i].posx = -1;
        source->clients[i].posy = -1;
    }

    if (!(file = fopen(filename, "r")))
        panic("An Error occured while retrieving the map");
    row = 0;
    col = 0;
    while (1)
    {
        c = fgetc(file);
        if (col >= MAP_COL)
        {
            col = 0;
            row++;
        }
        if (feof(file) || row >= MAP_ROW)
            break;

        if (c == BLOCK_PATH || c == BLOCK_STEEL || c == BLOCK_BRICK)
            source->map[row][col++] = c;
        else if (c != '\n')
            break;
    }
    if (row != MAP_ROW || col != 0)
        panic("An Error occured while retrieving the map");
}

/**
 * \fn void   copy_request(request_t source, request_t *destination)
 * \param source
 * \param destination
 */
void       copy_request(request_t source, request_t *destination)
{
    int    i, j;

    for (i = 0; i < MAP_ROW; i++)
        for (j = 0; j < MAP_COL; j++)
            destination->map[i][j] = source.map[i][j];
    for (i = 0; i < MAX_CLIENTS; i++)
        destination->clients[i] = source.clients[i];
}

/**
 * \fn int set_client(request_t *source, int client)
 * \param source
 * \param client
 */
int         set_client(request_t *source, int client)
{
    int     i;
    for (i = 0; i < MAX_CLIENTS; i++)
        if (source->clients[i].id == -1)
        {
            source->clients[i].id = client;
            source->clients[i].posx = posx++;
            source->clients[i].posy = 1;
            source->clients[i].alive = 1;
            source->clients[i].direction = LEFT;
            source->clients[i].next_direction = NOTHING;
            return i;
        }
    return (-1);
}

/**
 * \fn void   reset_client(client_t *client)
 * \param client
 */
void        reset_client(client_t *client)
{
    client->id = -1;
    client->posx = -1;
    client->posy = -1;
    client->alive= 0;
    client->direction = NOTHING;
    client->next_direction = NOTHING;
}
