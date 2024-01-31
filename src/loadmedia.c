#include <stdio.h>
#include <SDL2/SDL_surface.h>
#include "sdl_resources.h"

bool loadmedia(void)
{
    bool load_flag = true;
    screenSurface = loadSurface 
        ("./resources/hello_world.bmp");
    if (screenSurface == NULL) {
        printf( "Unable to load image! SDL Error: %s\n",
            SDL_GetError() );
        load_flag = false;
    } // if
    return load_flag;
} // loadmedia

SDL_Surface* loadSurface(char *path) 
{
    SDL_Surface* optimizedSurface = NULL; 
    SDL_Surface* loadedSurface = SDL_LoadBMP(path);

    if (loadedSurface == NULL) {
        printf("unable to load image\n");
    } else {
        optimizedSurface = SDL_ConvertSurface(loadedSurface, mainScreenSurface -> format,0);
        if (optimizedSurface == NULL) {
            printf("Unable to optimize image");
        }
        //Get rid of old loaded surface
        SDL_FreeSurface( loadedSurface );
    } // else
    return optimizedSurface;
} // loadSurface
