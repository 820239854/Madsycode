#ifndef ENGINE_H
#define ENGINE_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#define SCREEN_WIDTH 960
#define SCREEN_HEIGHT 640

class Engine
{
public:
    static Engine *GetInstance()
    {
        if (m_instance == nullptr)
        {
            m_instance = new Engine();
        }
        return m_instance;
    }

    bool Init();
    void Clean();
    void Quit();

    void Update(float dt);
    void Render();
    void Events();   

    inline bool IsRunning() { return m_isRunning; }
    inline SDL_Window *GetWindow() { return m_window; }
    inline SDL_Renderer *GetRenderer() { return m_renderer; }

private:
    Engine(){};
    bool m_isRunning = false;

    SDL_Window *m_window;
    SDL_Renderer *m_renderer;
    static Engine *m_instance;
};

#endif