#include "Sprite.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

Sprite::Sprite(SDL_Renderer* render)
{
    Change_render(render);
}

Sprite::~Sprite()
{
    if(img != NULL)
        SDL_FreeSurface(img);
    if(texture != NULL)
        SDL_DestroyTexture(texture);
}
void Sprite::Change_render(SDL_Renderer* render){
    renderer = render;
}
void Sprite::Set_image(char* filename){
    if(img != NULL)
        SDL_FreeSurface(img);
    if(texture != NULL)
        SDL_DestroyTexture(texture);
    img = IMG_Load(filename);
    texture = SDL_CreateTextureFromSurface(renderer,img);
}
