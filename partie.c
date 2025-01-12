#include "partie.h"
#include "joueur.h"
#include "rail.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <ctype.h>
#include <time.h>
#pragma warning(disable: 4996)

int echangerChevalet(Vecteur* joueur, Vecteur* pioche) {
    char lettre;
    scanf("%c", &lettre);
    srand(time(NULL));
    if (verifierMain(&lettre, joueur) == 1) {
        int indice = 0;
        for (int i = 0; i < joueur->nbElements; i++) {
            if (strcmp(joueur->elements[i], &lettre) == 0) {
                indice = i;
                break;
            }
        }
        supprimer(joueur, indice);
        retailler(joueur, taille(joueur));
        ajouter(joueur, pioche->elements[rand() % (pioche->nbElements)]);
        ajouter(pioche, lettre);
        retailler(joueur, taille(joueur));
        retailler(pioche, taille(pioche));
        return 1;
    }
    else {
        return 0;
    }
}

void afficherSituation(Vecteur* joueur1, Vecteur* joueur2, Vecteur* rail_recto, Vecteur* rail_verso) {
    printf("1 : ");
    afficherVecteur(joueur1);
    printf("2 : ");
    afficherVecteur(joueur2);
    printf("R : ");
    afficherVecteur(rail_recto);
    printf("V : ");
    afficherVecteur(rail_verso);
    printf("\n");
}

int verifierDico(char* motJoueur) {
    FILE* fichier = fopen("newDico.txt", "r");
    if (fichier == NULL) {
        printf("Erreur d'ouverture du fichier NewDico.txt\n");
        return 0;  // Erreur, fichier non trouvé
    }
    char motDico[9] = { 0 };
    int n;
    n = fscanf(fichier, "%8s", motDico);
    while (n == 1) {
        if (strcmp(motDico, motJoueur) == 0) {
            return 1; // Mot trouvé
        }
        n = fscanf(fichier, "%8s", motDico);
    }
    fclose(fichier);
    return 0;  // Mot non trouvé
}

int verifierMain(char* motJoueur, Vecteur* joueur) {
    size_t taille = strlen(motJoueur);
    int* lettres_etat = (int*)malloc(sizeof(int) * taille);
    if (!lettres_etat) {
        return 0;  // Échec de l'allocation
    }
    for (size_t i = 0; i < taille; ++i) {
        lettres_etat[i] = 0;  // Initialisation
    }
    for (size_t i = 0; i < taille; i++) {
        for (int j = 0; j < joueur->nbElements; j++) {
            if (joueur->elements[j] == motJoueur[i] && !lettres_etat[i]) {
                lettres_etat[i] = 1;  // La lettre est marquée trouvée
                break;  // Sortir de la boucle interne
            }
        }
    }
    for (size_t i = 0; i < taille; i++) {
        if (lettres_etat[i] != 1) {
            free(lettres_etat);  // Libération de la mémoire
            return 0;  // Il manque une lettre
        }
    }
    free(lettres_etat);  // Libération de la mémoire avant de retourner
    return 1;  // Toutes les lettres sont disponibles
}

int verifierVictoire(Vecteur* joueur1, Vecteur* joueur2) {
    if (joueur1->nbElements == 0) {
        printf("Victoire du joueur 1 !");
        return 1;
    }
    else if (joueur2->nbElements == 0) {
        printf("Victoire du joueur 2 !");
        return 1;
    }
    else {
        return 0;
    }
}