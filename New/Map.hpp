#pragma once

#include "Game.hpp"

class Map{
public:
    Map();
    ~Map();

    void LoadMap(int arr[24][48]);
    void DrawMap();

private:
    SDL_Rect src, dest;

    SDL_Texture* grass;

    int map[24][48];

};

