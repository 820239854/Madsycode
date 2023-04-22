#pragma once

#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <map>

class TextureManager
{
public:
    static TextureManager *GetInstance()
    {
        if (m_instance == nullptr)
        {
            m_instance = new TextureManager();
        }
        return m_instance;
    }

    bool Load(std::string id, std::string fileName);
    void Draw(std::string id, int x, int y, int width, int height, SDL_RendererFlip flip = SDL_FLIP_NONE);
    void Drop(std::string id);
    void Clean();

private:
    TextureManager(){};
    std::map<std::string, SDL_Texture *> m_textureMap;
    static TextureManager *m_instance;
};