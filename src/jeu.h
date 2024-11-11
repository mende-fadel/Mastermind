/**
 * @file jeu.h
 * @brief Implémentation du mécanisme de fonctionnement du jeu 
 * @author      Mohamed MAACHE <mohamed.maache@etu.unistra.fr>
 * @author      Fadel MENDE <fadel.mende@etu.unistra.fr>
 * @author      Serge MUKOKA <serge.mukoka@etu.unistra.fr>
 * @version     0.1
 * @date        2024
 * 
 */
#ifndef JEU_H
#define JEU_H

#include "affichage.h"
#include "couleurs.h"
#include "chargeur_fichier.h"
#include "input.h"
#include "random.h"
#include <string.h>
#define MAX_TRIES 10
#define MAX_COLORS 4
#define MAX_COLOR_LENGTH 4
#define LONGUEUR_COMBINAISON 4



void jouer_jeu(int mode_difficile);
int choisir_mode_couleur();
int choisir_mode_difficile();
void afficher_regles();
void evaluer_supposition(const char secret_combinaison[LONGUEUR_COMBINAISON + 1], const char guess_combinaison[LONGUEUR_COMBINAISON + 1], Res* resultat);
void afficher_solution(const char secret_combinaison[MAX_COLOR_LENGTH]);
int jeu_initialisation(int mode_initialisation, char sequence[MAX_COLOR_LENGTH]);
int verifier_victoire(const char sequence[LONGUEUR_COMBINAISON + 1], const char supposition[LONGUEUR_COMBINAISON + 1]);
void evaluer_supposition_difficile(const char secret_combinaison[LONGUEUR_COMBINAISON + 1], const char guess_combinaison[LONGUEUR_COMBINAISON + 1], Res* resultat);
#endif 
