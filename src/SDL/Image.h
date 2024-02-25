/**
 * @file Image.h
 * @brief Module qui gère l'affichage et la manipulation d'images (Pic)
 *
 */

#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

#include <iostream>
#include <assert.h>
#include <string.h>

using namespace std;

/**
 * @class Pic
 * @brief Classe qui gère l'affichage et la manipulation d'images.
 *
 */
class Pic
{

public:
    /**
     * @brief Constructeur par défaut
     */
    Pic();
    /**
     * @brief Destructeur
     */
    ~Pic();

    /**
     * @brief Charge une image depuis un fichier et la transforme en texture
     *
     * @param filename Le nom du fichier de l'image à charger
     * @param renderer Le SDL_Renderer sur lequel la texture sera dessinée
     */
    void loadFromFile(const char *filename, SDL_Renderer *renderer);

    /**
     * @brief Charge la surface courante en tant que texture
     *
     * @param renderer Le SDL_Renderer sur lequel la texture sera dessinée
     */
    void loadCurrentSurface(SDL_Renderer *renderer);

    /**
     * @brief Dessine la texture sur le SDL_Renderer aux coordonnées (x,y) avec une largeur et une hauteur optionnelles
     *
     * @param renderer Le SDL_Renderer sur lequel la texture sera dessinée
     * @param x Coordonnée x de la texture
     * @param y Coordonnée y de la texture
     * @param w Largeur de la texture (optionnelle, la taille réelle de l'image sera utilisée si non fournie)
     * @param h Hauteur de la texture (optionnelle, la taille réelle de l'image sera utilisée si non fournie)
     */
    void draw(SDL_Renderer *renderer, int x, int y, int w = -1, int h = -1);

    /**
     * @brief Renvoie la texture
     *
     * @return SDL_Texture* La texture de l'image
     */
    SDL_Texture *getTexture() const;

    /**
     * @brief Renvoie la surface
     *
     * @return SDL_Surface* La surface de l'image
     */
    SDL_Surface *getSurface() const;

    /**
     * @brief Modifie la surface de l'image
     *
     * @param surf La nouvelle surface de l'image
     */
    void setSurface(SDL_Surface *surf);

private:
    SDL_Surface *surface; /**< Surface de l'image*/
    SDL_Texture *texture; /**< Texture de l'image*/
    bool has_changed;     /**< Indique si la surface a été modifiée depuis la dernière création de la texture*/
};