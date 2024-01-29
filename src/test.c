#include <SDL2/SDL.h>
#include <stdio.h>
#include "sdl_resources.h"

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

SDL_Window *mainWindow = NULL;
SDL_Surface *mainScreenSurface = NULL;
SDL_Surface *screenSurface = NULL; 
                                   
int main(int argc, char* args[]) 
{
    if (!init()) {
        printf("Initialization Error");
    } else if (!loadmedia()) {
        printf("Media load error");
    } else {
        SDL_Event e; 
        bool nQuit = true;
        while(nQuit) {
            SDL_PollEvent(&e);
            if (e.type == SDL_QUIT) {
                nQuit = false;
            } else if (e.type == SDL_WINDOWEVENT) {
                //Apply the image
                SDL_BlitSurface(screenSurface, NULL, mainScreenSurface, NULL);
                //Update the surface
                SDL_UpdateWindowSurface(mainWindow);
            } // else
        } // while
    } // else
    sdlfree();
    return 0;
} // main
