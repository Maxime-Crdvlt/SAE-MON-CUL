#pragma once
#include "vecteur.h"

/**
 * @brief Echanges le chevalet que le joueur � voulu avec un chevalet al�atoire de la pioche
 * @param[in] joueur Le vecteur joueur qui �change le chevalet
 * @param[in] chevalet Le caract�res qui repr�sente le chevalet �chang�
 */
int echangerChevalet(Vecteur* joueur, Vecteur* pioche);

/**
 * @brief Demande la commande que veut faire le joueur
 * @param[in] joueur Le vecteur joueur qui va entrer sa commande
 * @param[in] numero_joueur Le num�ro du joueur qui va entrer sa commande
 */
int entrerCoup(Vecteur* joueur, Vecteur* pioche, int numero_joueur);

/**
 * @brief Affiches la situation actuelle de la partie
 * @param[in] joueur1 Le vecteur joueur qui repr�sente la main du joueur 1
 * @param[in] joueur2 Le vecteur joueur qui repr�sente la main du joueur 2
 * @param[in] rail_recto Le vecteur rail qui repr�sente le rail de vue Recto
 * @param[in] rail_verso Le vecteur rail qui repr�sente le rail de vue Verso
 */
void afficherSituation(Vecteur* joueur1, Vecteur* joueur2, Vecteur* rail_recto, Vecteur* rail_verso);

/**
 * @brief Verifie si le mot entr� est dans le dictionnaire
 * @param[in] motJoueur La cha�ne de caract�res qu'il faut v�rifier
 * @return 0 si le mot n'a pas �t� trouv� ou 1 si le mot a �t� trouv�
 */
int verifierDico(char* motJoueur);

/**
 * @brief Verifie si tous les caract�res du mots sont dans les chevalets du joueur
 * @param[in] motJoueur La cha�ne de caract�re qu'il faut v�rifier
 * @param[in] joueur Le vecteur joueur qui doit �tre compar� 
 * @return 0 si il manque une lettre ou 1 si le joueur � toutes les lettres
 */
int verifierMain(char* motJoueur, Vecteur* joueur);

/**
 * @brief Verifie si la partie est gagn�e par un joueur
 * @param[in] joueur1 Le vecteur joueur du joueur 1
 * @param[in] joueur2 Le vecteur joueur du joueur 2
 * @return 0 si personne n'a gagn� ou 1 si un des deux joueurs � gagn�
 */
int verifierVictoire(Vecteur* joueur1, Vecteur* joueur2);
