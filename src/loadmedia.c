#include <SDL2/SDL_error.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <string.h>
#include "sdl_resources.h"

const char *getFileExtension(char *path) {
    const char *dot = strrchr(path, '.');  // Find the last occurrence of '.' in the path
    if (dot && dot != path) {
        return dot + 1;
    }
    return NULL;  // No file extension found
} // getFileExtension

bool loadmedia(void)
{
    bool load_flag = true;
    #ifdef SOFT_RENDER
    screenSurface = loadSurface 
        ("./resources/alert.png");
        //("./resources/hello_world.bmp");
    if (screenSurface == NULL) {
        printf("Unable to load image! SDL Error: %s\n",
            SDL_GetError());
        load_flag = false;
    } // if
    #endif
    #ifdef HARD_RENDER
    gTexture = loadTexture
        //("./resources/hello_world.bmp");
        ("./resources/alert.png");
    if (gTexture == NULL) {
        printf("Unable to load Texture! SDL Error: %s\n",
            SDL_GetError());
        load_flag = false;
    } // if
    #endif
    return load_flag;
} // loadmedia

#ifdef SOFT_RENDER
SDL_Surface* loadSurface(char *path) 
{
    SDL_Surface* optimizedSurface = NULL; 
    SDL_Surface* loadedSurface = NULL;
    const char *extension = getFileExtension(path);

    if (strcmp("bmp", extension) == 0) {
        loadedSurface = SDL_LoadBMP(path);
    } else if (strcmp("png", extension) == 0) {
        loadedSurface = IMG_Load(path);
        if (loadedSurface == NULL) {
            printf("Loaded Surface is null\nIMGERROR: %s\n", IMG_GetError());
        } // if
    } else {
        printf("Unable to load image\n%s\n",SDL_GetError());
    } // else
    optimizedSurface = SDL_ConvertSurface(loadedSurface, mainScreenSurface -> format,0);
    if (optimizedSurface == NULL) {
        printf("Unable to optimize image\n%s\n", SDL_GetError());
    } // if
    //Get rid of old loaded surface
    SDL_FreeSurface(loadedSurface);
    return optimizedSurface;
} // loadSurface
#endif 

#ifdef HARD_RENDER
SDL_Texture* loadTexture(char *path) 
{
    SDL_Texture *newTexture = NULL;
    SDL_Surface* screenSurface = NULL;
    const char *extension = getFileExtension(path);
    if (strcmp("bmp", extension) == 0) {
        screenSurface = SDL_LoadBMP(path);
    } else if (strcmp("png", extension) == 0) {
        screenSurface = IMG_Load(path);
        if (screenSurface == NULL) {
            printf("Loaded Surface is null\nIMGERROR: %s\n", IMG_GetError());
        } // if
    } else {
        printf("Unable to load image\n%s\n",SDL_GetError());
    } // else

    newTexture = SDL_CreateTextureFromSurface(gRenderer, screenSurface);
    if (newTexture == NULL) {
        printf("Error creating texture.%s: ", SDL_GetError());
    } // if
    SDL_FreeSurface(screenSurface);
    return newTexture;
} // SDL_ Texture

struct mesh* MakeCube(struct mesh* meshCube) {
    meshCube->tris = (struct triangle*)malloc(12 * sizeof(struct triangle)); // allocate 12 triangles
    
    if (meshCube->tris == NULL) {
        // Handle memory allocation failure
        return NULL;
    }

    // SOUTH
    meshCube->tris[0] = (struct triangle) {
        .p = {
            {0, 0, 0}, {0, 1, 0}, {1, 1, 0}
        }
    };

    meshCube->tris[1] = (struct triangle) {
        .p = {
            {0, 0, 0}, {1, 1, 0}, {1, 0, 0}
        }
    };
    // EAST
    meshCube->tris[2] = (struct triangle) {
        .p = {
            {1, 0, 0}, {1, 1, 0}, {1, 1, 1}
        }
    };

    meshCube->tris[3] = (struct triangle) {
        .p = {
            {1, 0, 0}, {1, 1, 1}, {1, 0, 1}
        }
    };
    // NORTH
    meshCube->tris[4] = (struct triangle) {
        .p = {
            {1, 0, 1}, {1, 1, 1}, {0, 1, 1}
        }
    };

    meshCube->tris[5] = (struct triangle) {
        .p = {
            {1, 0, 1}, {0, 1, 1}, {0, 0, 1}
        }
    };
    // WEST
    meshCube->tris[6] = (struct triangle) {
        .p = {
            {0, 0, 1}, {0, 1, 1}, {0, 1, 0}
        }
    };

    meshCube->tris[7] = (struct triangle) {
        .p = {
            {0, 0, 1}, {0, 1, 0}, {0, 0, 0}
        }
    };
    // TOP
    meshCube->tris[8] = (struct triangle) {
        .p = {
            {0, 1, 0}, {0, 1, 1}, {1, 1, 1}
        }
    };

    meshCube->tris[9] = (struct triangle) {
        .p = {
            {0, 1, 1}, {1, 1, 1}, {1, 1, 0}
        }
    };
    // BOTTOM 
    meshCube->tris[10] = (struct triangle) {
        .p = {
            {1, 0, 1}, {0, 0, 1}, {0, 0, 0}
        }
    };

    meshCube->tris[11] = (struct triangle) {
        .p = {
            {1, 0, 1}, {0, 0, 0}, {1, 0, 0}
        }
    };
    return meshCube;
} 
#endif

