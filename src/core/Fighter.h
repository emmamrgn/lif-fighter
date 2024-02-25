/**
 * @brief Module qui gère un personnage (Fighter)
 *
 * @file Fighter.h
 *
 */

#pragma once

#include "string.h"
#include "Field.h"
#include "Hitbox.h"
#include "CharacterState.h"

using namespace std;


/**
 * @brief La classe Fighter est définie par sa position 2D (x,y), son nombre de point de vie et ses 2 Hitbox.
 * 
 */
class Fighter
{
    public:
        CharacterState PlayerState;
        
        /**
         * @brief Construit un objet Fighter
         * 
         */
        Fighter();

        /**
         * @brief Construit un objet Fighter avec ses paramètres.
         * 
         * @param x : abscisse de la position du fighter
         * @param y : ordonnée de la postion du fighter
         * @param hp : son nombre de point de vie
         * @param width : largeur du fighter
         * @param height : hauteur du fighter
         */
        Fighter(int x, int y, int hp, int height, int width);

        /**
         * @brief Detruit un objet Fighter
         * 
         */
        ~Fighter();

        /**
         * @brief Définit la position d'un fighter
         * 
         * @param x : abscisse 
         * @param y : ordonnée
         */
        void setPosition(int x, int y);

        /**
         * @brief Renvoie l'abscisse de la position
         */
        int getPositionX() const;

        /**
         * @brief Renvoie l'ordonnée de la position
         */
        int getPositionY() const;

        /**
         * @brief Defini les points de vie du fighter
         * 
         * @param hp : points de vie
         */
        void setHealth(const int hp);

        /**
         * @brief Renvoie les point de vie du fighter
         * 
         * @param hp : points de vie
         */
        int getHealth() const;

        /**
         * @brief Déplacement du fighter vers la gauche
         * 
         * @param f 
         */
        void left(const Field &f);

        /**
         * @brief Déplacement du fighter vers la droite
         * 
         * @param f 
         */
        void right(const Field &f);

        /**
         * @brief Action de saut du fighter
         * 
         * @param f 
         */
        void jump(const Field &f);

        /**
         * @brief Action d'accroupissement du fighter
         * 
         * @param f 
         */
        void crouch(const Field &f);

        /**
         * @brief Action de début du fighter
         * 
         * @param f 
         */
        void start(const Field &f);

        /**
         * @brief Renvoie un booléen si un fighter est en collision avec un autre fighter
         * 
         * @param f 
         */
        bool isColliding(const Fighter &Player2);

        /**
         * @brief Renvoie vraie si le fighter fait l'action de kick
         * 
         */
        void kick(Fighter &P2);

        /**
         * @brief Renvoie vraie si le fighter fait l'action de punch
         * 
         */
        void punch(Fighter &P2);

        /**
         * @brief Defini la hitbox de défense du fighter
         * 
         * @param X : abscisse de la position de la hitbox
         * @param Y : ordonnée de la position de la hitbox
         * @param width : largeur de la hitbox
         * @param height : longueur de la hitbox
         */
        void sethitbox(int X, int Y, float width, float height);

        /**
         * @brief Renvoie la hitbox d'de défense du fighter
         */
        Hitbox gethitbox() const;

        void RegressionTest();

    private:
        string name;

        int p_x, p_y;
        int p_hp;
        int p_width, p_height;

        bool alive = true;

        Hitbox hitbox;
        Hitbox hitbox_attack;
};