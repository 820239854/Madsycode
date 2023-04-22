#include "TextureManager.h"
#include "../Core/Engine.h"

TextureManager *TextureManager::m_instance = nullptr;

bool TextureManager::Load(std::string id, std::string fileName)
{
    SDL_Surface *tempSurface = IMG_Load(fileName.c_str());
    if (tempSurface == nullptr)
    {
        SDL_Log("Unable to load image: %s", IMG_GetError());
        return false;
    }
    SDL_Texture *texture = SDL_CreateTextureFromSurface(Engine::GetInstance()->GetRenderer(), tempSurface);
    SDL_FreeSurface(tempSurface);
    if (texture == nullptr)
    {
        SDL_Log("Unable to create texture: %s", SDL_GetError());
        return false;
    }
    m_textureMap[id] = texture;
    return true;
}

void TextureManager::Draw(std::string id, int x, int y, int width, int height, SDL_RendererFlip flip)
{
    SDL_Rect srcRect = {0, 0, width, height};
    SDL_Rect destRect = {x, y, width, height};
    SDL_RenderCopyEx(Engine::GetInstance()->GetRenderer(), m_textureMap[id], &srcRect, &destRect, 0, 0, flip);
}

void TextureManager::Drop(std::string id)
{
    m_textureMap.erase(id);
}

void TextureManager::Clean()
{
    m_textureMap.clear();
}