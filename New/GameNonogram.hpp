#pragma once

#include <SDL2/SDL.h>
#include <vector>

#include "Map.hpp"
#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <vector>
#include <string>

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
    bool initTTF(SDL_Renderer* renderer);
    void closeTTF();
    void renderArrRow(SDL_Renderer* renderer, const vector<vector<int>>& arr);
    void renderArrCol(SDL_Renderer* renderer, const vector<vector<int>>& arr);

    vector<vector<int>> sg_row;
    vector<vector<int>> sg_col;

    vector<int> row_segments;
    vector<int> col_segments;

private:
    TTF_Font *gFont = nullptr;
    bool success = true;
    int cnt;
    int max_row = 0;
    int max_col = 0;
};

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
