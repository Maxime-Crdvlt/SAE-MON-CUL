#pragma once
#include "vecteur.h"

enum { MAX_CHEVALETS_PIOCHE = 88 };

/**
 * @brief Remplis la pioche selon les r�gles du jeu
 * @param[in] pioche La pioche qu'il faut remplir
 * @return 0 en cas d'�chec (manque de m�moire disponible) et 1 en cas de succ�s.
 */
void remplirPioche(Vecteur* pioche);

/**
 * @brief M�lange la pioche
 * @param[in] pioche  La pioche qu'il faut m�langer
 * @return 0 en cas d'�chec et 1 en cas de succ�s.
 */
void melangerPioche(Vecteur* pioche);

/** 
* @brief  Distribue la pioche entre les deux joueurs
* @param[in] pioche La pioche qu'il faut distribuer  
* @param[in] joueur1 Le premier joueur a qui il faut distribuer
* @param[in] joueur2 Le deuxi�me joueur a qui il faut distribuer
* @return 0 en cas d'�chec et 1 en cas de succ�s.
*/
void distribuerPioche(Vecteur* pioche, Vecteur* joueur1, Vecteur* joueur2);