#include <string>

#include <SDL2/SDL.h>

#include "Animation.h"
#include "ResourceManager.h"
#include <iostream>

using namespace std;

Animation::Animation(){}

Animation::Animation(SDL_Renderer*& renderer, string filepath)
{
    SDL_Surface* retrieveSurface = ResourceManager::GetInstance().GetSurface(filepath);
    //faire test pour savoir si fichier bien ouvert
    m_texture = SDL_CreateTextureFromSurface(renderer,retrieveSurface);
}

Animation::~Animation()
{
    SDL_DestroyTexture(m_texture);
}

void Animation::Draw(int x, int y, int w, int h)
{
    //create a rectangle
    m_dst.x = x;
    m_dst.y = y;
    m_dst.w = w;
    m_dst.h = h;
}

void Animation::PlayFrame(int x, int y, int w, int h, int frame)//Select and play specific frame
{
    m_src.x = x+w*frame;
    m_src.y = y;
    m_src.w = w;
    m_src.h = h;
}

void Animation::Update() //Update every frame
{}

void Animation::Render(SDL_Renderer*&renderer)
{
    SDL_RenderCopy(renderer,m_texture,&m_src,&m_dst);
}
