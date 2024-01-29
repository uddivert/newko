#include <SDL2/SDL.h>
#include <stdio.h>
#include "sdl_resources.h"

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int main(int argc, char* args[]) 
{
    SDL_Window *mainWindow;
    SDL_Surface *mainScreenSurface; // uses sofware acceleration
                                    
    if (!init()) {
        printf("Initialization Error");
    } else if (!loadmedia()) {
        printf("Media load error");
    } else {
        //Apply the image
        SDL_BlitSurface(screenSurface, NULL, mainScreenSurface, NULL);
        //Update the surface
        SDL_UpdateWindowSurface(mainWindow);

        SDL_Event e; 
        bool nQuit = true;
        while(nQuit) {
            SDL_PollEvent(&e);
            if (e.type == SDL_QUIT) {
                nQuit = false;
            } else if (e.type == SDL_WINDOWEVENT) {
                SDL_UpdateWindowSurface(mainWindow);
            } // else
        } // while
    } // else
    sdlfree();
    return 0;
} // main
