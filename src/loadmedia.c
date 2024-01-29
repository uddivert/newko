#include "sdl_resources.h"

bool loadmedia(void)
{
    bool load_flag = true;
    screenSurface = SDL_LoadBMP
        ("./resources/hello_world.bmp");
    if (screenSurface == NULL) {
        printf( "Unable to load image! SDL Error: %s\n",
            SDL_GetError() );
        load_flag = false;
    } // if
    return load_flag;
} // loadmedia
