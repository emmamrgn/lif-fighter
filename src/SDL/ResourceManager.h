/**
 * @file ResourceManager.h
 * 
 * @brief Module qui gère les ressources SDL (ResourceManager)
 * 
 * 
 */
#pragma once

#include <string>
#include <unordered_map>

#include <SDL2/SDL.h>
/**
 * @brief La classe ResourceManager est une classe Singleton qui gère les ressources SDL.
 * 
 */
class ResourceManager
{
    public:
        /**
         * @brief Obtient l'instance unique de ResourceManager
         * 
         * @return L'instance unique
         */
        static ResourceManager& GetInstance(); 

        /**
         * @brief Détruit l'objet ResourceManager
         * 
         */
        ~ResourceManager();

        /**
         * @brief Obtient surface correspondant à un fichier image spécifié
         * 
         * @param filepath = chemin du fichier image
         * @return pointeur vers surface SDL correspondant au fichier spécifié ou nullptr si n'a pas été trouvé
         */
        SDL_Surface* GetSurface(std::string filepath);

    private:
        /**
         * @brief Construit l'objet ResourceManager
         * 
         */
        ResourceManager();

        /**
         * @brief Construit une copie de l'objet ResourceManager
         * @param Référence vers un autre objet ResourceManager
         * 
         */
        ResourceManager(ResourceManager const&);

        /**
         * @brief 
         * @param Référence vers un autre objet ResourceManager
         * @return Référence vers l'objet ResourceManager actuel 
         */
        ResourceManager operator=(ResourceManager const&);

        /**
         * @brief Tableau associatif qui contient les surfaces SDL correspondant aux fichiers chargés
         * 
         */
        std::unordered_map<std::string, SDL_Surface*> m_surfaces;

        /**
         * @brief Effectue un test de Regression pour s'assurer que les fonctions de la classe fonctionne
         * 
         */
        void RegressionTest();

};