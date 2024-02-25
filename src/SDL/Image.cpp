#include "Image.h"

// ============= IMAGE CLASS =============== //

Pic::Pic() : surface(nullptr), texture(nullptr), has_changed(false)
{
    int imgFlags = IMG_INIT_PNG | IMG_INIT_JPG;
    if (!(IMG_Init(imgFlags) & imgFlags))
    {
        cout << "SDL_image could not initialize! SDL_image Error: " << IMG_GetError() << endl;
        SDL_Quit();
        exit(1);
    }
}

Pic::~Pic()
{
    if (!(surface == nullptr))
        SDL_FreeSurface(surface);
    if (!(texture == nullptr))
        SDL_DestroyTexture(texture);
    surface = nullptr;
    texture = nullptr;
    has_changed = false;
}

void Pic::loadFromFile(const char *filename, SDL_Renderer *renderer)
{
    surface = IMG_Load(filename);
    if (surface == nullptr)
    {
        string nfn = string("../") + filename;
        cout << "Error: cannot load " << filename << ". Trying " << nfn << endl;
        surface = IMG_Load(nfn.c_str());
        if (surface == nullptr)
        {
            nfn = string("../") + nfn;
            surface = IMG_Load(nfn.c_str());
        }
    }
    if (surface == nullptr)
    {
        cout << "Error: cannot load " << filename << endl;
        SDL_Quit();
        exit(1);
    }

    SDL_Surface *surfaceCorrectPixelFormat = SDL_ConvertSurfaceFormat(surface, SDL_PIXELFORMAT_ARGB8888, 0);
    SDL_FreeSurface(surface);
    surface = surfaceCorrectPixelFormat;

    texture = SDL_CreateTextureFromSurface(renderer, surfaceCorrectPixelFormat);
    if (texture == NULL)
    {
        cout << "Error: problem to create the texture of " << filename << endl;
        SDL_Quit();
        exit(1);
    }
}

void Pic::loadCurrentSurface(SDL_Renderer *renderer)
{
    texture = SDL_CreateTextureFromSurface(renderer, surface);
    if (texture == nullptr)
    {
        cout << "Error: problem to create the texture from surface " << endl;
        SDL_Quit();
        exit(1);
    }
}

void Pic::draw(SDL_Renderer *renderer, int x, int y, int w, int h)
{
    int ok;
    SDL_Rect r;
    r.x = x;
    r.y = y;
    r.w = (w < 0) ? surface->w : w;
    r.h = (h < 0) ? surface->h : h;

    if (has_changed)
    {
        ok = SDL_UpdateTexture(texture, nullptr, surface->pixels, surface->pitch);
        assert(ok == 0);
        has_changed = false;
    }

    ok = SDL_RenderCopy(renderer, texture, nullptr, &r);
    //assert(ok == 0);
}

SDL_Texture *Pic::getTexture() const
{
    return texture;
}

void Pic::setSurface(SDL_Surface *surf)
{
    surface = surf;
}
