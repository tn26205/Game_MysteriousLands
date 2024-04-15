#include "Game.hpp"

GameObject *background;
GameObject *startgame;
GameObject *ground;
GameObject *turtle;
GameObject *turtlerun;
GameObject *ogre;
GameObject *box;
GameObject *nonogram;
GameObject *color[15][15];
int current[15][15];
int mapn[15][15];

Map *_map;

GameNgram *Ngram;
GameNgram *sgNgram = new GameNgram();

SDL_Renderer *Game::renderer = nullptr;

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

    background = new GameObject("Game Graphics/newbackground1.png",0,0,1536,768);
    startgame = new GameObject("Game Graphics/playgame.png",620,380,200,90);

    ground = new GameObject("Game Graphics/ground.png",0,0,1536,768);

    turtle = new GameObject("Game Graphics/Character/turtle.png",0,100,65,52);
    turtlerun = new GameObject("Game Graphics/Character/run.png",260,500,50,52);
    ogre = new GameObject("Game Graphics/Character/ogre.png",-10,650,55,58);
    box = new GameObject("Game Graphics/Box.png",100,100,61,68);
    nonogram = new GameObject("Game Graphics/nonogram.png",600,200,525,525);
    for (int i = 0; i < 15; i++)
    {
        for (int j = 0; j < 15; j++)
        {
            color[i][j] = new GameObject("Game Graphics/puzzle/x_black.png", j * PUZZLE_SIZE + START_X_GRID, i * PUZZLE_SIZE + START_Y_GRID, PUZZLE_SIZE, PUZZLE_SIZE);
        }
    }
    _map = new Map();

    LoadNgram("mapNgram.txt");
    for (int i = 0; i < 15; i++)
    {
        for (int j = 0; j < 15; j++)
        {
            std::cout << mapn[i][j] << " ";
        }
        std::cout << std::endl;
    }
    sgNgram->Suggest(mapn);
}

void Game::Start()
{
    SDL_RenderClear(renderer);
    background->Update();
    startgame->Update();

    background->Render();
    startgame->Render();

	SDL_RenderPresent(renderer);

	while(SDL_PollEvent(&event)){
        switch (event.type)
        {
            case SDL_QUIT :
                clean();
                break;
            case SDL_MOUSEBUTTONDOWN:
                SDL_GetMouseState(&mouse_x, &mouse_y);

                if(event.button.button == SDL_BUTTON_LEFT){
                    if(mouse_x >= startgame->getX() && mouse_x <= startgame->getX() + startgame->getWidth() &&
                   mouse_y >= startgame->getY() && mouse_y <= startgame->getY() + startgame->getHeight()){
                       isRunning = true;
                    }
                }
                break;
            default:
                break;
        }
	}
}

