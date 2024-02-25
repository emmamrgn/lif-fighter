/**
 * @file Animation.h
 *
 * @brief Module qui gère l'Animation du personnage.
 *
 *
 */
#pragma once

#include <string>
#include <SDL2/SDL.h>

#include "ResourceManager.h"

using namespace std;

/**
 * @class Animation
 * @brief Cette classe gère l'animation d'un personnage en sélectionnant et en affichant des images de texture.
 *
 */

class Animation
{
public:
    /**
     * @brief Constructeur par défaut de la classe Animation.
     *
     */
    Animation();

    /**
     * @brief Constructeur de la classe Animation.
     *
     * @param renderer Renderer SDL pour afficher les images.
     * @param filepath Chemin du fichier contenant la texture de l'animation.
     */
    Animation(SDL_Renderer *&renderer, string filepath);
    /**
     * @brief Destructeur de la classe Animation.
     *
     */
    ~Animation();

    /**
     * @brief Affiche l'image courante de l'animation.
     *
     * @param x Abscisse de l'image à afficher.
     * @param y Ordonnée de l'image à afficher.
     * @param w Largeur de l'image à afficher.
     * @param h Hauteur de l'image à afficher.
     */
    void Draw(int x, int y, int w, int h);

    /**
     * @brief Sélectionne et affiche une image spécifique de la texture de l'animation.
     * @param x Abscisse de l'image à afficher.
     * @param y Ordonnée de l'image à afficher.
     * @param w Largeur de l'image à afficher.
     * @param h Hauteur de l'image à afficher.
     * @param frame Numéro de l'image à afficher dans la texture de l'animation.
     */
    void PlayFrame(int x, int y, int w, int h, int frame); // Select and play specific frame

    /**
     * @brief Met à jour l'animation à chaque frame.
     *
     */
    void Update(); // Update every frame

    /**
     * @brief Affiche l'animation complète.
     *
     * @param renderer Renderer SDL pour afficher les images.
     */
    void Render(SDL_Renderer *&renderer);

private:
    SDL_Rect m_src;         /**< Où on sélectionne l'image dans la texture. */
    SDL_Rect m_dst;         /**< Où on affiche l'image. */
    SDL_Texture *m_texture; /**< Texture de l'animation.*/
};