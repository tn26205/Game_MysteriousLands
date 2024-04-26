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

#pragma once
#include <fstream>
#include <vector>
using namespace std;

#include "Game.hpp"
#include "TextureManager.hpp"
#include "GameObject.hpp"

class Map{
public:
    Map();
    ~Map();

    void LoadMap(const char* filepath);
    void DrawMap();

    SDL_Rect src, dest;

    SDL_Texture* grass;

    SDL_Rect GetTextureRect() const {
        return dest;
    }

private:

    int map[24][48];
};

