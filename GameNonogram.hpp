#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <vector>
#include <string>
#include <chrono> // Thư viện thời gian
#include "Game.hpp"
#include "Map.hpp"

const int START_X_GRID = 300;
const int START_Y_GRID = 225;
const int PUZZLE_SIZE = 35;
const int SG_X_ROW = 235;
const int SG_X_COL = 270;
const int SG_Y_ROW = 305;
const int SG_Y_COL = 200;

class GameNgram
{
public:
    GameNgram();
    ~GameNgram();

    void LoadNgram(const char* filepath);
    void handleEventNgramClickLeft(int &mouse_x, int &mouse_y, Mix_Chunk* sound1, Mix_Chunk *sound2);
    void handleEventNgramClickRight(int &mouse_x, int &mouse_y, Mix_Chunk* sound1, Mix_Chunk *sound2);
    void Suggest(int a[15][15]);
    bool initTTF(SDL_Renderer* renderer);
    void closeTTF();
    void renderArrRow(SDL_Renderer* renderer, const vector<vector<int>>& arr);
    void renderArrCol(SDL_Renderer* renderer, const vector<vector<int>>& arr);
    void renderScore(SDL_Renderer* renderer, int score, int x, int y) ;
    void updateScore(int& score) ;

    vector<vector<int>> sg_row;
    vector<vector<int>> sg_col;

    vector<int> row_segments;
    vector<int> col_segments;

    SDL_Surface* textSurface;

    TTF_Font *gFont = nullptr;

private:
    bool success = true;
    int cnt;
    int max_row = 0;
    int max_col = 0;
};
