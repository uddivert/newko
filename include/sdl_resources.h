#ifndef SDL_RESOURCES_H
#define SDL_RESOURCES_H

#include <SDL2/SDL.h>
#include <stdbool.h>

// Your header file contents go here
bool init(void);

// load media
bool loadmedia(void);

// free resources and close
void sdlfree(void);

extern bool init_flag; // success true;
extern bool load_flag; // load success flag
extern SDL_Window *mainWindow;
extern SDL_Surface *mainScreenSurface; // uses sofware acceleration
extern SDL_Surface *screenSurface; 

#endif // SDL_RESOURCES_H

