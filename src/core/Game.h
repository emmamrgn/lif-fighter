/**
 * @brief Module qui gère le jeu (Game) LIF-FIGHTER
 *
 *
 * @file Game.h
 * @date 2023-03-19
 */

#pragma once

#include "Fighter.h"
#include "Field.h"
#include "Hitbox.h"

/**
 * @brief La classe Game est définie par 2 Fighter, un Field
 *
 */
class Game
{
    public:

        /**
         * @brief Construit un Game
         * 
         */
        Game();
        /**
         * @brief Detruit le Game
         * 
         */
        ~Game();

        /**
         * @brief Renvoie le fighter Player1
         */
        Fighter &getPlayer1();

        /**
         * @brief Renvoie le fighter Player2
         */
        Fighter &getPlayer2();

        /**
         * @brief Renvoie le Field du Game
         * 
         * @return const Field& 
         */
        const Field &getconstField() const;

        /**
         * @brief Renvoie le fighter Player 1
         * 
         * @return const Fighter& 
         */
        const Fighter &getconstFighter1() const;

        /**
         * @brief Renvoie le fighter Player 2
         * 
         * @return const Fighter& 
         */
        const Fighter &getconstFighter2() const;

        /**
         * @brief Renvoie vraie lorsque qu'une touche du clavier est touchée pour le Player1, faux sinon
         * 
         * @param keybind : la touche du clavier pressée
         */
        bool keyboardActionP1(const char keybind);

        /**
         * @brief Renvoie vraie lorsque qu'une touche du clavier est touchée pour le Player2, faux sinon
         * 
         * @param keybind : la touche du clavier pressée
         */
        bool keyboardActionP2(const char keybind);

        /**
         * @brief test de régression pour tester les fonctions
         */
        void regressionTest();

    private:
        Field F;
        Fighter Player1;
        Fighter Player2;
        //    Menu mainMenu;
        const int GRAVITY = 50;
};