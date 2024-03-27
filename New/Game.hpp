#pragma once

#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include <iostream>
#include <vector>

class Game
{
public:

    Game();
    ~Game();

    void logErrorAndExit(const char* msg, const char* error);
    void initSDL(const char* WINDOW_TITLE, int x_pos, int y_pos, int SCREEN_WIDTH, int SCREEN_HEIGHT,bool fullScreen);
    void handleEvents();
	void update();
	void render();
	void clean();

	bool running() { return isRunning; }

private:
    bool isRunning = false;
    SDL_Window* window;
    SDL_Renderer* renderer;

};
