/**
 * @file        input.h
 * @brief       fichier d'en-tête du input.c
 * @author      Mohamed MAACHE <mohamed.maache@etu.unistra.fr>
 * @author      Fadel MENDE <fadel.mende@etu.unistra.fr>
 * @author      Serge MUKOKA <serge.mukoka@etu.unistra.fr>
 * @version     0.1
 * @date        2024
 */
#ifndef INPUT_H
#define INPUT_H

#define LONGUEUR_COMBINAISON 4

void lire_combinaison(char supposition[LONGUEUR_COMBINAISON]);

int est_valide(const char *supposition);

#endif


