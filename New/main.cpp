#include "Game.hpp"

int SCREEN_WIDTH = 960;
int SCREEN_HEIGHT = 600;

const char* WINDOW_TITLE = "My Game";

Game *game = nullptr;

int main(int argc, char* argv[])
{
    game = new Game();

    game->initSDL(WINDOW_TITLE, SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, false);

    while(game->running()){

        game->handleEvents();
        game->update();
        game->render();

    }

    game->clean();

    return 0;
}
