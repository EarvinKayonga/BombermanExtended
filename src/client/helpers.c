/**
 * \file client/helpers.c
 * \brief helpers functions.
 * \version 0.1
 * \date June 2017, 1
 *
 * Functions to render the map and and assign an id to a client
 *
 */
#include        "keys.h"

void            clear()
{
    #ifdef __WIN32__
    clrscr();
    #endif

    #ifdef linux
        //system("/bin/stty raw && /bin/stty cooked && clear");
        system("@cls||clear");
    #endif
}



void            paint(request_t *request, client_t *client)
{
    int         i, j, k, id;

    id = -1;
    clear();
    intro();

    for (i = 0; i < 10; i++)
        if (request->clients[i].id == id && id > 0)
            *client = request->clients[i];

    for (i = 0; i < MAP_ROW; i++)
    {
        for (j = 0; j < MAP_COL; j++)
        {
            int find = 0;
            for (k = 0; k < MAX_CLIENTS; k++)
            {
                client_t o = request->clients[k];

                if (o.id > 0 && o.posx == j && o.posy == i)
                {
                    if (client->id == o.id)
                        printf(" X |");
                    else
                        printf(" x |");
                    find = 1;
                    break;
                }
            }
            if (find == 0)
                printf(" %c |", request->map[i][j]);
        }
        printf("\n");
        for (k = 0; k < MAP_COL; k++)
            printf(" _  ");
        printf("\n");
    }
    fflush(stdout);
}


void            send_command(char key, int server)
{
    request_t   request;

    if (key == '.')
        graceful_exit();

    if (indexOf(KEYS, KEYS_COUNT, key) > -1) {
        if (key == BOMB_KEY)
            request.protocol = P_POSE_BOMB;
        else {
            request.protocol = P_MOVE;
            switch (key) {
                case UP_KEY:
                    request.direction = UP;
                    break;
                case DOWN_KEY:
                    request.direction = DOWN;
                    break;
                case RIGHT_KEY:
                    request.direction = RIGHT;
                    break;
                case LEFT_KEY:
                    request.direction = LEFT;
                    break;
            }
        }
        write(server, &request, sizeof(request_t));
    }
}

void            assign_client(request_t request, client_t* client)
{
    int         i, id;

    id = request.id;

    for (i = 0; i < MAX_CLIENTS; i++)
        if (request.clients[i].id == id)
            *client = request.clients[i];
}


/**
 * \fn void intro()
 * \brief Prints the Intro
 */
void              intro()
{
    printf("............................\n");
    printf("....  B O M B E R M A N  ...\n");
    printf("............................\n");
    printf("Quit    : %c\n",  QUIT_KEY);
    printf("Up      : %c\n",  UP_KEY);
    printf("Right   : %c\n",  RIGHT_KEY);
    printf("Down    : %c\n",  DOWN_KEY);
    printf("Left    : %c\n\n", LEFT_KEY);
    printf("Bomb    : %c\n",  BOMB_KEY);
}
