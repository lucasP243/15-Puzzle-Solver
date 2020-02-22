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
	Solutions s; // Solutions du taquin

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
* @return true si une solution est trouv�e
*/
bool jouer(Taquin& t);

/**
* @brief Afficher le contenu des liste adev et dev
* @param[in] t : le taquin a afficher
*/
void afficher(Taquin& t);

/**
* @brief V�rifier si �tat appartient � une liste
* @param[in] l : la liste
* @param[in] e : l'�tat � v�rifier
* @return le bool�en r�sultant de la v�rification
*/
bool appartient(Etat& e, Taquin& t);

/**
* @brief V�rifie si l'�tat correspond � l'un des �tats but
* @param[in] e : l'�tat
* @return le bool�en r�sultant de cette v�rification
*/
bool but(Taquin&t, const Etat& e);

/**
* @brief D�salloue un taquin
* @param[in] t : le taquin a d�sallouer
*/
void detruire(Taquin& t);

/**
* @brief Retrace et affiche la solution d'un taquin
* @param[in] t : le taquin
*/
void afficherSolution(Taquin& t);

#endif // !_TAQUIN_