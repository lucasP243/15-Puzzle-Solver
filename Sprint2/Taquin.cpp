/**
* @file Taquin.cpp
* @brief Codage des fonctions relatives au type Taquin
* @author CHAN Jennifer & PINARD Lucas - Groupe 104
* @version 1 - 26/12/2018
*
* Projet SDA
*/

#include "Taquin.h"
#include "Etat.h"
#include <cassert>
#include <iostream>
using namespace std;

void initialiser(Taquin &t)
{
	Tab2D m;
	cin >> t.nbL >> t.nbC;
	initialiser(m, t.nbL, t.nbC);
	lire(m);

	initialiser(t.LEE);
	initialiser(t.LEAE);

	Etat e;
	e.resultant = m;
	searchCaseVide(e);
	e.m = FIXE;
	e.indexPrecedent = NULL;
	inserer(t.LEAE, longueur(t.LEAE), e);

	cout << "Damier : " << t.nbL << " lignes, " << t.nbC << "colonnes" << endl
		<< "Iteration 0" << endl;

	afficher(t);

	cout << "Fin iteration 0" << endl << endl << endl;
}

void deplacer(Taquin& t)
{
	unsigned int index = longueur(t.LEE);
	inserer(t.LEE, index, lire(t.LEAE, longueur(t.LEAE) - 1));
	supprimer(t.LEAE, longueur(t.LEAE) - 1);
	for (int m = EST; m <= NORD; m++)
		if (estPossible(lire(t.LEE, index), (Mouvement)m))
		{
			Etat f;
			f.resultant = lire(t.LEE, index).resultant;
			f.indexPrecedent = index;
			deplacer(f, (Mouvement)m);

			inserer(t.LEAE, longueur(t.LEAE), f);
			afficher(f);
		}
}

bool jouer(Taquin& t)
{
	cout << "Iteration 1" << endl;

	unsigned int index = longueur(t.LEE);
	inserer(t.LEE, index, lire(t.LEAE, longueur(t.LEAE) - 1));
	supprimer(t.LEAE, longueur(t.LEAE) - 1);
	for (int m = EST; m <= NORD; m++)
		if (estPossible(lire(t.LEE, longueur(t.LEE) - 1), (Mouvement)m))
		{
			Etat f;
			clone(f.resultant, lire(t.LEE, longueur(t.LEE) - 1).resultant);
			f.indexPrecedent = index;
			deplacer(f, (Mouvement)m);

			inserer(t.LEAE, longueur(t.LEAE), f);
		}

	afficher(t);
	cout << "Fin iteration 1" << endl;
	return false;
}

void afficher(Taquin & t)
{
	cout << "*** LEE - long : " << longueur(t.LEE) << endl;
	for (unsigned int i = 0; i < longueur(t.LEE); i++)
		afficher(lire(t.LEE, i));

	cout << endl;

	cout << "*** LEAE - long : " << longueur(t.LEAE) << endl;
	for (unsigned int i = 0; i < longueur(t.LEAE); i++)
		afficher(lire(t.LEAE, i));
}

void detruire(Taquin & t)
{
	detruire(t.LEAE);
	detruire(t.LEE);
}