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
		e.resultant.tab[e.x][e.y] = 
			e.resultant.tab[e.x][(int)(e.y - 1) % e.resultant.nbC];
		e.resultant.tab[e.x][(e.y - 1) % e.resultant.nbC] = 0;
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