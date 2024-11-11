/**
 * @file        affichage.c
 * @brief       les fonctions utilitaires de l'affichage sur terminal 
 * @author      Mohamed MAACHE <mohamed.maache@etu.unistra.fr>
 * @author      Fadel MENDE <fadel.mende@etu.unistra.fr>
 * @author      Serge MUKOKA <serge.mukoka@etu.unistra.fr>
 * @version     0.1
 * @date        2024
 */
#include <stdio.h>
#include "affichage.h"
#include "couleurs.h"
#include <unistd.h> 
#include <string.h> 
#include <stdlib.h> 

void clearScreen() {
    system("clear || cls");
}

void printAnimatedText(const char *text, unsigned int delayMicroseconds) {
    for (; *text; text++) {
        printf("%c", *text);
        fflush(stdout); 
        usleep(delayMicroseconds);
    }
}

void displayLoseScreen() {
    clearScreen();
    const char *losetext =

"_____.___.              .____                        \n"
"\\__  |   | ____  __ __  |    |    ____  ______ ____  \n"
" /   |   |/  _ \\|  |  \\ |    |   /  _ \\/  ___// __ \\ \n"
" \\____   (  <_> )  |  / |    |__(  <_> )___ \\\\  ___/ \n"
" / ______|\\____/|____/  |_______ \\____/____  >\\___  >\n"
" \\/                             \\/         \\/     \\/ \n";                                                                                         


    printAnimatedText(losetext, 10000); 
}


void displayWinScreen() {
    clearScreen();
    const char *winText =
    " __     __          __          ___       _ \n"
    " \\ \\   / /          \\ \\        / (_)     | |\n"
    "  \\ \\_/ /__  _   _   \\ \\  /\\  / / _ _ __ | |\n"
    "   \\   / _ \\| | | |   \\ \\/  \\/ / | | '_ \\| |\n"
    "    | | (_) | |_| |    \\  /\\  /  | | | | |_|\n"
    "    |_|\\___/ \\__,_|     \\/  \\/   |_|_| |_(_)\n"
    "                                           \n"
    "                                           \n";

    printAnimatedText(winText, 10000); // Adjust delay as needed
}


void animateStartScreen() {
    clearScreen();

    printAnimatedText("=========================================================\n",2000);
    printAnimatedText("             Bienvenue dans le jeu Mastermind !\n", 2000);
    printAnimatedText("=========================================================\n\n", 2000);

    usleep(1000000); 
    
    printAnimatedText("  Règles :\n", 8000);
    printAnimatedText("  - Vous devez deviner une combinaison secrète de 4 couleurs en 10 essais ou moins.\n", 2000);
    printAnimatedText("  - Couleurs disponibles : Rouge (R), Orange (O), Jaune (J), Vert (V), Bleu (B), Marron (M).\n", 2000);
    printAnimatedText("  - Après chaque essai, vous recevrez des indices sous forme d'épingles noires et blanches :\n", 2000);
    printAnimatedText("    - Épingle noire : Couleur correcte et bien placée.\n", 2000);
    printAnimatedText("    - Épingle blanche : Couleur correcte mais mal placée.\n", 2000);
    printAnimatedText("  - Vous gagnez si vous devinez la combinaison correctement en moins de 10 essais.\n", 2000);
    printAnimatedText("  - Modes : Facile (pas de couleurs répétées) et Difficile (couleurs répétées autorisées).\n\n", 2000);

    usleep(500000); 

    printAnimatedText("=========================================================\n", 2000);
    printAnimatedText("                     C'est parti !\n", 10000);
    printAnimatedText("=========================================================\n", 2000);
}


/**
 * @brief Affiche le début du tableau de résultats.
 * 
 * Cette fonction affiche le début du tableau de résultats, comprenant les en-têtes
 * des colonnes.
 */
void affichage_debut(int useColor) {
    if (useColor) {
        print("+", 'J');
        print("---------", 'R');
        print("+", 'J');
        print("-------", 'B');
        print("+", 'J');
        print("-------------------", 'V');
        print("+\n", 'J');
        
        print("|", 'J');
        print(" guess # ", 'R');
        print("|", 'J');
        print(" guess ", 'B');
        print("|", 'J');
        print(" result", 'V');
        print("            |", 'J');
        print("\n", 'J');
        
        print("+", 'J');
        print("---------", 'R');
        print("+", 'J');
        print("-------", 'B');
        print("+", 'J');
        print("-------------------", 'V');
        print("+", 'J');
    } else {
        printf("+---------+-------+-------------------+\n");
        printf("| guess # | guess | result            |\n");
        printf("+---------+-------+-------------------+");
    }
}



/**
 * @brief Affiche une ligne du tableau de résultats.
 * 
 * @param guess_nombre Le numéro de l'essai.
 * @param guess La chaîne de caractères représentant le guess.
 * @param resultat La structure contenant les résultats black et white.
 */
 void affichage_guess(const int guess_nombre, const char guess[MAX_COLOR_LENGTH + 1], const Res resultat, int mode_couleur) 
{
    if (mode_couleur) {
        print("|", 'J');
        if (guess_nombre >= 10) {
            print("  %d     ", 'R', guess_nombre);
        } else {
            print("  %d      ", 'R', guess_nombre);
        }
        print("|", 'J');
        print(" %s  ", 'B', guess);
        print("|", 'J');
        print("black: ", 'V');
        print("%d", 'B', resultat.black);
        print(" | ", 'V');
        print("white: ", 'J');
        print("%d", 'B', resultat.white);
        print("|", 'V');
    } else {
        printf("|  %d      |%s   |black: %d | white: %d|", guess_nombre, guess, resultat.black, resultat.white);
    }

}
