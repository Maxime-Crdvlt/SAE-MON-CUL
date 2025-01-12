#include "pioche.h"
#include "joueur.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <ctype.h>
#include <time.h>

#pragma warning(disable: 4996) 

void remplirPioche(Vecteur* pioche) {
    // Fréquence des lettres selon les règles du jeu
    char lettres[] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V' };
    int quantites[] = { 9, 1, 2, 3, 14, 1, 1, 1, 7, 1, 5, 3, 6, 5, 2, 1, 6, 7, 6, 5, 2 };
    int index = 0;
    for (int i = 0; i < sizeof(quantites) / sizeof(int); i++) {
        for (int j = 0; j < quantites[i]; j++) {
            ajouter(pioche, lettres[i]);
            index++;
        }
    }
}

void melangerPioche(Vecteur* pioche) {
    srand(time(NULL));
    for (int i = 0; i < pioche->capacite; i++) {
        int j = rand() % pioche->capacite;
        char temp = pioche->elements[i];
        pioche->elements[i] = pioche->elements[j];
        pioche->elements[j] = temp;
    }
}

void distribuerPioche(Vecteur* pioche, Vecteur* joueur1, Vecteur* joueur2) {
    for (int i = 0, j = MAX_CHEVALETS_PIOCHE - 1; i < NB_INITIAL_CHEVALETS && j > MAX_CHEVALETS_PIOCHE - (2 * NB_INITIAL_CHEVALETS); i++, j = j - 2) {
        joueur1->elements[i] = pioche->elements[j];
        joueur1->nbElements++;

        joueur2->elements[i] = pioche->elements[j - 1];
        joueur2->nbElements++;

        // Réallocation à chaque boucle
        retailler(pioche, j - 1);
    }
}