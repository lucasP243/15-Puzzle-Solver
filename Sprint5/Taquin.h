#ifndef _TAQUIN_
#define _TAQUIN_

/**
* @file Taquin.h
* @brief Définition du type structuré Taquin
* @author CHAN Jennifer & PINARD Lucas - Groupe 104
* @version 1 - 18/12/2018
*
* Projet SDA
*/

#include "Liste.h"

struct Taquin
{
	Liste LEE;	// Liste des états explorés
	Liste LEAE; // Liste des états à explorer
	Solutions s; // Solutions du taquin

	unsigned int nbL, nbC; // nombre de lignes et de colonnes du taquin
};

/**
* @brief Créer le jeu de taquin avec l’état initial
* @param[in] t : le taquin a initialiser
*/
void initialiser(Taquin& t);

/**
* @brief Créer les états résultants du déplacement de l'état courant dans chaque direction et les placer dans LEAE
* @param[in] t : le taquin à développer
* @pre le déplacement est possible
*/
void deplacer(Taquin& t);

/**
* @brief Itération de l'algorithme de recherche
* @param[in] t : le taquin avec lequel itérer
* @return true si une solution est trouvée
*/
bool jouer(Taquin& t);

/**
* @brief Afficher le contenu des liste adev et dev
* @param[in] t : le taquin a afficher
*/
void afficher(Taquin& t);

/**
* @brief Vérifier si état appartient à une liste
* @param[in] l : la liste
* @param[in] e : l'état à vérifier
* @return le booléen résultant de la vérification
*/
bool appartient(Etat& e, Taquin& t);

/**
* @brief Vérifie si l'état correspond à l'un des états but
* @param[in] e : l'état
* @return le booléen résultant de cette vérification
*/
bool but(Taquin&t, const Etat& e);

/**
* @brief Désalloue un taquin
* @param[in] t : le taquin a désallouer
*/
void detruire(Taquin& t);

/**
* @brief Retrace et affiche la solution d'un taquin
* @param[in] t : le taquin
*/
void afficherSolution(Taquin& t);

#endif // !_TAQUIN_