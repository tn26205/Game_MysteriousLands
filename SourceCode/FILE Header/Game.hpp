#ifndef GAME_FUNCTION_H_//Cac chi thi tien xu ly, ktra xem GAME_FUNCTION_H da duoc dinh nghia chua
#define GAME_FUNCTION_H_

#include <windows.h>
#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_ttf.h>

//Dinh nghia cac bien global

static SDL_Window* gWindow = NULL;   // Cua so
static SDL_Renderer* gScreen = NULL; // Hien thi
static SDL_Event gEvent;     // bien su kien

//Dinh nghia cac thong so co ban cho cac ham cua game tren man hinh

const int SCREEN_WIDTH = 960;
const int SCREEN_HEIGHT = 600;
const int SCREEN_BPP = 32;  // Dinh nghia pixel

//dinh nghia mau sac

const int COLOR_KEY_R = 167;
const int COLOR_KEY_G = 175;
const int COLOR_KEY_B = 180;

#endif // GAME_FUNCTION_H
