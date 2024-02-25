#include "Menu.h"
#include <SDL2/SDL_ttf.h>

Menu::Menu()
{
    // init ttf pour l'affichage texte
    if (TTF_Init() != 0)
    {
        cout << "Erreur lors de l'initialisation de la SDL_ttf : " << TTF_GetError() << endl;
        SDL_Quit();
        exit(1);
    }

    // taille de la fenetre du menu
    dimx = 720;
    dimy = 480;

    // police pour le texte
    font = TTF_OpenFont("data/fontMenu.ttf", 90);
    if (font == nullptr)
    {
        cout << "Failed to load .ttf! SDL_TTF Error: " << TTF_GetError() << endl;
        SDL_Quit();
        exit(1);
    }

    // couleur de l'affichage du texte
    fontColor.r = 0;
    fontColor.g = 0;
    fontColor.b = 0;
    fontColor.a = 255;

    // position/taille du Rect pour l'affichage du PLAY
    posPlay.x = dimx / 2 - 40;
    posPlay.y = 70;
    posPlay.h = 100;
    posPlay.w = 100;

    // position/taille du Rect pour l'affichage du INFOS
    posInfos.x = dimx / 2 - 40;
    posInfos.y = 180;
    posInfos.h = 100;
    posInfos.w = 100;

    // position/taille du Rect pour l'affichage du QUIT
    posQuit.x = dimx / 2 - 40;
    posQuit.y = 290;
    posQuit.h = 100;
    posQuit.w = 100;

    // creation de la fenetre pour le menu
    windowMenu = SDL_CreateWindow("MENU LIF-Fighter", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, dimx, dimy, SDL_WINDOW_SHOWN /*| SDL_WINDOW_POPUP_MENU*/);

    if (windowMenu == nullptr)
    {
        cout << "Erreur lors de la creation de la fenetre : " << SDL_GetError() << endl;
        SDL_Quit();
        exit(1);
    }

    // renderer du menu
    rendererMenu = SDL_CreateRenderer(windowMenu, -1, 0);

    // chargement image background menu
    im_background.loadFromFile("data/menu_background.png", rendererMenu);
    im_background.draw(rendererMenu, 0, 0, dimx, dimy);

    // chargement surface du PLAY
    im_txtPlay.setSurface(TTF_RenderText_Solid(font, "1 : PLAY", fontColor));
    im_txtPlay.loadCurrentSurface(rendererMenu);
    TTF_SizeText(font, "1 : PLAY", &posPlay.w, &posPlay.h);
    SDL_RenderCopy(rendererMenu, im_txtPlay.getTexture(), NULL, &posPlay);

    // chargement surface INFOS
    im_txtInfos.setSurface(TTF_RenderText_Solid(font, "2 : INFOS", fontColor));
    im_txtInfos.loadCurrentSurface(rendererMenu);
    TTF_SizeText(font, "2 : INFOS", &posInfos.w, &posInfos.h);
    SDL_RenderCopy(rendererMenu, im_txtInfos.getTexture(), nullptr, &posInfos);

    // chargement surface QUIT
    im_txtQuit.setSurface(TTF_RenderText_Solid(font, "3 : QUIT", fontColor));
    im_txtQuit.loadCurrentSurface(rendererMenu);
    TTF_SizeText(font, "3 : QUIT", &posQuit.w, &posQuit.h);
    SDL_RenderCopy(rendererMenu, im_txtQuit.getTexture(), nullptr, &posQuit);

    SDL_RenderPresent(rendererMenu);

    SDL_Event events;
    bool quit = false;

    while (!quit)
    {
        while (SDL_PollEvent(&events))
        {
            if (events.type == SDL_QUIT)
                quit = true;
            else if (events.type == SDL_KEYDOWN)
            {
                switch (events.key.keysym.scancode)
                {
                case SDL_SCANCODE_1:
                    stateM = menuState::PLAY;
                    SDL_HideWindow(windowMenu);
                    quit = true;
                    break;
                case SDL_SCANCODE_2:
                    stateM = menuState::INFOS;
                    displayInfos();
                    cout << "infos.png" << endl;
                    break;
                case SDL_SCANCODE_3:
                case SDL_SCANCODE_ESCAPE:
                    stateM = menuState::QUIT;
                    quit = true;
                    break;
                default:
                    break;
                }
            }
        }
    }
    SDL_RenderPresent(rendererMenu);
};

Menu::~Menu()
{
    TTF_CloseFont(font);
    SDL_DestroyRenderer(rendererMenu);
    SDL_DestroyWindow(windowMenu);
    SDL_Quit();
}

void Menu::displayInfos()
{
    SDL_RenderClear(rendererMenu);
    im_infos.loadFromFile("data/menu/infos.png", rendererMenu);
    im_infos.draw(rendererMenu, 0, 0, posInfos.w, posInfos.h);
    SDL_RenderPresent(rendererMenu);
}