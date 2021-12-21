#ifndef _GRILLE_
#define _GRILLE_

#include "Problem.h"
#include "Historique.h"


/*
*	@brief repr�sente une grille
*/
struct Grille {
	Problem pb; // pb, le probl�me
	unsigned **tab; // tab, un tableau 2D repr�sentant une grille de d�mineur
	Historique histo; // histo, l'historique de coups
};

/*
*	@brief v�rifie si une case de la grille est valide
*	@param[in,out] gr, la grille
*	@param[in] x, l'abscisse 
*	@param[in] y, l'ordonn�e
*	@return vrai si x / y <= 0 et >= au nombre de lignes / colonnes 
*/
bool validCase(Grille *gr, unsigned int x, unsigned int y);

/*
*	@brief v�rifie s'il y a des mines sur la case choisie
*	@param[in,out] gr, la grille
*	@param[in] x, l'abscisse
*	@param[in] y, l'ordonn�e
*	@return vrai si la case[x][y] contient une mine
*/
bool detectedMines(Grille *gr, unsigned int x, unsigned int y);

/**
*	@brief Incr�mente les cases � proximit�s de mines
*	@param[in,out] gr, la grille
*	@param[in] x, l'abscisse x de la grille
*	@param[in] y, l'ordonn�e y de la grille
*	@return le nombre de mines � proximit� de la case.
*/
unsigned int minesNearby(Grille *gr, unsigned int x, unsigned int y);

/*
*	@brief initialise les colonnes de la grille
*	@param[in,out] gr, la grille
*/
void generateGrid(Grille *gr);

/*
*	@brief affiche la grille du d�mineur
*	@param[in] g, la grille
*/
void printGrid(const Grille *g);

/*
*	@brief Cr�e une grille de d�mineur
*/
void createGrille();

/*
*	@brief D�masque une case. Si elle est vide, d�masque les autres aux alentours, sinon n'affiche que la case cibl�.
*	@param[in,out] gr, la grille
*	@param[in] x, l'abscisse
*	@param[in] y, l'ordonn�e
*/
void unmaskMines(Grille &gr, unsigned int x, unsigned int y);

/*
*	@brief rentre les positions des mines dans le tableau associ�
*	@param[in,out] gr, la grille
*/
void setMines(Grille *gr);

/*
*	@brief place les mines 
*	@param[in,out] g, la grille
*	@param[in] i, la ligne 
*	@param[in] j, la colonne
*	@param[in] numToCheck, le num�ro correspondant � la position de la mine
*/
void placeMines(Grille *g, unsigned i, unsigned j, unsigned numToCheck);

/*
*	@brief initialise les colonnes de la grille
*	@param[in,out] g, la grille
*/
void fillGrid(Grille *g);

#endif // !_GRILLE_

