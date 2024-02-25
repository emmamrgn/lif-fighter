/**
 * @file CharacterState.h
 * @brief Module qui gère l'état du personnage (CharacterState)
 *
 * @date 2023-04-29
 * 
 * 
 */
#pragma once

#include <string>
#include <stdlib.h>
#include <iostream>

using namespace std;
/**
 * @brief La classe CharacterState est définie par une énumeration de différents états 
 * que le fighter peut avoir
 * 
 */
class CharacterState
{

        public:
                enum States{IDLE, WALK, WALKBACK, CROUCH, JUMP, PUNCH, KICK, HIT, START, LOSER, WINNER};
                States state = States::START;

                bool ResetFrames = false;

                /**
                 * @brief Construit un objet CharacterState
                 * 
                 */
                CharacterState();

                /**
                 * @brief Détruit un objet CharacterState 
                 * 
                 */
                ~CharacterState();

                /**
                 * @brief récupère l'état du fighter et retourne son string associé
                 * 
                 * @param state : un argument de l'énumération de type "States"
                 * @return string : état du fighter 
                 */
                string GetStateString(States state);

                /**
                 * @brief recupère et renvoie un string représentant l'état actuel d'une instance de la classe "CharacterState"
                 * Cette fonction permet de réduire les risques d'erreurs lors de la conversions des énumérations d'état en string. 
                 * 
                 * @return string : état du fighter 
                 */
                string GetCurrentStateString();

                /**
                 * @brief Met l'état d'une instance de la classe "CharacterState" à "IDLE"
                 * vérifie si état actuel est déjà "IDLE" en comparant avec valeur de l'énumération "States::IDLE"
                 * si c'est le cas, fonction se termine. Sinon, fonction modifie énumération avec opérateur d'affectation.
                 * + réinitialisation des Frames pour effectuer cet état ou un autre de nouveau.
                 */
                void Idle();

                /**
                 * @brief Met l'état d'une instance de la classe "CharacterState" à "START"
                 * 
                 */
                void Start();

                /**
                 * @brief Met l'état d'une instance de la classe "CharacterState" à "WALK"
                 * 
                 */
                void Walk();

                /**
                 * @brief Met l'état d'une instance de la classe "CharacterState" à "WALKBACK"
                 * 
                 */
                void Walkback();

                /**
                 * @brief Met l'état d'une instance de la classe "CharacterState" à "JUMP"
                 * 
                 */
                void Jump();

                /**
                 * @brief Met l'état d'une instance de la classe "CharacterState" à "CROUCH"
                 * 
                 */
                void Crouch();

                /**
                 * @brief Met l'état d'une instance de la classe "CharacterState" à "KICK"
                 * 
                 */
                void Kick();

                /**
                 * @brief Met l'état d'une instance de la classe "CharacterState" à "PUNCH"
                 * 
                 */
                void Punch();

                /**
                 * @brief Met l'état d'une instance de la classe "CharacterState" à "HIT"
                 * 
                 */
                void Hit();

                /**
                 * @brief Met l'état d'une instance de la classe "CharacterState" à "LOST"
                 * 
                 */
                void Loser();

                /**
                 * @brief Met l'état d'une instance de la classe "CharacterState" à "WON"
                 * 
                 */
                void Winner();

                void RegressionTest();
                
        private: 
                /**
                 * @brief Définit l'état du personnage à "START"
                 * 
                 */
                void SetStart();

                /**
                 * @brief Définit l'état du personnage à "IDLE"
                 * 
                 */
                void SetIdle();

                /**
                 * @brief Définit l'état du personnage à "WALK"
                 * 
                 */
                void SetWalk();

                /**
                 * @brief Définit l'état du personnage à "WALKBACK"
                 * 
                 */
                void SetWalkback();

                /**
                 * @brief Définit l'état du personnage à "JUMP"
                 * 
                 */
                void SetJump();

                /**
                 * @brief Définit l'état du personnage à "KICK"
                 * 
                 */
                void SetKick();

                /**
                 * @brief Définit l'état du personnage à "PUNCH"
                 * 
                 */
                void SetPunch();

                /**
                 * @brief Définit l'état du personnage à "CROUCH"
                 * 
                 */
                void SetCrouch();

                /**
                 * @brief Définit l'état du personnage à "HIT"
                 * 
                 */
                void SetHit();

                /**
                 * @brief Définit l'état du personnage à "LOST"
                 * 
                 */
                void SetLoser();

                /**
                 * @brief Définit l'état du personnage à "WINNER"
                 * 
                 */
                void SetWinner();
};