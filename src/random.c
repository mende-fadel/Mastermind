/**
 * @file        random.c
 * @brief       
 * @author      Mohamed MAACHE <mohamed.maache@etu.unistra.fr>
 * @author      Fadel MENDE <fadel.mende@etu.unistra.fr>
 * @author      Serge MUKOKA <serge.mukoka@etu.unistra.fr>
 * @version     0.1
 * @date        2024
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NB_COULEURS 6
#define LONGUEUR_COMBINAISON 4

const char* couleur_aleatoire() {
    const static char* couleurs[NB_COULEURS] = {"R", "V", "B", "J", "M", "O"};
    return couleurs[rand() % NB_COULEURS];
}




char* combinaison_aleatoire() {
    char* sequence = malloc((LONGUEUR_COMBINAISON + 1) * sizeof(char)); // Correction ici pour la taille correcte
    if (sequence == NULL) {
        // Échec de l'allocation, retourne NULL
        return NULL;
    }

    const static char couleurs[] = "RVBJVO"; // Les couleurs disponibles
    for (int i = 0; i < LONGUEUR_COMBINAISON; i++) {
        sequence[i] = couleurs[rand() % (sizeof(couleurs) - 1)]; // Choix aléatoire d'une couleur
    }
    sequence[LONGUEUR_COMBINAISON] = '\0'; // Ne pas oublier le caractère de fin de chaîne

    return sequence; // Retourne le pointeur vers la nouvelle allocation
}
