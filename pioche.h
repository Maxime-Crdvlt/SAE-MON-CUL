#pragma once
#include "vecteur.h"

enum { MAX_CHEVALETS_PIOCHE = 88 };

/**
 * @brief Remplis la pioche selon les règles du jeu
 * @param[in] pioche La pioche qu'il faut remplir
 * @return 0 en cas d'échec (manque de mémoire disponible) et 1 en cas de succès.
 */
void remplirPioche(Vecteur* pioche);

/**
 * @brief Mélange la pioche
 * @param[in] pioche  La pioche qu'il faut mélanger
 */
void melangerPioche(Vecteur* pioche);

/** 
* @brief  Distribue la pioche entre les deux joueurs
* @param[in] pioche La pioche qu'il faut distribuer  
* @param[in] joueur1 Le premier joueur a qui il faut distribuer
* @param[in] joueur2 Le deuxième joueur a qui il faut distribuer
*/
void distribuerPioche(Vecteur* pioche, Vecteur* joueur1, Vecteur* joueur2);