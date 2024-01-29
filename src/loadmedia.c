#include "sdl_resources.h"

bool loadmedia(void)
{
    bool load_flag = true;
    screenSurface = SDL_LoadBMP
        ("./resources/hello_world.bmp");
    if (screenSurface == NULL) {
        printf( "Unable to load image %s! SDL Error: %s\n",
                "02_getting_an_image_on_the_screen/hello_world.bmp",
                SDL_GetError() );
        load_flag = false;
    } // if
    return load_flag;
} // loadmedia
