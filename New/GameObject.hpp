
#pragma once

#include "Game.hpp"

class GameObject{
public:
    GameObject(const char* texturesheet, /*SDL_Renderer* ren,*/ int x, int y,int w, int h);
    ~GameObject();

   void Update();
   void Render();

private:
    int xpos;
    int ypos;

    SDL_Texture* objTexture;
    SDL_Rect srcRect, destRect;
    //SDL_Renderer* renderer;
};