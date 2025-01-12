#include "vecteur.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <ctype.h>
#include <time.h>
#pragma warning(disable: 4996)

int initVecteur(Vecteur* v, int capacite) {
	assert(capacite > 0);
	v->capacite = capacite;
	v->nbElements = 0;
	v->elements = (char*)malloc(sizeof(char) * capacite);
	return v->elements != NULL;
}

int taille(const Vecteur* v) {
	return v->nbElements;
}

int ajouter(Vecteur* v, char it) {
	if (v->nbElements == v->capacite) {
		v->capacite++;
		char* tab = (char*)realloc(v->elements, sizeof(char) * v->capacite);
		if (tab == NULL)
			return 0;
		v->elements = tab;
	}
	v->elements[v->nbElements++] = it;
	return 1;
}

char obtenir(const Vecteur* v, int i) {
	assert(i >= 0 && i < v->nbElements);
	return v->elements[i];
}

void modifier(Vecteur* v, int i, char it) {
	assert(i >= 0 && i < v->nbElements);
	v->elements[i] = it;
}

void supprimer(Vecteur* v, int i) {
	assert(i >= 0 && i < v->nbElements);
	for (++i; i < v->nbElements; ++i)
		v->elements[i - 1] = v->elements[i];
	--v->nbElements;
}

int retailler(Vecteur* v, int taille) {
	assert(taille > 0);
	char* tab = (char*)realloc(v->elements, sizeof(char) * taille);
	if (tab == NULL)
		return 0;
	v->elements = tab;
	v->capacite = taille;
	if (v->nbElements > taille)
		v->nbElements = taille;
	return 1;
}

void detruireVecteur(Vecteur* v) {
	free(v->elements);
}

void afficherVecteur(Vecteur* v) {
	for (int i = 0; i < v->capacite; i++) {
		printf("%c", v->elements[i]);
	}
	printf("\n");
}