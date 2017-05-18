#include    "sdl.h"

/*
 * Gracefully Freeing used resources and exiting the program
 */
void        graceful_exit(SDL_Surface *f){
    if (f != NULL)
        SDL_FreeSurface(f);

    SDL_Quit();
    fflush(stdout) ;
    exit(0);
}

/*
 * Handling generic errors
 */
void        panic(char *message)
{
    SDL_Quit();
    fflush(stdout) ;
    perror(message);
    exit(1);
}
