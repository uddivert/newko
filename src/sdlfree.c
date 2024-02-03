#include "sdl_resources.h"

void sdlfree(void)
{
    #ifdef SOFT_RENDER
    SDL_FreeSurface(screenSurface);
    mainScreenSurface = NULL;

    SDL_DestroyWindow(mainWindow);
    mainWindow = NULL;

    SDL_Quit();
    #endif
    #ifdef HARD_RENDER
    //Free loaded image
    SDL_DestroyTexture(gTexture);
    gTexture = NULL;

    //Destroy window    
    SDL_DestroyRenderer(gRenderer);
    SDL_DestroyWindow(mainWindow);
    mainWindow = NULL;
    gRenderer = NULL;
    SDL_Quit();
    #endif 
} // sdl_Free
