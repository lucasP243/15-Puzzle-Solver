/**
* @file Tableau2D.cpp
* @brief Codage des fonctions relatives au type Tab 2D
* @author CHAN Jennifer & PINARD Lucas - Groupe 104
* @version 1 - 13/12/2018
*
* Projet SDA
*/

#include "Tableau2D.h"

#include <cassert>
#include <cstring>
#include <iomanip>
#include <iostream>
using namespace std;

void initialiser(Tab2D& m, unsigned int nbL, unsigned int nbC)
{

	assert(nbL && nbC);
	m.tab = new unsigned int*[nbL];

	for (unsigned int i = 0; i < nbL; i++)
	{
		m.tab[i] = new unsigned int[nbC];
	}

	m.nbL = nbL;
	m.nbC = nbC;
}

void detruire(Tab2D& m)
{
	for (unsigned int i = 0; i < m.nbL; i++)
	{
		delete[] m.tab[i];
	}

	delete[] m.tab;
	m.tab = NULL;
}

void lire(Tab2D& m)
{
	char temp[3];
	bool voidIsSet = false;
	for (unsigned int i = 0; i < m.nbL; i++) 
		for (unsigned int j = 0; j < m.nbC; j++)
		{
			cin >> temp;
			if (temp[0] == '#')
			{
				assert(voidIsSet == false);
				m.tab[i][j] = 0;
				voidIsSet = true;
			}
			else 
			{
				m.tab[i][j] = atoi(temp);
				assert(m.tab[i][j] < m.nbL * m.nbC);
			}
		}
}

void afficher(const Tab2D& m)
{
	for (unsigned int i = 0; i < m.nbL; i++)
	{
		for (unsigned int j = 0; j < m.nbC; j++)
		{
			if (m.tab[i][j]) cout << setw(3) << m.tab[i][j];
			else cout << "  #";
		}

		cout << endl;
	}
}

void clone(Tab2D & m, const Tab2D & ref)
{
	initialiser(m, ref.nbL, ref.nbC);
	for (unsigned int i = 0; i < ref.nbL; i++)
		for (unsigned int j = 0; j < ref.nbC; j++)
			m.tab[i][j] = ref.tab[i][j];
}

Solutions generer(Tab2D & m)
{
	Solutions solt;
	solt.nb = m.nbC;
	solt.s = new Tab2D[solt.nb];

	for (unsigned int x = 0; x < m.nbC; x++)
	{
		initialiser(solt.s[x], m.nbL, m.nbC);
		for (unsigned int i = 0; i < m.nbL; i++)
			for (unsigned int j = 0; j < m.nbC; j++)
			{
				solt.s[x].tab[i][j] = (((j + x) % m.nbC) + (i * m.nbC) + 1) % (m.nbL * m.nbC);
				solt.s[x].tab[i][j];
			}
	}

	return solt;
}

void detruire(Solutions& s)
{
	for (unsigned int x = 0; x < s.nb; x++)
		detruire(s.s[x]);
	delete[] s.s;
	s.s = NULL;
}