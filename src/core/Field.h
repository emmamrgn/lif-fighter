/**
 * @brief Module qui gère le terrain (Field)
 *
 * Un Field est un tableau 2D de caractères de taille f_dimx x f_dimy
 * La taille maximum d'un terrain est de 720x480.
 *
 * @file Field.h
 * @date 2023-03-07
 */

#pragma once

#include <cassert>

/**
 * @brief La classe Field contient ses dimensions et un tab 2D de cases (1 case = 1 char)
 *
 */
class Field
{
    public:
        /**
         * @brief Construit un objet Field
         * Le constructeur remplit dimx et dimy et les cases du tableau field avec un terrain par défaut.
         */
        Field();

        /**
         * @brief Renvoie vraie si on peut positionner un personnage au coordonnées (x,y), faux sinon
         * 
         * @param x : abscisse de la case à tester
         * @param y : ordonnée de la case à tester
         */
        bool isPositionValid(const int x, const int y) const;

        /**
         * @brief Renvoie la largeur du field
         */
        int getDimX() const;

        /**
         * @brief Renvoie la hauteur du field
         * 
         * @return int 
         */
        int getDimY() const;

        /**
         * @brief Renvoie le type d'objet au coordonnées (x,y)
         * 
         * @param x : abscisse de la case de l'objet
         * @param y : ordonnée de la case de l'objet
         */
        unsigned char getXYasChar(const int x, const int y) const;

        void RegressionTest();

    private:
        enum TypeCase
        {
            SPACE = ' ',
            WALL = '#'
        };

        int f_dimx;
        int f_dimy;
        TypeCase field[720][480];
};

inline unsigned char Field::getXYasChar(const int x, const int y) const
{
    assert(x >= 0);
    assert(y >= 0);
    assert(x < f_dimx);
    assert(y < f_dimy);
    return (char)(field[x][y]);
} 
