/**
 * @file jeu.c
 * @brief Implémentation du jeu en lui-même
 * @author      Mohamed MAACHE <mohamed.maache@etu.unistra.fr>
 * @author      MUKOKA SERGE <serge.mukoka@etu.unistra.fr>
 * @author      MENDE FADEL <fadel.mende@etu.unistra.fr>
 * @version     0.1
 * @date        2024
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "affichage.h"
#include "couleurs.h"
#include "random.h"
#include "jeu.h"

#define MAX_TRIES 10
#define LONGUEUR_COMBINAISON 4



void afficher_regles(){
    printf("Bienvenue dans le jeu du Mastermind !\n");
    printf("Vous avez 10 essaies pour deviner une combinaison de 6 couleurs.\n");
    printf("Les couleurs possibles sont : R, V, B, J, L, O\n");
    printf("Voici exemple de combinaison : RVBJ\n");
    
}

int choisir_mode_couleur() {
    char choix;
    
    printf("Voulez-vous utiliser la couleur pour l'affichage ? (o/n) : ");
    scanf(" %c", &choix);
    
    if (choix == 'o' || choix == 'O') {
        return 1; 
    } else {
        return 0; 
    }
}

int choisir_mode_difficile() {
    char choix;
    
    printf("Voulez-vous jouer en mode difficile ? (o/n) : ");
    scanf(" %c", &choix);
    
    if (choix == 'o' || choix == 'O') {
        return 1; 
    } else {
        return 0; 
    }
}

int jeu_initialisation(int i, char sequence[MAX_COLOR_LENGTH]) {
    if (i == 1) {
        const char* loadedSequence = charger_sequence("./data/sequence_secrete.txt");
        strcpy(sequence, loadedSequence);

        return 1;
    } else {
        char* combinaison = combinaison_aleatoire();
        strcpy(sequence, combinaison); 
        printf("\n");
        return 1;
    }
}

void evaluer_supposition(const char secret_combinaison[LONGUEUR_COMBINAISON + 1], const char guess_combinaison[LONGUEUR_COMBINAISON + 1], Res* resultat) {
    int black_count = 0, white_count = 0;
    int secret_used[LONGUEUR_COMBINAISON] = {0}, guess_used[LONGUEUR_COMBINAISON] = {0};

    // Évaluation des pions noirs
    for (int i = 0; i < LONGUEUR_COMBINAISON; i++) {
        if (guess_combinaison[i] == secret_combinaison[i]) {
            black_count++;
            secret_used[i] = guess_used[i] = 1;
        }
    }

    // Évaluation des pions blancs
    for (int i = 0; i < LONGUEUR_COMBINAISON; i++) {
        if (!guess_used[i]) {
            for (int j = 0; j < LONGUEUR_COMBINAISON; j++) {
                if (!secret_used[j] && guess_combinaison[i] == secret_combinaison[j]) {
                    white_count++;
                    secret_used[j] = 1;
                    break;
                }
            }
        }
    }

    resultat->black = black_count;
    resultat->white = white_count;
}

void evaluer_supposition_difficile(const char secret_combinaison[LONGUEUR_COMBINAISON + 1], const char guess_combinaison[LONGUEUR_COMBINAISON + 1], Res* resultat) {
    int black_count = 0, white_count = 0;
    int secret_used[LONGUEUR_COMBINAISON] = {0}, guess_used[LONGUEUR_COMBINAISON] = {0};

    for (int i = 0; i < LONGUEUR_COMBINAISON; i++) {
        if (guess_combinaison[i] == secret_combinaison[i]) {
            black_count++;
            secret_used[i] = guess_used[i] = 1;
        }
    }

    for (int i = 0; i < LONGUEUR_COMBINAISON; i++) {
        if (!guess_used[i]) {
            for (int j = 0; j < LONGUEUR_COMBINAISON; j++) {
                if (!secret_used[j] && guess_combinaison[i] == secret_combinaison[j]) {
                    white_count++;
                    secret_used[j] = 1;
                    break; 
                }
            }
        }
    }

    resultat->black = black_count;
    resultat->white = white_count;
}


int verifier_victoire(const char sequence[LONGUEUR_COMBINAISON + 1], const char supposition[LONGUEUR_COMBINAISON + 1]) {
    return strcmp(sequence, supposition) == 0;
}


