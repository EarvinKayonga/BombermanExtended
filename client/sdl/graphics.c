#include    "sdl.h"

const int   SCREEN_WIDTH = 640;
const int   SCREEN_HEIGHT = 480;
const int   SCREEN_BPP = 32;
const char* BOOM= "Boom Bitch";


/*
 * Init the SDL Library and returns a SDL_Surface Object
 */
SDL_Surface  *init_sdl(){
    SDL_Surface  *window;

    if (SDL_Init(SDL_INIT_VIDEO)
        || ((window = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_HWSURFACE)) == NULL)){
        fprintf(stderr, "Error SDL : %s\n", SDL_GetError());
        panic("SDL_PANIC");
    }

    SDL_WM_SetCaption(BOOM, NULL );

    return (window);
}



