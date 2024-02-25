/**
 * @file AnimationData.h
 *
 * @brief Module qui gère les informations des animations (AnimationData)
 * 
 * 
 */
#pragma once

#include <string>
#include <stdlib.h>
#include <iostream>

using namespace std;

/**
 * @brief La classe AnimationData gère les informations des animations
 * 
 */
class AnimationData
{
    public:
        /**
         * @brief Construit l'objet AnimationData
         * 
         */
        AnimationData();
        /**
         * @brief Construit l'objet AnimationData avec un fichier CSV et un nom d'animation
         * 
         * @param CSVFile = chemin du fichier CSV contenant les informations des animations
         * @param animationName = nom de l'animation
         */
        AnimationData(string CSVFile, string animationName);

        /**
         * @brief Detruit l'objet AnimationData
         * 
         */
        ~AnimationData();

        string AnimationName; /**< Nom de l'animation */

        int NbFrames; /**< Nombre de frames de l'animation */

        int AnimationWidth; /**< Largeur de l'animation */

        int AnimationHeight; /**< Hauteur de l'animation */

        /**
         * @brief Effecture un test de Regression pour s'assurer que les fonctions de la classe fonctionne
         * 
         */
        void RegressionTest();
};