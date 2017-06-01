#include    "exits.h"

/*
 * Gracefully Freeing used resources and exiting the program
 */
void        graceful_exit(){
    fflush(stdout) ;
    exit(0);
}

/*
 * Handling generic errors
 */
void        panic(char *message)
{
    fflush(stdout) ;
    perror(message);
    exit(1);
}
