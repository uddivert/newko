#include <stdio.h>
#include "sdl_resources.h"

bool init()
{
    //Screen dimension constants
    const int SCREEN_WIDTH = 640;
    const int SCREEN_HEIGHT = 480;

    bool init_flag = false;

    if (SDL_Init(SDL_INIT_VIDEO)  < 0) {
        printf("SDL initialize Error: %s\n", SDL_GetError());
    } else {
        //Create window
        mainWindow= SDL_CreateWindow( "DEMO", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
        if (mainWindow == NULL ) {
            printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
        } else {
            init_flag = true;
            int imgFlags = IMG_INIT_PNG;
            if (!(IMG_Init(imgFlags) & imgFlags))
            {
                printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
                init_flag = false;
            }
            #ifdef SOFT_RENDER
            /* create surface context and send to main window*/
            mainScreenSurface = SDL_GetWindowSurface(mainWindow);
            #endif
            #ifdef HARD_RENDER
            gRenderer = SDL_CreateRenderer(mainWindow, -1, SDL_RENDERER_ACCELERATED);
            if (gRenderer == NULL) {
                printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
                init_flag = false;
            } else {
                //Initialize renderer color
                SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF); // black
            } // else
            #endif
        } // else
    } // else
    return init_flag;
} // init
