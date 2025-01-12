#include "vecteur.h"
#include "dictionnaire.h"
#include "pioche.h"
#include "rail.h"
#include "joueur.h"
#include "partie.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <ctype.h>
#include <time.h>
#pragma warning(disable: 4996)

int main() {
	// Initialisation de la partie - Création des variables et du jeu
	optimiserDico();
		// Initialisation de la pioche
	Vecteur pioche;
	initVecteur(&pioche, MAX_CHEVALETS_PIOCHE);
	remplirPioche(&pioche);
	melangerPioche(&pioche);
		// Création des joueurs et leur main
	Vecteur joueur1;
	Vecteur joueur2;
	initVecteur(&joueur1, NB_INITIAL_CHEVALETS);
	initVecteur(&joueur2, NB_INITIAL_CHEVALETS);
		// Distribution de la pioche
	distribuerPioche(&pioche, &joueur1, &joueur2);
		// Triage de la main des joueurs par ordre alphabétique
	qsort(joueur1.elements, joueur1.nbElements, sizeof(char), comparerChevalets);
	qsort(joueur2.elements, joueur2.nbElements, sizeof(char), comparerChevalets);
		// Affichage de la main des joueurs
	printf("1> ");
	afficherVecteur(&joueur1);
	printf("2> ");
	afficherVecteur(&joueur2);
	printf("\n");
		// Création du rail
	Vecteur rail_recto;
	Vecteur rail_verso;
	initVecteur(&rail_recto, MAX_CHEVALETS_RAIL);
	initVecteur(&rail_verso, MAX_CHEVALETS_RAIL);

	// Début du jeux - Initialisation du rail
	int tour = 1;
	char* pre_mot_joueur1 = (char*)malloc(TAILLE_PRE_MOT);
	char* pre_mot_joueur2 = (char*)malloc(TAILLE_PRE_MOT);
	strcpy(pre_mot_joueur1, demanderPreMot(&joueur1, &rail_recto, 1));
	strcpy(pre_mot_joueur2, demanderPreMot(&joueur2, &rail_recto, 2));
	if (strcmp(pre_mot_joueur1, pre_mot_joueur2) < 0) {
		remplirRail(&rail_recto, pre_mot_joueur1);
		remplirRail(&rail_recto, pre_mot_joueur2);
		tour = 1; // La partie commencera par le joueur 1
	}
	else if (strcmp(pre_mot_joueur1, pre_mot_joueur2) > 0) {
		remplirRail(&rail_recto, pre_mot_joueur2);
		remplirRail(&rail_recto, pre_mot_joueur1);
		tour = 2; // Le partie commencera par le joueur 2
	}
	else {
		remplirRail(&rail_recto, pre_mot_joueur1);
		remplirRail(&rail_recto, pre_mot_joueur2);
		tour = 1; // La partie commencera par le joueur 1 par défaut
	}
	inverserRail(&rail_recto, &rail_verso);
	afficherSituation(&joueur1, &joueur2, &rail_recto, &rail_verso);

	// Continuité du jeux
	int coup = 0;
	do {
		if (tour == 1) {
			do {
				printf("%d> ", tour);
				char commande;
				scanf(" %c", &commande);
				if (commande == 'R' || commande == 'V') {
					//proposerMot(joueur);
				}
				else if (commande == '-') {
					if (echangerChevalet(&joueur1, &pioche) == 1)
						coup = 1;
					else
						break;
				}
				else if (commande == 'r' || commande == 'v') {
					//signalerMot();
				}
			} while (coup != 1);
			qsort(joueur1.elements, joueur1.nbElements, sizeof(char), comparerChevalets);
			qsort(joueur2.elements, joueur2.nbElements, sizeof(char), comparerChevalets);
			afficherSituation(&joueur1, &joueur2, &rail_recto, &rail_verso);
			tour = 2;
		}
		else {
			do {
				printf("%d> ", tour);
				char commande;
				scanf(" %c", &commande);
				if (commande == 'R' || commande == 'V') {
					//proposerMot(joueur);
				}
				else if (commande == '-') {
					if (echangerChevalet(&joueur2, &pioche) == 1)
						coup = 1;
					else
						break;
				}
				else if (commande == 'r' || commande == 'v') {
					//signalerMot();
				}
			} while (coup != 1);
			qsort(joueur1.elements, joueur1.nbElements, sizeof(char), comparerChevalets);
			qsort(joueur2.elements, joueur2.nbElements, sizeof(char), comparerChevalets);
			afficherSituation(&joueur1, &joueur2, &rail_recto, &rail_verso);
			tour = 1;
		}
	} while (verifierVictoire(&joueur1, &joueur2) == 0);
}