#pragma once
#include "vecteur.h"

enum
{
	MAX_CHEVALETS_RAIL = 8
};

/**
 * @brief Remplis le rail avec le mot
 * @param[in] rail Le rail a remplir
 * @param mot[in] Le mot � ins�rer dans le rail
 */
void remplirRail(Vecteur* rail, char* mot);

/** 
* @brief Inverse un rail dans un rail diff�rent
* @param[in] railRecto Le rail � inverser 
* @param[in] railVerso Le rail dans lequel se fera l'inversion
*/
void inverserRail(Vecteur* rail_recto, Vecteur* rail_verso);