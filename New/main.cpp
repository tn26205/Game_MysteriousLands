#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "Game.hpp"

Game *game = nullptr;
int SCREEN_WIDTH = 960;
int SCREEN_HEIGHT = 600;

int main(int argc, char* args[])
{
    const int EPS=60;
    const int frameDelay = 1000/EPS;
    Uint32 frameStart;
    int frameTime;

    game = new Game();

    game->init("My Game", SCREEN_WIDTH, SCREEN_HEIGHT, false);
    while(game->running()){
        frameStart = SDL_GetTicks();

        game->handleEvents();
        game->update();
        game->render();

        frameTime = SDL_GetTicks() - frameStart;

        if(frameDelay > frameTime)
        {
            SDL_Delay(frameDelay-frameTime);
        }
    }

    game->clean();
    return 0;
}
