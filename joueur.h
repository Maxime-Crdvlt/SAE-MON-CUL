#pragma once
#include "vecteur.h"

enum { NB_INITIAL_CHEVALETS = 12, MAX_MOT = 6, TAILLE_PRE_MOT = 4 };

/**
 * @brief Compare les chevalets afin de les trier par ordre alphabétique avec qsort()
 * @param[in] a Pointeur vers le premier élément à comparer
 * @param[in] b Pointeur vers le deuxième élément à comparer
 * @return Un entier représentant le résultat de la comparaison :
 *	Si a < b la valeur sera négative
 *	Si a > b la valeur sera positive
 *	Si a = b la valeur sera zéro
 */
int comparerChevalets(const void* a, const void* b);

/** 
* @brief La fonction demande le mot au joueur  
* @param[in] joueur Le joueur a qui il faut demander le mot 
* @param[in] numero Le numéro du joueur (1 ou 2)  
* @param[in] tailleMin La taille minimale du mot attendue
* @param[in] tailleMax La taille maximale du mot attendue
*/
char* demanderPreMot(Vecteur* joueur, Vecteur* rail, int numero);