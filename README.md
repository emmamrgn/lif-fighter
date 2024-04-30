## LIF-FIGHTER

Un jeu de combat simple en 2D style Street-Fighter.

*(réalisé dans le cadre de l'UE Conception Et Développement D'Applications)*

## Créateurs :
* DJAMAKORZIAN Sasha 
* MORGENSTERN Emma 

## Installation

### Linux :

Vérifiez que toute la librairie SDL2 est bien installée avec la commande suivante : 

`sudo apt-get install libsdl2-dev libsdl2-image-dev libsdl2-ttf-dev libsdl2-mixer-dev`


### Windows :

Il n'y a pas de version du jeu sous Windows même mais il est possible d'utiliser WSL. 

Sous WSL, la commande de l'installation de la librairie est la même sous Linux _(voir ci-dessus)_.

*Comment installer WSL : https://learn.microsoft.com/fr-fr/windows/wsl/install*

## Utilisation

### Linux et WSL :

Dans le répertoire racine :

Tapez la commande make pour compiler le projet et obtenir les executables.

La commande :
* bin/SDL permet d'éxécuter le jeu avec la librairie SDL
* bin/test permet d'éxécuter les tests de régressions

## Comment jouer ?

### Les touches du Menu : 

* 1 : Play pour accéder au jeu 
* 2 : Infos pour accéder aux infos du jeu (les touches)
* 3 : Quit pour quitter le jeu

*A noter : la touche ECHAP et la croix de la fenetre ferme le menu et le jeu*

### Les touches en Jeu : 

* Joueur de gauche : 
    - D : déplacement à droite
    - Q : déplacement à gauche
    - S : s'accroupir
    - C : coup de poing
    - V : coup de pied

* Joueur de droite :
    - L : déplacement à droite
    - J : déplacement à gauche
    - K : s'accroupir
    - B : coup de poing
    - N : coup de pied

* Quand le jeu est fini : 
    - ECHAP : pour quitter le jeu

* Refaire une partie : 
    - rentrer la commande `bin/SDL` dans le terminal


## Organisation des répertoires et des fichiers

* **README.txt** : Le README que vous lisez actuellement.

* **UML.png** : Le diagramme UML du jeu

* **doc/** : Contient le fichier .doxy et l'index vers la page de documentation du jeu.

* **data/** : Contient tous les fichiers utilisés pour l'affichage des personnages et de leurs animations, du background et des différents sons.

* **obj/** : Contient les fichiers objets permettant de créer les exécutables

* **bin/** : Contient les exécutables.

* **src/** : 
    - core/ : contient le code des différents module du noyau du jeu
    - SDL/ : contient le code concernant l'affichage sfml
    - txt/ : les fichiers de la version texte de la démo mi-parcours

* **Makefile** : Permet de compiler tout le code, de créer les fichiers .obj et les exécutables.
