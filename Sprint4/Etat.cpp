/**
* @file Etat.cpp
* @brief Codage des fonctions relatives au type Etat
* @author CHAN Jennifer & PINARD Lucas - Groupe 104
* @version 1 - 26/12/2018
*
* Projet SDA
*/

#include "Etat.h"
#include "Tableau2D.h"

#include <cassert>
#include <iostream>
using namespace std;

void afficher(Etat & e)
{
	switch (e.m)
	{
	case FIXE:
		break;
	case EST:
		cout << "EST" << endl;
		break;
	case SUD:
		cout << "SUD" << endl;
		break;
	case OUEST:
		cout << "OUEST" << endl;
		break;
	case NORD:
		cout << "NORD" << endl;
		break;
	default:
		break;
	}
	afficher(e.resultant);
	cout << "f=g+h=" << e.g << "+" << e.h << "=" << e.g + e.h << endl;
}

void searchCaseVide(Etat & e)
{
	for (unsigned int i = 0; i < e.resultant.nbL; i++)
		for (unsigned int j = 0; j < e.resultant.nbC; j++)
			if (e.resultant.tab[i][j] == 0)
			{
				e.x = i;
				e.y = j;
				break;
			}
}

bool estPossible(Etat & e, Mouvement m)
{
	bool s;
	switch (m)
	{
	case OUEST:
	case EST:
		s = true;
		break;
	case NORD:
		s = (e.x != 0);
		break;
	case SUD:
		s = (e.x < e.resultant.nbL - 1);
		break;
	default:
		s = false;
		break;
	}
	return s;
}

void deplacer(Etat & e, Mouvement m)
{
	e.m = m;
	searchCaseVide(e);
	switch (m)
	{
	case EST:
		e.resultant.tab[e.x][e.y] = 
			e.resultant.tab[e.x][(e.y + 1) % e.resultant.nbC];
		e.resultant.tab[e.x][(e.y + 1) % e.resultant.nbC] = 0;
		searchCaseVide(e);
		break;

	case SUD:
		e.resultant.tab[e.x][e.y] = e.resultant.tab[(e.x) + 1][e.y];
		e.resultant.tab[(e.x) + 1][e.y] = 0;
		searchCaseVide(e);
		break;

	case OUEST:
		if (e.y == 0)
		{
			e.resultant.tab[e.x][e.y] =
				e.resultant.tab[e.x][e.resultant.nbC - 1];
			e.resultant.tab[e.x][e.resultant.nbC - 1] = 0;
		}
		else
		{
			e.resultant.tab[e.x][e.y] =
				e.resultant.tab[e.x][(e.y - 1) % e.resultant.nbC];
			e.resultant.tab[e.x][(e.y - 1) % e.resultant.nbC] = 0;
		}
		searchCaseVide(e);
		break;

	case NORD:
		e.resultant.tab[e.x][e.y] = e.resultant.tab[(e.x) - 1][e.y];
		e.resultant.tab[(e.x) - 1][e.y] = 0;
		searchCaseVide(e);
		break;

	default:
		break;
	}
}

unsigned int heuristique(Etat & e)
{
	Solutions s = generer(e.resultant);
	unsigned int h = e.resultant.nbC * e.resultant.nbL, h1;

	for (unsigned int x = 0; x < s.nb; x++)
	{
		h1 = 0;
		for (unsigned int i = 0; i < e.resultant.nbL; i++)
			for (unsigned int j = 0; j < e.resultant.nbC; j++)
				if (e.resultant.tab[i][j] != 0
					&& e.resultant.tab[i][j] != s.s[x].tab[i][j])
					h1++;
		if (h1 < h) h = h1;
	}
	return h;
}
