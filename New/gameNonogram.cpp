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
void GameNgram::handleEventNgramClickLeft(int &mouse_x, int &mouse_y)
{
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

void GameNgram::Suggest(int a[15][15]){
    sg_row.clear();
    sg_col.clear();

    for (int i = 0; i < 15; i++) {
        row_segments.clear();
        int check = 0;

        for (int j = 0; j < 15; j++) {
            if (a[i][j] == 0) {
                if (check > 0) {
                    row_segments.push_back(check);
                    check = 0;
                }
            } else if (a[i][j] == 1) {
                check++;
            }
        }

        if (check > 0) {
            row_segments.push_back(check);
        }

        sg_row.push_back(row_segments);
    }

    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < sg_row[i].size(); j++) {
            cout << sg_row[i][j] << " ";
        }
        cout << endl;
    }


    for (int j = 0; j < 15; j++) {
        row_segments.clear();
        int check = 0;

        for (int i = 0; i < 15; i++) {
            if (a[i][j] == 0) {
                if (check > 0) {
                    row_segments.push_back(check);
                    check = 0;
                }
            } else if (a[i][j] == 1) {
                check++;
            }
        }

        if (check > 0) {
            row_segments.push_back(check);
        }

        sg_col.push_back(row_segments);
    }

    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < sg_col[i].size(); j++) {
            cout << sg_col[i][j] << " ";
        }
        cout << endl;
    }
}

