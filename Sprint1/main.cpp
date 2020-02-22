#include "Tableau2D.h"

#include <cstdlib>
#include <iostream>
using namespace std;

void main()
{
	Tab2D m;
	unsigned int
		L,
		C;

	cin >> L >> C;
	initialiser(m, L, C);

	lire(m);

	afficher(m);

	detruire(m);

	system("PAUSE");
}