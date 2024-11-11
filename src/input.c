/**
 * @file input.c
 * @brief Implémentation d'un système de saisie et de validation de combinaisons de couleurs.
 * @author      Mohamed MAACHE <mohamed.maache@etu.unistra.fr>
 * @author      Fadel MENDE <fadel.mende@etu.unistra.fr>
 * @author      Serge MUKOKA <serge.mukoka@etu.unistra.fr>
 * @version     0.1
 * @date        2024
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define LONGUEUR_COMBINAISON 4


int est_valide(const char *supposition) {
    // Vérification de la longueur
    if (strlen(supposition) != LONGUEUR_COMBINAISON) {
        printf("La combinaison doit être de %d caractères.\n", LONGUEUR_COMBINAISON);
        return 0;
    }
    
    // Vérification de la validité des caractères
    for (int i = 0; i < LONGUEUR_COMBINAISON; i++) {
        char c = toupper(supposition[i]);
        if (c != 'R' && c != 'V' && c != 'B' && c != 'J' && c != 'M' && c != 'O') {
            printf("Caractère invalide détecté : %c\n", supposition[i]);
            return 0; 
        }
    }
    return 1; 
}



void lire_combinaison(char supposition[LONGUEUR_COMBINAISON + 1]) {
    do {
        printf("   Entre une combinaison: ");
        scanf("%s", supposition);
    } while (!est_valide(supposition));
}


