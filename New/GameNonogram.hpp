#pragma once

#include <SDL2/SDL.h>
#include <vector>

#include "Map.hpp"

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
    void Suggest(int a[15][15]);

    vector<vector<int>> sg_row;
    vector<vector<int>> sg_col;

    vector<int> row_segments;
    vector<int> col_segments;

private:
    SDL_Renderer *renderer;
};
