#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "Game.hpp"
#include "Base_Image.hpp"

#define MAX_TILES 20

class Tile_Map : public BaseImage
{
public:  // hinh anh tinh o moi o
    Tile_Map();
    ~Tile_Map();

private:

};

//Xay dung mot lop quan ly map

class Game_Map
{
public:
    Game_Map();
    ~Game_Map();


    void LoadMap{char* name};//ham doc tung thong tin trong file text so do map

    void LoadTiles(SDL_Renderer* gScreen);//ham load tung hinh anh cho tuong ung voi ma hoa

    void DrawMap(SDL_Rendere* gScreen); // ham xay dung map

private:
    map game_map; // chua toan bo thong tin ve ban do
    Tile_Map tilemap[MAX_TILES];
};
