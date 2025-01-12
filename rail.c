#include "rail.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <ctype.h>
#include <time.h>

void remplirRail(Vecteur* rail, char* mot ) {
	size_t taille = strlen(mot);
	for (int i = 0; i < taille; i++) {
		ajouter(rail, mot[i]);
	}
}

void inverserRail(Vecteur* rail_recto, Vecteur* rail_verso) {
	for (int i = 0; i < rail_recto->nbElements / 2; i++) {
		char temp = rail_recto->elements[i];
		rail_verso->elements[i] = rail_recto->elements[rail_recto->nbElements - i - 1];
		rail_verso->elements[rail_recto->nbElements - i - 1] = temp;
	}
}