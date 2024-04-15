#include "GameNonogram.hpp"

extern GameObject* nonogram;
extern GameObject* startgame;
extern int current[15][15];
extern int mapn[15][15];

Map *mapNgram;

Game *quit;

GameNgram::GameNgram()
{
}

GameNgram::~GameNgram()
{}
/*void GameNgram::LoadNgram(const char* filepath)
{
    std::ifstream file(filepath);
    if(!file.is_open()) std::cout << "error";

    for(int i=0;i<24;i++){
        for(int j=0;j<48;j++){
            file >> mapn[i][j];
        }
    }
    file.close();

}*/
void GameNgram::handleEventNgramClickLeft(int &mouse_x, int &mouse_y)
{
    //LoadNgram("mapNgram.txt");
    std::cout << "Click left: " << mouse_x << " " << mouse_y << std::endl;
    int pos_x = (int)((mouse_y - START_Y_GRID) / PUZZLE_SIZE);
    int pos_y = (int)((mouse_x - START_X_GRID) / PUZZLE_SIZE);
    std::cout << pos_x << " " << pos_y << std::endl;

    if (mapn[pos_x][pos_y] == 1) current[pos_x][pos_y] = 1;
    else current[pos_x][pos_y] = 2;

    for (int i = 0; i < 15; i++)
    {
        for (int j = 0; j < 15; j++)
        {
            std::cout << current[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void GameNgram::handleEventNgramClickRight(int &mouse_x, int &mouse_y)
{
    std::cout << "Click right: " << mouse_x << " " << mouse_y << std::endl;
    int pos_x = (int)((mouse_y - START_Y_GRID) / PUZZLE_SIZE);
    int pos_y = (int)((mouse_x - START_X_GRID) / PUZZLE_SIZE);
    std::cout << pos_x << " " << pos_y << std::endl;
    if (mapn[pos_x][pos_y] == 0)
         current[pos_x][pos_y] = -1;
    else
         current[pos_x][pos_y] = -2;
    for (int i = 0; i < 15; i++)
    {
        for (int j = 0; j < 15; j++)
        {
            std::cout << current[i][j] << " ";
        }
        std::cout << std::endl;
    }
}
