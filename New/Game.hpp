#pragma once

#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include <iostream>
#include <vector>

class TextureManager;
class Game
{
public:

    int SCREEN_WIDTH = 1536;
    int SCREEN_HEIGHT = 768;
    int x_pos, y_pos;

    Game();
    ~Game();

    void logErrorAndExit(const char* msg, const char* error);
    void initSDL(const char* WINDOW_TITLE, int x_pos, int y_pos, int SCREEN_WIDTH, int SCREEN_HEIGHT,bool fullScreen);
    void handleEvents();
	void update();
	void render();
	void clean();
	void Start();

	bool running() { return isRunning; }
    static SDL_Renderer* renderer;
private:

    bool isRunning = false;
    int srcRect_w,srcRect_h;
    SDL_Window* window;

    SDL_Event event;

};
