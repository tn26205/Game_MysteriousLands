#pragma once

#include "Game.hpp"

class Map{
public:
    Map();
    ~Map();

    void LoadMap(const char* filepath);
    void DrawMap();

private:
    SDL_Rect src, dest;

    SDL_Texture* grass;

    int map[24][48];

};

