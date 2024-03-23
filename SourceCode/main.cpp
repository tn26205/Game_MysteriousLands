#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "Game.hpp"
#include "Base_Image.hpp"

BaseImage gBackground;

bool Init()
{
    bool success = true;
    if(SDL_Init(SDL_INIT_VIDEO) < 0){
        return false;
    }
    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"); // thiet lap che do ti le va chat luong
    gWindow = SDL_CreateWindow("Mysterious Lands", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT,SDL_WINDOW_SHOWN);
    if(gWindow == NULL) success = false;
    else {
        gScreen = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);

        if(gScreen == NULL) success = false;
        else{
            SDL_SetRenderDrawColor(gScreen, 255, 255, 255, 255); // truyen mau sac ra man hinh
            int imgFlags = IMG_INIT_PNG;
            if(!(IMG_Init(imgFlags) && imgFlags)) success = false;
        }
    }

    return success;
}

bool LoadBackground()
{
    bool ret = gBackground.LoadImage("D:/INT 2215/Game Graphics/candyLand_3_1.png",gScreen);
    if (ret == false) return false;

    return true;
}

void close()
{
    gBackground.Free();

    SDL_DestroyRenderer(gScreen);
    gScreen = NULL;

    SDL_DestroyWindow(gWindow);
    gWindow = NULL;
    IMG_Quit();
    SDL_Quit();
}

int main(int argc, char* args[])
{
    if(Init() == false) return 1;

    if(LoadBackground()==false) return 1;

    bool quit = false;
    while(!quit){
        while (SDL_PollEvent(&gEvent)!=0){
            if (gEvent.type == SDL_QUIT){
                quit = true;
            }
        }
        SDL_SetRenderDrawColor(gScreen, 255, 0, 0, 255);
        SDL_RenderClear(gScreen);

        gBackground.Render(gScreen, NULL);

        SDL_RenderPresent(gScreen);
    }
    close();
    return 0;
}
