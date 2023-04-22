#include <iostream>
#include <SDL2/SDL.h>
#include "Engine.h"

Engine *Engine::m_instance = nullptr;

void Engine::Init()
{
    const int WIDTH = 800;
    const int HEIGHT = 600;

    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_Window *wnd = SDL_CreateWindow("HELLO", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_ALLOW_HIGHDPI);
    if (NULL == wnd)
    {
        std::cout << "Could not create Window" << SDL_GetError() << std::endl;
        return;
    }
    m_isRunning = true;
}

void Engine::Update(float dt)
{
    std::cout << "Update" << std::endl;
}

void Engine::Render()
{
}

void Engine::Events()
{
}

void Engine::Clean()
{
}

void Engine::Quit()
{
}