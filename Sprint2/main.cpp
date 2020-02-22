#include "Tableau2D.h"
#include "Taquin.h"

#include <cstdlib>
#include <iostream>
using namespace std;

int main()
{
	Taquin t;
	initialiser(t);
	jouer(t);
	detruire(t);

	system("PAUSE"); return 0;
}