void Game::update()
{
    ground->Update();
    turtle->Update();
    turtlerun->Update();
    ogre->Update();

    turtlerun->x_pos+=2;
    turtlerun->y_pos--;
    ogre->x_pos+=2;
    ogre->y_pos--;
    box->Update();

    if (isNonogram)
    {
        nonogram->Update();

        for (int i = 0; i < 15; i++)
        {
            for (int j = 0; j < 15; j++)
            {
                if (current[i][j] == 1)
                {
                    color[i][j] = new GameObject("Game Graphics/puzzle/black.png", j * PUZZLE_SIZE + START_X_GRID, i * PUZZLE_SIZE + START_Y_GRID, PUZZLE_SIZE, PUZZLE_SIZE);
                }
                else if (current[i][j] == 2)

                {
                    color[i][j] = new GameObject("Game Graphics/puzzle/red.png", j * PUZZLE_SIZE + START_X_GRID, i * PUZZLE_SIZE + START_Y_GRID, PUZZLE_SIZE, PUZZLE_SIZE);
                }
                 else if (current[i][j] == -1)
                {
                    color[i][j] = new GameObject("Game Graphics/puzzle/x_black.png", j * PUZZLE_SIZE + START_X_GRID, i * PUZZLE_SIZE + START_Y_GRID, PUZZLE_SIZE, PUZZLE_SIZE);
                }
                else if (current[i][j] == -2)

                {
                    color[i][j] = new GameObject("Game Graphics/puzzle/x_red.png", j * PUZZLE_SIZE + START_X_GRID, i * PUZZLE_SIZE + START_Y_GRID, PUZZLE_SIZE, PUZZLE_SIZE);
                }
                color[i][j]->Update();
            }
        }
    }

    turtle->HandleMove();
}
void Game::render()
{
	SDL_RenderClear(renderer);
    ground->Render();

    _map->DrawMap();

    turtle->Render();
    turtlerun->Render();
    ogre->Render();
    box->Render();
    if (isNonogram)
    {
        nonogram->Render();

        for (int i = 0; i < 15; i++)
        {
            for (int j = 0; j < 15; j++)
            {
                color[i][j]->Render();
            }
        }
    }
	SDL_RenderPresent(renderer);
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
                break;
            case SDL_MOUSEBUTTONDOWN:
                SDL_GetMouseState(&mouse_x, &mouse_y);

                if(event.button.button == SDL_BUTTON_LEFT){
                   if(mouse_x >= box->getX() && mouse_x <= box->getX() + box->getWidth() && mouse_y >= box->getY() && mouse_y <= box->getY() + box->getHeight())
                    {
                        isNonogram = true;
                        std::cout << "Nonogram" << std::endl;
                        GameNgram *Ngram = new GameNgram();

                    }
                    else if (mouse_x >= nonogram->getX() && mouse_x <= nonogram->getX() + nonogram->getWidth() && mouse_y >= nonogram->getY() && mouse_y <= nonogram->getY() + nonogram->getHeight() && isNonogram)
                    {
                        Ngram->handleEventNgramClickLeft(mouse_x, mouse_y);
                    }
                }
                else if (event.button.button == SDL_BUTTON_RIGHT)
                {
                    if (mouse_x >= nonogram->getX() && mouse_x <= nonogram->getX() + nonogram->getWidth() && mouse_y >= nonogram->getY() && mouse_y <= nonogram->getY() + nonogram->getHeight() && isNonogram)
                    {
                        Ngram->handleEventNgramClickRight(mouse_x, mouse_y);
                    }
                }
                break;

            default:
                break;
        }
    }
}

void Game::LoadNgram(const char* filepath)
{
    std::ifstream file(filepath);
    if(!file.is_open()) return;

    for(int i=0;i<15;i++){
        for(int j=0;j<15;j++){
            file >> mapn[i][j];
        }
    }
    file.close();
}

bool Game::checkCollision(const SDL_Rect& obj_1, const SDL_Rect& obj_2)
{
    int left_1 = obj_1.x;
    int right_1 = obj_1.x + obj_1.w;
    int top_1 = obj_1.y;
    int bottom_1 = obj_1.y + obj_1.h;

    int left_2 = obj_2.x;
    int right_2 = obj_2.x + obj_2.w;
    int top_2 = obj_2.y;
    int bottom_2 = obj_2.y + obj_2.h;

    if (left_1 > left_2 && left_1 < right_2)
    {
        if (top_1 > top_2 && top_1 < bottom_2)
        {
          return true;
        }

        if (bottom_1 > top_2 && bottom_1 < bottom_2)
        {
          return true;
        }
    }
    if(right_1 > left_2 && right_1 < right_2){
        if (top_1 > top_2 && top_1 < bottom_2)
        {
            return true;
        }
        if (bottom_1 > top_2 && bottom_1 < bottom_2)
        {
          return true;
        }
    }

    if (left_2 > left_1 && left_2 < right_1)
    {
        if (top_2 > top_1 && top_2 < bottom_1)
        {
          return true;
        }
        if (bottom_2 > top_1 && bottom_2 < bottom_1)
        {
          return true;
        }
    }

    if (right_2 > left_1 && right_2 < right_1)
    {
        if (top_2 > top_1 && top_2 < bottom_1)
        {
          return true;
        }
        if (bottom_2 > top_1 && bottom_2 < bottom_1)
        {
          return true;
        }
    }

    if (top_1 == top_2 && right_1 == right_2 && bottom_1 == bottom_2)
    {
        return true;
    }

    return false;

}

void Game::clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
}

