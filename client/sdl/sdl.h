#ifndef     __SDL_H__
#define     __SDL_H__

#include    <SDL/SDL.h>
#include    <stdlib.h>
#include    <stdio.h>
#include    <string.h>

void        panic(char *message);
SDL_Surface *init_sdl();

#endif
