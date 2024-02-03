#include <stdio.h>
#include <SDL2/SDL_surface.h>
#include "sdl_resources.h"

bool loadmedia(void)
{
    bool load_flag = true;
    #ifdef SOFT_RENDER
    screenSurface = loadSurface 
        ("./resources/hello_world.bmp");
    if (screenSurface == NULL) {
        printf( "Unable to load image! SDL Error: %s\n",
            SDL_GetError() );
        load_flag = false;
    } // if
    #endif
    #ifdef HARD_RENDER
    gTexture = loadTexture
        ("./resources/hello_world.bmp");
    if (gTexture == NULL) {
        printf( "Unable to load Texture! SDL Error: %s\n",
            SDL_GetError() );
    #endif
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
        } // if
        //Get rid of old loaded surface
        SDL_FreeSurface( loadedSurface );
    } // else
    return optimizedSurface;
} // loadSurface

SDL_Texture* loadTexture(char *path) 
{
    SDL_Texture *newTexture = NULL;
    SDL_Surface* loadedSurface = SDL_LoadBMP(path);
    if (screenSurface == NULL) {
        printf( "Unable to load image! SDL Error: %s\n",
            SDL_GetError() );
    } else {
        newTexture = SDL_CreateTextureFromSurface(gRenderer, loadedSurface);
        if (newTexture == NULL) {
            printf("Error creating texture.%s", SDL_GetError());
        } // if
        SDL_FreeSurface(loadedSurface);
    } // else
    return newTexture;
} // SDL_ Texture
