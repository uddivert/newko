#include <SDL2/SDL.h>
#include <stdio.h>
#include "sdl_resources.h"

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

SDL_Window *mainWindow = NULL;

/** if using software renderer*/
#ifdef SOFT_RENDER
SDL_Surface *mainScreenSurface = NULL;
SDL_Surface *screenSurface = NULL; 
#endif

#ifdef HARD_RENDER
/** if using hardware renderer*/
SDL_Renderer *gRenderer = NULL;
SDL_Texture *gTexture = NULL;
#endif
                                   
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
                SDL_Rect stretchRect;
                stretchRect.x = 0;
                stretchRect.y = 0;
                stretchRect.w = SCREEN_WIDTH;
                stretchRect.h = SCREEN_HEIGHT;
                SDL_BlitScaled(screenSurface, NULL, mainScreenSurface, &stretchRect );
                //Update the surface
                SDL_UpdateWindowSurface(mainWindow);
            } // else
        } // while
    } // else
    sdlfree();
    return 0;
} // main
