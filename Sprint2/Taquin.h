#ifndef _TAQUIN_
#define _TAQUIN_

/**
* @file Taquin.h
* @brief D�finition du type structur� Taquin
* @author CHAN Jennifer & PINARD Lucas - Groupe 104
* @version 1 - 18/12/2018
*
* Projet SDA
*/

#include "Liste.h"

struct Taquin
{
	Liste LEE;	// Liste des �tats explor�s
	Liste LEAE; // Liste des �tats � explorer

	unsigned int nbL, nbC; // nombre de lignes et de colonnes du taquin
};

/**
* @brief Cr�er le jeu de taquin avec l��tat initial
* @param[in] t : le taquin a initialiser
*/
void initialiser(Taquin& t);

/**
* @brief Cr�er les �tats r�sultants du d�placement de l'�tat courant dans chaque direction et les placer dans LEAE
* @param[in] t : le taquin � d�velopper
* @pre le d�placement est possible
*/
void deplacer(Taquin& t);

/**
* @brief It�ration de l'algorithme de recherche
* @param[in] t : le taquin avec lequel it�rer
*/
bool jouer(Taquin& t);

/**
* @brief Afficher le contenu des liste adev et dev
* @param[in] t : le taquin a afficher
*/
void afficher(Taquin& t);

/**
* @brief D�salloue un taquin
* @param[in] t : le taquin a d�sallouer
*/
void detruire(Taquin& t);

#endif // !_TAQUIN_