#include "sdl_resources.h"

void sdlfree(void)
{
    SDL_FreeSurface(screenSurface);
    mainScreenSurface = NULL;

    SDL_DestroyWindow(mainWindow);
    mainWindow = NULL;

    SDL_Quit();
} // sdl_Free
