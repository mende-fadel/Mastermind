#include <stdio.h>
#include "couleurs.h"
#include "jeu.h"
#include <stdlib.h>
#include <time.h>
#include "affichage.h"
#include <unistd.h>

#define ANSI_COULEUR_ROUGE "\x1b[31m"
#define ANSI_COULEUR_VERT "\x1b[32m"
#define ANSI_COULEUR_BLEU "\x1b[34m"
#define ANSI_COULEUR_JAUNE "\x1b[33m"
#define ANSI_COULEUR_RESET "\x1b[0m"
#define ESSAIE 10

int main() {
    srand(time(NULL));

    char sequence[MAX_COLOR_LENGTH + 1]; // Ajout d'un espace pour le caractère nul
    int mode_initialisation;
    int mode_couleur;
    int mode_difficile;
    double essai_nb = 1;

    // Affichage des règles du jeu
    //afficher_regles();
    animateStartScreen();
    // demande le mode
    mode_couleur = choisir_mode_couleur();
    mode_difficile = choisir_mode_difficile();

    printf("Choisissez le mode d'initialisation (1 pour chargement depuis un fichier, 0 pour une génération aléatoire) : ");
    scanf("%d", &mode_initialisation);

    if (!jeu_initialisation(mode_initialisation, sequence)) {
        return 1;
    }

    affichage_debut(mode_couleur);
        //printf(" sequence secrete : %s\n", sequence);
    while (essai_nb- MAX_TRIES<= 0) {
        char supposition[MAX_COLOR_LENGTH];
        Res resultat;

        // Lecture de la supposition du joueur
        lire_combinaison(supposition);

        // De même pour evaluer_supposition ou evaluer_supposition_difficile
        if (mode_difficile) {
            evaluer_supposition_difficile(sequence, supposition, &resultat);
        }else{
            evaluer_supposition(sequence, supposition, &resultat);
        }

        // Affichage des résultats
        //printf("l'essai_nb %d : ", essai_nb);

        // Vérification de la victoire
        if (verifier_victoire(sequence, supposition)) {
            clearScreen();
            displayWinScreen();
            printf("\nFélicitations ! Vous avez trouvé la séquence secrète!!!\n");
            return 0; // Quitte le jeu après la victoire
        }
        affichage_guess(essai_nb, supposition, resultat, mode_couleur);

        // Incrémentation du nombre d'essais
        essai_nb++;
    }

    printf("\n");
    displayLoseScreen();
    printf("La séquence secrète était : %s\n", sequence);
    return 0;
}
