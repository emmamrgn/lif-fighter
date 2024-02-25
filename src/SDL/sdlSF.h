/**
 * @file sdlSF.h
 * @brief Module qui gère la classe SDLSimple et la boucle de jeu.
 * 
 * 
 */

#pragma once

#include "../core/Game.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>

#include <stdlib.h>
#include <iostream>
#include <time.h>

#include "Animation.h"
#include "AnimationData.h"
#include "Menu.h"
#include "Image.h"
#include "../core/CharacterState.h"

/**
 * @brief La classe SDL pour gérer le jeu avec un affichage SDL.
*/

class SDLSimple 
{
    private:
    
        Game game;

        SDL_Window * window; /**< Fenêtre SDL dans laquelle le jeu est affiché */
        SDL_Renderer *renderer; /**< Renderer SDL pour dessiner des textures */
        TTF_Font * font; /**< Police utilisée pour le texte */
        Pic font_im; /**< Texture pour la police */
        SDL_Color font_color; /**< Couleur de la police */

        Pic background; /**< Texture d'arrière-plan pour le jeu */

        Pic im_iconRise; /**< Texture de l'icône Rise */
        Pic im_iconYukiko; /**< Texture de l'icône Yukiko */

        Pic im_EndingRise; /**< Texture de fin de partie pour Rise */
        Pic im_NameRise; /**< Texture du nom de Rise pour l'écran de fin */
        Pic im_EndingYukiko; /**< Texture de fin de partie pour Yukiko */
        Pic im_NameYukiko; /**< Texture du nom de Yukiko pour l'écran de fin */
        Pic im_RiseWin;

        bool keyboard; /**< Indique si le clavier est utilisé */
        bool withSound; /**< Indique si le son est activé */

        Mix_Music * soundmp3; /**< Objet de musique SDL pour la musique de fond */
        Mix_Chunk* soundwav; /**< Objet de son SDL pour les effets sonores */

        Fighter& player = game.getPlayer1(); /**< Référence au premier personnage joueur */
        Fighter& player2 = game.getPlayer2(); /**< Référence au deuxième personnage joueur */




        // SDL_Renderer *menuRenderer;
        Menu mainMenu;
        // enum GameState {MENU,PLAY,INFOS,QUIT};
        // GameState State = GameState::MENU;

    public:

        static int frameNumber; /**< Numéro du frame actuel de l'animation du joueur 1 */
        static int frameNumber2; /**< Numéro du frame actuel de l'animation du joueur 2 */

        int AnimationWidth = tabRise[player.PlayerState.state].AnimationWidth; /**< Largeur de l'animation en cours du joueur 1 */
        int AnimationHeight = tabRise[player.PlayerState.state].AnimationHeight; /**< Hauteur de l'animation en cours du joueur 1 */
        int NbFrames = tabRise[player.PlayerState.state].NbFrames; /**< Nombre de frames de l'animation en cours du joueur 1 */

        int AnimationWidth2 = tabYukiko[player2.PlayerState.state].AnimationWidth; /**< Largeur de l'animation en cours du joueur 2 */
        int AnimationHeight2 = tabYukiko[player2.PlayerState.state].AnimationHeight; /**< Hauteur de l'animation en cours du joueur 2 */
        int NbFrames2 = tabYukiko[player2.PlayerState.state].NbFrames; /**< Nombre de frames de l'animation en cours du joueur 2 */
        /**
         * @brief Constructeur de SDLSimple
         */
        SDLSimple();

        /**
         * @brief Destructeur de SDLSimple
         */
        ~SDLSimple();

        /**
         * @brief Boucle principale du jeu avec SDL
         */
        void sdlBoucle ();

        /**
         * @brief Affiche les textures à l'écran
         */
        void sdlAff ();

        /**
         * @brief Crée le menu principal du jeu
         */
        void createMenu();

        /**
         * @brief Joue un fichier son
         * @param soundFile Nom du fichier son à jouer
         */
        void playMoveSound(const char* soundFile);

        /**
         * @brief Affiche la barre d'hp des fighters à l'écran
         */
        void hp_bar();

        /**
         * @brief Met en place les collisions et l'impact sur les poins de vie / affiche si besoin les hitboxes des personnages à l'écran.
         */
        void hitboxes();

        /**
         * @brief Met en place la fin de partie.
         * 
         */
        void endgame();

        /**
         * @brief Tableau de données d'animation pour Rise
         */
        AnimationData tabRise[11];

        /**
         * @brief Tableau de données d'animation pour Yukiko
         */
        AnimationData tabYukiko[11];
};