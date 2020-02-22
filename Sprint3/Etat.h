#ifndef _ETAT_
#define _ETAT_

/**
* @file Etat.h
* @brief Définition du type structuré Etat
* @author CHAN Jennifer & PINARD Lucas - Groupe 104
* @version 1 - 18/12/2018
*
* Projet SDA
*/

#include "Tableau2D.h"


enum Mouvement { FIXE, NORD, OUEST, SUD, EST };

struct Etat
{
	Tab2D resultant;				// Représentation 2D de cet état du Taquin
	Mouvement m;					// Mouvement ayant conduit à cet état
	unsigned int indexPrecedent,	// index de l'état précédent
		g, h,						// heuristique de l'état
		x, y;						// position de la case vide dans l'état
};

typedef Etat Item;

/**
* @brief Afficher un état du taquin
* @param[in] e : l'état à afficher
*/
void afficher(Etat& e);

/**
* @brief Trouver la position de la case vide
* @param[in/out] e : l'état dans lequel chercher la case vide
*/
void searchCaseVide(Etat& e);

/**
* @brief Vérifier si un déplacement est possible
* @param[in] e : l'état courant
* @param[in] m : le déplacement à vérifier
* @return le booléen résultant de la vérification
*/
bool estPossible(Etat& e, Mouvement m);

/**
* @brief Effectue le déplacement sur un état vers une direction
* @param[in/out] e : l'état
* @param[in] m : la direction du mouvement
*/
void deplacer(Etat& e, Mouvement m);

#endif // !_ETAT_