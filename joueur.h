#pragma once
#include "vecteur.h"

enum { NB_INITIAL_CHEVALETS = 12, MAX_MOT = 6, TAILLE_PRE_MOT = 4 };

/**
 * @brief Compare les chevalets afin de les trier par ordre alphab�tique avec qsort()
 * @param[in] a Pointeur vers le premier �l�ment � comparer
 * @param[in] b Pointeur vers le deuxi�me �l�ment � comparer
 * @return Un entier repr�sentant le r�sultat de la comparaison :
 *	Si a < b la valeur sera n�gative
 *	Si a > b la valeur sera positive
 *	Si a = b la valeur sera z�ro
 */
int comparerChevalets(const void* a, const void* b);

/** 
* @brief La fonction demande le mot au joueur  
* @param[in] joueur Le joueur a qui il faut demander le mot 
* @param[in] numero Le num�ro du joueur (1 ou 2)  
* @param[in] tailleMin La taille minimale du mot attendue
* @param[in] tailleMax La taille maximale du mot attendue
*/
char* demanderPreMot(Vecteur* joueur, Vecteur* rail, int numero);