#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "Game.hpp"
class TextureManager{
public:
    static SDL_Texture* LoadTexture(const char* fileName);
    static void Draw(SDL_Texture* tex, SDL_Rect src, SDL_Rect dest);
};
