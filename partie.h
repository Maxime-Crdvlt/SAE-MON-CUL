#pragma once
#include "vecteur.h"

/**
 * @brief Echanges le chevalet que le joueur à voulu avec un chevalet aléatoire de la pioche
 * @param[in] joueur Le vecteur joueur qui échange le chevalet
 * @param[in] chevalet Le caractères qui représente le chevalet échangé
 */
int echangerChevalet(Vecteur* joueur, Vecteur* pioche);

/**
 * @brief Demande la commande que veut faire le joueur
 * @param[in] joueur Le vecteur joueur qui va entrer sa commande
 * @param[in] numero_joueur Le numéro du joueur qui va entrer sa commande
 */
int entrerCoup(Vecteur* joueur, Vecteur* pioche, int numero_joueur);

/**
 * @brief Affiches la situation actuelle de la partie
 * @param[in] joueur1 Le vecteur joueur qui représente la main du joueur 1
 * @param[in] joueur2 Le vecteur joueur qui représente la main du joueur 2
 * @param[in] rail_recto Le vecteur rail qui représente le rail de vue Recto
 * @param[in] rail_verso Le vecteur rail qui représente le rail de vue Verso
 */
void afficherSituation(Vecteur* joueur1, Vecteur* joueur2, Vecteur* rail_recto, Vecteur* rail_verso);

/**
 * @brief Verifie si le mot entré est dans le dictionnaire
 * @param[in] motJoueur La chaîne de caractères qu'il faut vérifier
 * @return 0 si le mot n'a pas été trouvé ou 1 si le mot a été trouvé
 */
int verifierDico(char* motJoueur);

/**
 * @brief Verifie si tous les caractères du mots sont dans les chevalets du joueur
 * @param[in] motJoueur La chaîne de caractère qu'il faut vérifier
 * @param[in] joueur Le vecteur joueur qui doit être comparé 
 * @return 0 si il manque une lettre ou 1 si le joueur à toutes les lettres
 */
int verifierMain(char* motJoueur, Vecteur* joueur);

/**
 * @brief Verifie si la partie est gagnée par un joueur
 * @param[in] joueur1 Le vecteur joueur du joueur 1
 * @param[in] joueur2 Le vecteur joueur du joueur 2
 * @return 0 si personne n'a gagné ou 1 si un des deux joueurs à gagné
 */
int verifierVictoire(Vecteur* joueur1, Vecteur* joueur2);
