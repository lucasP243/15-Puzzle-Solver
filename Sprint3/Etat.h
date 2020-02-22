#ifndef _ETAT_
#define _ETAT_

/**
* @file Etat.h
* @brief D�finition du type structur� Etat
* @author CHAN Jennifer & PINARD Lucas - Groupe 104
* @version 1 - 18/12/2018
*
* Projet SDA
*/

#include "Tableau2D.h"


enum Mouvement { FIXE, NORD, OUEST, SUD, EST };

struct Etat
{
	Tab2D resultant;				// Repr�sentation 2D de cet �tat du Taquin
	Mouvement m;					// Mouvement ayant conduit � cet �tat
	unsigned int indexPrecedent,	// index de l'�tat pr�c�dent
		g, h,						// heuristique de l'�tat
		x, y;						// position de la case vide dans l'�tat
};

typedef Etat Item;

/**
* @brief Afficher un �tat du taquin
* @param[in] e : l'�tat � afficher
*/
void afficher(Etat& e);

/**
* @brief Trouver la position de la case vide
* @param[in/out] e : l'�tat dans lequel chercher la case vide
*/
void searchCaseVide(Etat& e);

/**
* @brief V�rifier si un d�placement est possible
* @param[in] e : l'�tat courant
* @param[in] m : le d�placement � v�rifier
* @return le bool�en r�sultant de la v�rification
*/
bool estPossible(Etat& e, Mouvement m);

/**
* @brief Effectue le d�placement sur un �tat vers une direction
* @param[in/out] e : l'�tat
* @param[in] m : la direction du mouvement
*/
void deplacer(Etat& e, Mouvement m);

#endif // !_ETAT_