#include "Game.hpp"
#include "TextureManager.hpp"
#include "GameObject.hpp"

/*SDL_Texture* playerTex;

SDL_Rect srcR, destR;*/

GameObject* player;

Game::Game()
{}

Game::~Game()
{}

void Game::init(const char* title, int width, int height, bool fullscreen)
{
    int flags = 0;

    if (fullscreen)
    {
        flags = SDL_WINDOW_FULLSCREEN;
    }

    if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
    {
        window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, flags);
        renderer = SDL_CreateRenderer(window, -1, 0);
        if (renderer)
        {
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        }

        isRunning = true;
    }
    /*SDL_Surface *tmpSurface = IMG_Load("Game Graphics/human1.png");
    playerTex = SDL_CreateTextureFromSurface(renderer, tmpSurface);
    SDL_FreeSurface(tmpSurface);*/
    //playerTex = TextureManager::LoadTexture("Game Graphics/AdobeStock_start1.bmp",renderer);
    player = new GameObject("Game Graphics/human1.png",renderer);
}
void Game::handleEvents()
{
    SDL_Event event;

	SDL_PollEvent(&event);

	switch (event.type)
	{
	case SDL_QUIT :
		isRunning = false;
		break;
	default:
		break;
	}
}
void Game::update()
{
    /*cnt++;

    destR.w = 128;
    destR.h = 128;
    destR.x=cnt;

    std::cout  << cnt << std::endl;*/
    player->Update();
}

void Game::render()
{
	SDL_RenderClear(renderer);
    //SDL_RenderCopy(renderer, playerTex, NULL, &destR);
    player->Render();
	SDL_RenderPresent(renderer);
}

void Game::clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
}



