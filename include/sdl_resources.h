#ifndef SDL_RESOURCES_H
#define SDL_RESOURCES_H
#define HARD_RENDER

#include <SDL2/SDL.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_surface.h>
#include <stdbool.h>

struct vec3d
{
    float x, y, z;
};

struct triangle {
    struct vec3d p[3];
}; // triangle

struct mesh {
    struct triangle *tris;
}; //mesh

// header file contents go here
bool init(void);

// load media
bool loadmedia(void);
SDL_Surface* loadSurface(char *path);
SDL_Texture* loadTexture(char *path);

// free resources and close
void sdlfree(void);

extern bool init_flag; // success true;
extern bool load_flag; // load success flag
extern SDL_Window *mainWindow;
extern SDL_Surface *mainScreenSurface; // uses sofware acceleration
extern SDL_Surface *screenSurface; 
extern SDL_Renderer* gRenderer;
extern SDL_Texture* gTexture;

#endif // SDL_RESOURCES_H

