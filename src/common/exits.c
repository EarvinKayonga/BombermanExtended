/**
 * \file common/exits.c
 * \brief Exit Handling.
 * \version 0.1
 * \date June 2017, 1
 *
 * Exit Handling
 *
 */
#include    "exits.h"

/**
 * \fn void panic(char *message)
 * \brief Gracefully Freeing used resources and exiting the program
 */
void        graceful_exit()
{
    fflush(stdout) ;
    exit(0);
}

/**
 * \fn void panic(char *message)
 * \brief Freeing used resources and exiting the program && exiting the program because of a major issue
 */
void        panic(char *message)
{
    fflush(stdout) ;
    printf("%s \n", message);
    exit(1);
}

/**
 * \fn void lost_connection(char* message, int socket)
 * \brief Freeing used resources and exiting the program && exiting the program because of a network connection failure
 */
void        lost_connection(char* message, int socket)
{
    close(socket);
    panic(message);
}

/**
 * \fn void gameover(int socket)
 * \brief Freeing used resources and exiting the program && exiting the program because the Game is OVER.
 */

void         gameover(int socket)
{
    lost_connection("G A M E O V E R\n", socket);
}
