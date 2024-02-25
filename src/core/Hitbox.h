/**
 * @brief Module qui gère les Hitbox d'un fighter
 *
 * @file Hitbox.h
 * @date 2023-03-19
 */

#pragma once

#include <iostream>
#include <cassert>
#include "string.h"

/**
 * @brief La classe Hitbox est définie par sa position (x,y), et sa taille (width, height)
 *
 */
class Hitbox
{
    public:
        int Boxwidth_hitbox;
        int Boxheight_hitbox;
        /**
         * @brief Construit une Hitbox
         */
        Hitbox();

        /**
         * @brief Détruit la Hitbox
         */
        ~Hitbox();

        /**
         * @brief Définit la position de la Hitbox en x et y
         * 
         * @param x : abscisse
         * @param y : ordonnee
         */
        void hitbox(int x, int y);

        /**
         * @brief Définit la position de la Hitbox en x
         * 
         * @param x : abscisse
         */
        void setPositionX(int x);

        /**
         * @brief Définit la position de la Hitbox en y
         * 
         * @param y : ordonnee
         */
        void setPositionY(int y);

        /**
         * @brief Renvoie la position de la Hitbox en x et en y 
         */
        int getPosition();

        /**
         * @brief Renvoie la position de la Hitbox en x
         */
        int getPositionX();

        /**
         * @brief Renvoie la position de la Hitbox en y
         */
        int getPositionY();

        /**
         * @brief Définit la taille de la Hitbox
         * 
         * @param Boxwidth : largeur 
         * @param Boxheight : hauteur
         */
        void setSize(int Boxwidth, int Boxheight);

        /**
         * @brief Définit la largeur de la Hitbox
         * 
         * @param Boxwidth : largeur
         */
        void setSizeW(int Boxwidth);

        
        int getSizeW();

        int getSizeH();

        /**
         * @brief Définit la hauteur de la Hitbox
         * 
         * @param Boxheight : hauteur
         */
        void setSizeH(int Boxheight);

        void RegresstionTest();

    private:
        int Hitbox_x, Hitbox_y;
};