#include "request.h"

int       posx = 1;

void      init_request(request_t *source, char *filename)
{
    int   row, col, i;
    char c;
    FILE *file;

    for (i = 0; i < MAX_CLIENTS; i++)
    {
        source->clients[i].id = -1;
        source->clients[i].posx = -1;
        source->clients[i].posy = -1;
    }

    file = fopen(filename, "r");
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
        die("bad map");
}

void       copy_request(request_t source, request_t *destination)
{
    int    i, j;

    for (i = 0; i < MAP_ROW; i++)
        for (j = 0; j < MAP_COL; j++)
            destination->map[i][j] = source.map[i][j];
    for (i = 0; i < MAX_CLIENTS; i++)
        destination->clients[i] = source.clients[i];
}

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

void        reset_client(client_t *client)
{
    client->id = -1;
    client->posx = -1;
    client->posy = -1;
    client->alive= 0;
    client->direction = NOTHING;
    client->next_direction = NOTHING;
}
