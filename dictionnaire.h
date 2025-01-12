#pragma once

/**
 * @brief V�rifie si le mot contient les lettres interdites du jeu afin d'optimiser le dictionnaire
 * @param[in] word Le mot a v�rifier 
 * @return 1 si le mot contient une des lettres interdites et 0 si le mot ne contient pas de lettres interdites
 */
int mauvaisesLettres(const char* word);

/** 
* @brief Optimise le dictionnaire en cr�ant un nouveau focntionnaire sans les mots impossibles � proposer
*/
void optimiserDico();