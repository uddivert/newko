#include "sdl_resources.h"

bool init()
{
    //Screen dimension constants
    const int SCREEN_WIDTH = 640;
    const int SCREEN_HEIGHT = 480;

    SDL_Window *mainWindow = NULL;
    SDL_Surface *mainScreenSurface = NULL; // uses sofware acceleration
    bool init_flag = false;

    if (SDL_Init(SDL_INIT_VIDEO)  < 0) {
        printf("SDL initialize Error: %s\n", SDL_GetError());
    } else {
        //Create window
        mainWindow= SDL_CreateWindow( "DEMO", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
        if (mainWindow == NULL ) {
            printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
        } else {
            mainScreenSurface = SDL_GetWindowSurface(mainWindow);
            init_flag = true;
        } // else
    } // else
    return init_flag;
} // init
