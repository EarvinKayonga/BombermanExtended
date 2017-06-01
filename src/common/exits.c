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
    perror(message);
    exit(1);
}