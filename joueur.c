#include "joueur.h"
#include "partie.h"
#include "rail.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <ctype.h>
#include <time.h>

#pragma warning(disable: 4996)

int comparerChevalets(const void* a, const void* b) {
    return (*(const char*)a - *(const char*)b);  // Comparaison de caract�res
}

char* demanderPreMot(Vecteur* joueur, Vecteur* rail, int numero) {
    int valide = 0;
    char* motJoueur = (char*)malloc(sizeof(char) * TAILLE_PRE_MOT+1);
    do {
        printf("%d> ", numero);
        scanf("%s", motJoueur);
        size_t taille_mot = strlen(motJoueur);
        if (taille_mot < TAILLE_PRE_MOT || taille_mot > TAILLE_PRE_MOT) {
            continue;
        }
        else if (verifierDico(motJoueur) == 0) {
            continue;
        }
        else if (verifierMain(motJoueur, joueur) == 0) {
            continue;
        }
        else {
            valide = 1;
            for (int i = 0; i < taille_mot; i++) {
                for (int j = 0; j < joueur->nbElements; j++) {
                    if (joueur->elements[j] == motJoueur[i]) {
                        supprimer(joueur, j);
                        break; // Supprimes une seule fois la lettre
                    }
                }
            }
            retailler(joueur, taille(joueur));
            return motJoueur;
        }
    } while (valide == 0);
}