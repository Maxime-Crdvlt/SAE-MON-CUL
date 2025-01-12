#include "dictionnaire.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <ctype.h>
#include <time.h>
#pragma warning(disable: 4996)

enum { MAX_LETTRES_MOTS = 256 };

int mauvaisesLettres(const char* word) {
    const char* lettres_interdites = "KXYZW";
    while (*word) {
        if (strchr(lettres_interdites, toupper(*word))) {
            return 1;  // Le mot contient une des lettres interdites
        }
        word++;
    }
    return 0;
}

void optimiserDico() {
    FILE* dico_base = fopen("ods4.txt", "r");
    FILE* nouveau_dico = fopen("newDico.txt", "w+");
    if (!dico_base || !nouveau_dico) {
        fprintf(stdin, "Erreur lors de l'ouverture des fichiers.\n");
        return;
    }
    char mot[30] = { 0 };
    int n;
    n = fscanf(dico_base, "%29s", mot);
    while (n == 1) {
        if (strlen(mot) <= 8 && !mauvaisesLettres(mot)) {
            fprintf(nouveau_dico, "%s\n", mot);  // Conserver le mot
        }
        n = fscanf(dico_base, "%29s", mot);
    }
    if (ferror(dico_base))
        printf("erreur - %s\n", strerror(errno));
    fclose(dico_base);
    fclose(nouveau_dico);
}
