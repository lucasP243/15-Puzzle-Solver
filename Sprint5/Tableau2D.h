/**
* @file Tableau2D.h
* @brief D�finition du type structur� Tab2D
* @author CHAN Jennifer & PINARD Lucas - Groupe 104
* @version 1 - 13/12/2018
* 
* Projet SDA
*/

#ifndef _TABLEAU2D_
#define _TABLEAU2D_

struct Tab2D
{
	unsigned int** tab;	// adresse du tableau bidimensionnel 
						// allou� en m�moire dynamique

	unsigned int
		nbL,			// nombre de lignes de la matrice
		nbC;			// nombre de colonnes de la matrice
};

struct Solutions
{
	Tab2D* s;			// tableau des diff�rents damiers solutions
	unsigned int nb;	// nombre de solutions
};

/**
* @brief Allouer en m�moire dynamique un Tableau2D
* @param[in/out] m : le tableau � initialiser
* @param[in] nbL : le nombre de lignes de m
* @param[in] nbC : le nombre de colonnes de m
* @pre nbL > 0 && nbC > 0
*/
void initialiser(
	Tab2D& m, 
	unsigned int nbL, 
	unsigned int nbC
);

/**
* @brief D�sallouer un Tableau2D
* @param[in] m : le tableau � d�sallouer
*/
void detruire(
	Tab2D& m
);

/**
* @brief Lire un Tableau2D
* @param[in] m : le tableau � lire
*/
void lire(
	Tab2D& m
);

/**
* @brief Afficher un Tableau2D
* @param[in] m (constant) : le tableau � afficher
*/
void afficher(
	const Tab2D& m
);

/**
* @brief Cloner un Tableau 2D
* @param[in] m : le tableau � initialiser
* @param[in] ref : le tableau � cloner
*/
void clone(
	Tab2D& m,
	const Tab2D& ref
);

/**
* @brief G�n�rer les solutions d'un Tableau2D
* @param[in] m : le Tableau2D
* @return les solutions
*/
Solutions generer(Tab2D& m);

/**
* @brief D�sallouer les solutions d'un taquin
* @param[in] s : les solutions
*/
void detruire(Solutions& s);

#endif // !_TABLEAU2D_