/*
* @file main.cpp
* @brief Programme de test de résolution d'un taquin
* @author CHAN Jennifer & PINARD Lucas - Groupe 104
* @version 1 - 2/01/2019
*
* Projet SDA
*/

#include "Tableau2D.h"
#include "Taquin.h"

#include <cstdlib>
#include <iostream>
using namespace std;

int main()
{
	Taquin t;
	initialiser(t);
	if (jouer(t)) afficherSolution(t);
	else cout << "Pas de solution trouvée." << endl;

	system("PAUSE"); return 0;
}