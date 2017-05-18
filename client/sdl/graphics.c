#include    "sdl.h"

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


/*
 * Init the SDL Library and returns a SDL_Surface Object
 */
SDL_Surface  *init_sdl(){
    SDL_Surface  *window;

    if (SDL_Init(SDL_INIT_VIDEO)
        || ((window = SDL_SetVideoMode(500, 500, 32, SDL_HWSURFACE)) == NULL)){
        fprintf(stderr, "Error SDL : %s\n", SDL_GetError());
        panic("SDL_PANIC");
    }

    return (window);
}

void        graceful_exit(SDL_Surface *f){
    if (f != NULL)
        SDL_FreeSurface(f);

    SDL_Quit();
    fflush(stdout) ;
    exit(0);
}

