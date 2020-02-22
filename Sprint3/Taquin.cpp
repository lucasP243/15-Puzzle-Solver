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
	t.s = generer(m);

	initialiser(t.LEE);
	initialiser(t.LEAE);

	Etat e;
	e.resultant = m;
	searchCaseVide(e);
	e.m = FIXE;
	e.indexPrecedent = NULL;
	e.g = 0;
	e.h = 0;
	inserer(t.LEAE, longueur(t.LEAE), e);

	cout << "Damier : " << t.nbL << " lignes, " << t.nbC << " colonnes" << endl
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
	unsigned int indexCourant;
	Etat* courant;
	unsigned int iteration = 0;
	while (iteration < 100)
	{
		indexCourant = 0;
		courant = &(lire(t.LEAE, 0));
		for (unsigned int i = 0; i < longueur(t.LEAE); i++)
			if (courant->g > lire(t.LEAE, i).g)
			{
				courant = &(lire(t.LEAE, i));
				indexCourant = i;
			}

		if (but(t, *courant)) return true;
		else
		{
			cout << "Iteration " << ++iteration << endl;

			inserer(t.LEE, longueur(t.LEE), *courant);
			supprimer(t.LEAE, indexCourant);
			for (int m = NORD; m <= EST; m++)
				if (estPossible(lire(t.LEE, longueur(t.LEE) - 1), (Mouvement)m))
				{
					Etat f;
					clone(f.resultant, lire(t.LEE, longueur(t.LEE) - 1).resultant);
					f.indexPrecedent = indexCourant;
					f.h = 0;
					f.g = courant->g + 1;
					deplacer(f, (Mouvement)m);

					if (!appartient(f, t))
						inserer(t.LEAE, 0, f);
				}

			afficher(t);
			cout << "Fin iteration " << iteration << endl << endl << endl;
		}
	}
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

bool appartient(Etat & e, Taquin & t)
{
	bool appartientLEE, appartientLEAE;
	for (unsigned int x = 0; x < longueur(t.LEE); x++)
	{
		appartientLEE = true;
		for (unsigned int i = 0; i < e.resultant.nbL; i++)
			for (unsigned int j = 0; j < e.resultant.nbC; j++)
				if (e.resultant.tab[i][j] != lire(t.LEE, x).resultant.tab[i][j]) appartientLEE = false;

		if (appartientLEE == true) return true;
	}

	for (unsigned int x = 0; x < longueur(t.LEAE); x++)
	{
		appartientLEAE = true;
		for (unsigned int i = 0; i < e.resultant.nbL; i++)
			for (unsigned int j = 0; j < e.resultant.nbC; j++)
				if (e.resultant.tab[i][j] != lire(t.LEAE, x).resultant.tab[i][j]) appartientLEAE = false;

		if (appartientLEAE == true) return true;
	}

	return false;
}

bool but(Taquin& t, const Etat& e)
{
	bool estBut;
	for (unsigned int x = 0; x < e.resultant.nbC; x++)
	{
		estBut = true;
		for (unsigned int i = 0; i < e.resultant.nbL; i++)
			for (unsigned int j = 0; j < e.resultant.nbC; j++)
				if (e.resultant.tab[i][j] != t.s.s[x].tab[i][j]) estBut = false;

		if (estBut == true) return true;
	}

	return false;
}

void detruire(Taquin & t)
{
	detruire(t.LEAE);
	detruire(t.LEE);
	detruire(t.s);
}