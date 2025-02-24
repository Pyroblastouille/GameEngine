#ifndef _HPP_SPRITE
#define _HPP_SPRITE

#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
class Sprite
{
private:
    /* data */
    int width;
    int height;
    SDL_Surface *img;
    SDL_Texture *texture;
    SDL_Renderer *renderer;
public:
    Sprite(SDL_Renderer* render = NULL);
    ~Sprite();
    void Change_render(SDL_Renderer* render);
    void Set_image(char* filename);
};

#endif