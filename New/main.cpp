#include "Game.hpp"

int SCREEN_WIDTH = 1536;
int SCREEN_HEIGHT = 768;

const char* WINDOW_TITLE = "My Game";

Game *game = nullptr;

int main(int argc, char* argv[])
{
    const int FPS=50; //(Frame Per Second: so luong khung hinh muon chay trong mot giay)
    const int frameDelay = 1000/FPS;
    Uint32 frameStart;

    int frameTime;

    game = new Game();

    game->initSDL(WINDOW_TITLE, SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, false);

    /*background = new GameObject("Game Graphics/newbackground.png",0,0,1500,750);

    background->Update();
    SDL_RenderClear(Game::renderer);
    background->Render();
    SDL_RenderPresent(Game::renderer);*/
    //game->Start();
    while(game->running()){

        frameStart = SDL_GetTicks();

        game->handleEvents();
        game->update();
        game->render();

        frameTime = SDL_GetTicks() - frameStart;

        if(frameDelay > frameTime)
        {
            SDL_Delay(frameDelay-frameTime);
        }
    }

    game->clean();

    return 0;
}
