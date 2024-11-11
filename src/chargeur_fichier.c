/**
 * @file        chargeur_fichier.c
 * @brief       Fonctions utilitaires pour le chargement de fichier, le chargement de séquences de couleurs à partir d'un fichier 
 * @author      Mohamed MAACHE <mohamed.maache@etu.unistra.fr>
 * @author      Fadel MENDE <fadel.mende@etu.unistra.fr>
 * @author      Serge MUKOKA <serge.mukoka@etu.unistra.fr>
 * @version     0.1
 * @date        2024
 */
#include <stdio.h>
#include <string.h>

#define MAX_COLORS 6
#define MAX_COLOR_LENGTH 4

/**
 * @brief Charge une séquence de couleurs à partir d'un fichier.
 * 
 * Cette fonction charge et valide une séquence de couleurs à partir d'un fichier.
 * 
 * @param filename Le nom du fichier contenant la séquence de couleurs.
 * @param sequence Le tableau dans lequel stocker la séquence de couleurs.
 * @param sequence_length Le pointeur vers la variable où stocker la longueur de la séquence.
 * @return 1 si la séquence est chargée avec succès, 0 sinon.
 */
const char* charger_sequence(const char *filename) {
    static char sequence[MAX_COLORS + 1];
    sequence[0] = '\0'; 

    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Erreur : Impossible d'ouvrir le fichier %s\n", filename);
        return sequence; 
    }

    int count = 0;
    char color;
    while (count < MAX_COLORS && fscanf(file, " %c", &color) == 1) { 
        sequence[count++] = color;
    }
    sequence[count] = '\0'; 

    fclose(file);


    if (count < MAX_COLOR_LENGTH) {
        printf("Erreur : Séquence de couleurs incomplète\n");
        sequence[0] = '\0'; 
    }

    return sequence;
}


