/**
 * @file        affichage.h
 * @brief       fichier d'en-tête du affichage.c
 * @author      Mohamed MAACHE <mohamed.maache@etu.unistra.fr>
 * @author      Fadel MENDE <fadel.mende@etu.unistra.fr>
 * @author      Serge MUKOKA <serge.mukoka@etu.unistra.fr>
 * @version     0.1
 * @date        2024
 */
#include "chargeur_fichier.h"
#ifndef AFFICHAGE_H
#define AFFICHAGE_H

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

typedef struct {
    int black;
    int white;
} Res;

void affichage_debut(int useColor);

void affichage_guess(const int guess_nombre, const char guess[MAX_COLOR_LENGTH + 1], const Res resultat, int mode_couleur);
void clearScreen();
void displayWinScreen();
void displayLoseScreen();
void animateStartScreen();

#endif

