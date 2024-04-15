#pragma once

#include <SDL2/SDL.h>

//#include "GameObject.hpp"
#include "Map.hpp"
//#include "Game.hpp"

const int START_X_GRID = 600;
const int START_Y_GRID = 200;
const int PUZZLE_SIZE = 35;

class GameNgram
{
public:
    GameNgram();
    ~GameNgram();

    void LoadNgram(const char* filepath);
    void handleEventNgramClickLeft(int &mouse_x, int &mouse_y);
    void handleEventNgramClickRight(int &mouse_x, int &mouse_y);

    //int mapn[15][15];
private:
    SDL_Renderer *renderer;
    int cnt=0;
};
