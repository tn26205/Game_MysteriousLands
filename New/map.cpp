#include "Map.hpp"

extern const int START_X_GRID;
extern const int START_X_GRID;
extern const int PUZZLE_SIZE;

Map::Map()
{
    grass = TextureManager::LoadTexture("Game Graphics/grass/1.png");

    LoadMap("file_map.txt");
    //LoadNgram("mapNgram.txt");
    /*for (int i = 0; i < 15; i++)
    {
        for (int j = 0; j < 15; j++)
        {
            std::cout <<mapn[i][j] << " ";
        }
        std::cout << std::endl;
    }*/

    src.x = src.y = 0;
    src.w = dest.w = 36;
    src.h = dest.h = 34;

    dest.x = dest.y = 0;
}

Map::~Map()
{
}

void Map::LoadMap(const char* filepath)
{
    std::ifstream file(filepath);
    if(!file.is_open()) return;

    for(int i=0;i<24;i++){
        for(int j=0;j<48;j++){
            file >> map[i][j];
        }
    }
    file.close();

}

void Map::DrawMap()
{
    int type;

    for(int i=0;i<24;i++){
        for(int j=0;j<48;j++){
           type=map[i][j];

           dest.x = j*32;
           dest.y = i*32;

           switch (type)
           {
               case 1:
                    TextureManager::Draw(grass, src, dest);
                   break;
               default:
                break;
           }
        }
    }
}

