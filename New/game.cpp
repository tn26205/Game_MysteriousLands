#include "Game.hpp"
#include "TextureManager.hpp"
#include "GameObject.hpp"
#include "Map.hpp"

GameObject* background;
GameObject* startgame;
GameObject* ground;
//GameObject* grass;
GameObject* turtle;
GameObject* turtlerun;
GameObject* ogre;

Map* _map;

SDL_Renderer* Game::renderer = nullptr;


Game::Game()
{}

Game::~Game()
{}

void Game::logErrorAndExit(const char* msg, const char* error)
{
    SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_ERROR, "%s: %s", msg, error);
    SDL_Quit();
}

void Game::initSDL(const char* WINDOW_TITLE, int x_pos, int y_pos, int SCREEN_WIDTH, int SCREEN_HEIGHT,bool fullScreen)
{
    int flags = 0;
    if(fullScreen){
        flags = SDL_WINDOW_FULLSCREEN;
    }

    if(SDL_Init(SDL_INIT_EVERYTHING) != 0) logErrorAndExit("SDL_Init", SDL_GetError());

    window = SDL_CreateWindow(WINDOW_TITLE, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, flags);
    if (window == nullptr) logErrorAndExit("CreateWindow", SDL_GetError());

    if (!IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG)) logErrorAndExit( "SDL_image error:", IMG_GetError());

    renderer = SDL_CreateRenderer(window, -1, 0);

    if (renderer)
    {
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
    }
    else logErrorAndExit("CreateRenderer", SDL_GetError());

    isRunning = true;

    /*SDL_Surface *bgr= IMG_Load("Game Graphics/bgr.jpg");
    background = SDL_CreateTextureFromSurface(renderer, bgr);
    SDL_FreeSurface(bgr);*/

    background = new GameObject("Game Graphics/newbackground1.png",0,0,1536,768);
    startgame = new GameObject("Game Graphics/startgame.png",330,430,300,200);

    Start();

    ground = new GameObject("Game Graphics/ground.png",0,0,1536,768);
    //grass = new GameObject("Game Graphics/grass/Asset 1.png",-1,-1,32,30);
    turtle = new GameObject("Game Graphics/Character/turtle.png",0,100,65,52);
    turtlerun = new GameObject("Game Graphics/Character/run.png",260,500,50,52);
    ogre = new GameObject("Game Graphics/Character/ogre.png",-10,650,55,58);

    _map = new Map();

}
void Game::handleEvents()
{
    while (SDL_PollEvent(&event)) {
        switch (event.type)
        {
            case SDL_QUIT :
                isRunning = false;
                break;
            case SDL_KEYDOWN:
                switch(event.key.keysym.sym)
                    {
                    case SDLK_UP:
                        turtle->y_pos -= 32;
                        break;
                    case SDLK_DOWN:
                        turtle->y_pos += 32;
                        break;
                    case SDLK_RIGHT:
                        turtle->x_pos += 32;
                        break;
                    case SDLK_LEFT:
                        turtle->x_pos -= 32;
                        break;
                    default:
                        break;
                    }
            case SDL_KEYUP:
                break;
            default:
                break;
        }
    }
}


//int cnt=0;
void Game::update()
{
   /* cnt++;

    destR.w = 128;
    destR.h = 128;
    destR.x=cnt;

    std::cout  << cnt << std::endl;*/
    //background->Update();
    //startgame->Update();
    ground->Update();
    //grass->Update();
    turtle->Update();
    turtlerun->Update();
    ogre->Update();
    turtlerun->x_pos+=2;
    turtlerun->y_pos--;
    ogre->x_pos+=2;
    ogre->y_pos--;

    //turtle->HandleInputAction(event);

    turtle->HandleMove();

    //turtle->Update();
}
void Game::render()
{
	SDL_RenderClear(renderer);
    //SDL_RenderCopy(renderer, background, NULL, NULL);
    //background->Render();
    //startgame->Render();
    ground->Render();
    //grass->Render();

    _map->DrawMap();
    turtle->Render();
    turtlerun->Render();
    ogre->Render();
	SDL_RenderPresent(renderer);
}

void Game::clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
}
void Game::Start()
{
    background->Update();
    startgame->Update();
    background->Render();
    startgame->Render();
    handleEvents();
    //isRunning=true;

	SDL_RenderPresent(renderer);
	SDL_Delay(10);
}
