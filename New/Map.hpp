#pragma once
#include <fstream>

#include "Game.hpp"
#include "TextureManager.hpp"
#include "GameObject.hpp"

class Map{
public:
    Map();
    ~Map();

    void LoadMap(const char* filepath);
    void DrawMap();
private:
    SDL_Rect src, dest;
    SDL_Rect src_n, dest_n;

    SDL_Texture* grass;

    int map[24][48];
};

