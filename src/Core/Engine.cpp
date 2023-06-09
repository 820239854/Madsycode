#include "Engine.h"
#include "../Graphics/TextureManager.h"

Engine *Engine::m_instance = nullptr;

bool Engine::Init()
{
    if (SDL_Init(SDL_INIT_EVERYTHING))
    {
        SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
        return false;
    }
    int img_flags = IMG_INIT_JPG | IMG_INIT_PNG;
    if ((IMG_Init(img_flags) & img_flags) != img_flags)
    {
        printf("Unable to initialize SDL_image: %s\n", IMG_GetError());
        return false;
    }

    m_window = SDL_CreateWindow("HELLO", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_ALLOW_HIGHDPI);
    if (NULL == m_window)
    {
        SDL_Log("Unable to create window: %s", SDL_GetError());
        return false;
    }
    m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (NULL == m_renderer)
    {
        SDL_Log("Unable to create renderer: %s", SDL_GetError());
        return false;
    }

    TextureManager::GetInstance()->Load("tree", "assets/tree.png");

    m_isRunning = true;
    return true;
}

void Engine::Update(float dt)
{
}

void Engine::Render()
{
    SDL_SetRenderDrawColor(m_renderer, 0, 0, 0, 255);
    SDL_RenderClear(m_renderer);

    TextureManager::GetInstance()->Draw("tree", 0, 0, 347, 465);

    SDL_RenderPresent(m_renderer);
}

void Engine::Events()
{
    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
        case SDL_QUIT:
            Quit();
            break;
        default:
            break;
        }
    }
}

void Engine::Clean()
{
}

void Engine::Quit()
{
    m_isRunning = false;
}