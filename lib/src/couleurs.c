#include <stdio.h>
#include <stdarg.h>

#define ANSI_COULEUR_ROUGE "\x1b[31m"
#define ANSI_COULEUR_VERT "\x1b[32m"
#define ANSI_COULEUR_BLEU "\x1b[34m"
#define ANSI_COULEUR_JAUNE "\x1b[33m"
#define ANSI_COULEUR_RESET "\x1b[0m"

/**
 * @brief Imprime un texte donné en couleur spécifiée.
 *
 * @param format Le format du texte à imprimer.
 * @param couleur La lettre représentant la couleur ('R' pour rouge, 'V' pour vert, etc...)
 * Si la lettre fournie ne correspond à aucune couleur
 * reconnue, le texte sera imprimé sans couleur.
 */
void print(const char *format, int couleur, ...) {
    va_list args;
    va_start(args, couleur);

    switch (couleur) {
        case 'R': 
            printf("%s", ANSI_COULEUR_ROUGE);
            break;
        case 'V': 
            printf("%s", ANSI_COULEUR_VERT);
            break;
        case 'B': 
            printf("%s", ANSI_COULEUR_BLEU);
            break;
        case 'J': 
            printf("%s", ANSI_COULEUR_JAUNE);
            break;
        default:
            break;
    }

    vprintf(format, args); 

    printf("%s", ANSI_COULEUR_RESET);
    va_end(args);
}
