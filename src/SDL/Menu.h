/**
 * @file Menu.h
 *
 * @brief Module qui gère le Menu et son affichage.
 *
 *
 */
#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

#include <stdlib.h>
#include <iostream>

#include "Image.h"

using namespace std;

class Menu
{
public:
    /**
     * @brief Constructeur de la classe Menu
     * 
     */
    Menu();
    /**
     * @brief Destructeur de la classe Menu
     * 
     */
    ~Menu();

    /**
     * @brief Enumération pour les différents états du menu.
     *
     */
    enum menuState { MENU,PLAY,INFOS,QUIT}; // différents etat du menu
    
    menuState stateM = menuState::MENU; /**< Etat par défaut du menu. */

    /**
     * @brief Fonction pour afficher la page Infos du menu.
     *
     */
    void displayInfos(); // affichage de la page infos

private:
    int dimx, dimy; /**< Dimensions de la fenêtre du menu. */

    TTF_Font *font;      /**< Police d'écriture pour le menu. */
    SDL_Color fontColor; /**< Couleur de la police d'écriture. */

    SDL_Renderer *rendererMenu; /**< Renderer pour le menu. */
    SDL_Window *windowMenu;     /**< Fenêtre pour le menu. */

    SDL_Rect posPlay;  /**< Position de l'option PLAY sur le menu. */
    SDL_Rect posInfos; /**< Position de l'option INFOS sur le menu. */
    SDL_Rect posQuit;  /**< Position de l'option QUIT sur le menu. */

    Pic im_txtPlay;  /**< Image pour l'option PLAY sur le menu. */
    Pic im_txtInfos; /**< Image pour l'option INFOS sur le menu. */
    Pic im_txtQuit;  /**< Image pour l'option QUIT sur le menu. */

    Pic im_infos;      /**< Page Infos du menu : image avec les informations. */
    Pic im_background; /**< Image du fond d'écran du menu. */

};