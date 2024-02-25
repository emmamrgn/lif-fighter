#include "ResourceManager.h"
#include <SDL2/SDL_image.h>

#include <iostream>

using namespace std;

ResourceManager::ResourceManager(){}

ResourceManager::ResourceManager(ResourceManager const&){}

ResourceManager::~ResourceManager(){
    for(auto it = m_surfaces.begin(); it != m_surfaces.end(); ++it){
        SDL_FreeSurface(it->second);
    }
}

ResourceManager ResourceManager::operator=(ResourceManager const& rhs){
    return *this;
}

// Is instantiate, exactly 1 instance of our class
ResourceManager& ResourceManager::GetInstance(){
    static ResourceManager* s_instance = new ResourceManager;
    return *s_instance;
}

SDL_Surface* ResourceManager::GetSurface(std::string filepath){
    // We will, look through, our m_surface which is a 'unordered_map' and see if
    // a file exists and if the file does exist, then return the associated surface.
    auto search = m_surfaces.find(filepath);
    if(search != m_surfaces.end()){
        return m_surfaces[filepath];
    }else{
        SDL_Surface* surface = IMG_Load(filepath.c_str());
        m_surfaces.insert(std::make_pair(filepath,surface));
        return m_surfaces[filepath];
    }
    
    return nullptr;

}

void ResourceManager::RegressionTest()
{
    ResourceManager& rm = ResourceManager::GetInstance();
    SDL_Surface* surface = rm.GetSurface("assets/spritesheetR_walk.png");
    if(surface == nullptr){
        cout << "RegressionTest failed" << endl;
    }else{
        cout << "RegressionTest passed" << endl;
    }
}