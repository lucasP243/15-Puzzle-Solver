#include "Tableau2D.h"

#include <cassert>
#include <cstring>
#include <iomanip>
#include <iostream>
using namespace std;

void initialiser(Tab2D& m, unsigned int nbL, unsigned int nbC)
{
	assert(nbL && nbC);
	m.tab = new Item*[nbL];

	for (unsigned int i = 0; i < nbL; i++)
	{
		m.tab[i] = new Item[nbC];
	}

	m.nbL = nbL;
	m.nbC = nbC;

	cout << "Damier : " << m.nbL << " lignes, " << m.nbC << " colonnes"
		<< endl;
}

void detruire(Tab2D& m)
{
	for (unsigned int i = 0; i < m.nbL; i++)
	{
		delete[] m.tab[i];
	}

	delete[] m.tab;
}

void lire(Tab2D& m)
{
	char temp[3];
	for (unsigned int i = 0; i < m.nbL; i++) 
		for (unsigned int j = 0; j < m.nbC; j++)
		{
			cin >> temp;
			if (temp[0] == '#')
				m.tab[i][j] = 0;
			else
				m.tab[i][j] = atoi(temp);
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