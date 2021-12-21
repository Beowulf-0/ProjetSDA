#ifndef _GRILLE_
#define _GRILLE_

#include "Problem.h"
#include "Historique.h"


/*
*	@brief représente une grille
*/
struct Grille {
	Problem pb; // pb, le problème
	unsigned **tab; // tab, un tableau 2D représentant une grille de démineur
	Historique histo; // histo, l'historique de coups
};

/*
*	@brief vérifie si une case de la grille est valide
*	@param[in,out] gr, la grille
*	@param[in] x, l'abscisse 
*	@param[in] y, l'ordonnée
*	@return vrai si x / y <= 0 et >= au nombre de lignes / colonnes 
*/
bool validCase(Grille *gr, unsigned int x, unsigned int y);

/*
*	@brief vérifie s'il y a des mines sur la case choisie
*	@param[in,out] gr, la grille
*	@param[in] x, l'abscisse
*	@param[in] y, l'ordonnée
*	@return vrai si la case[x][y] contient une mine
*/
bool detectedMines(Grille *gr, unsigned int x, unsigned int y);

/**
*	@brief Incrémente les cases à proximités de mines
*	@param[in,out] gr, la grille
*	@param[in] x, l'abscisse x de la grille
*	@param[in] y, l'ordonnée y de la grille
*	@return le nombre de mines à proximité de la case.
*/
unsigned int minesNearby(Grille *gr, unsigned int x, unsigned int y);

/*
*	@brief initialise les colonnes de la grille
*	@param[in,out] gr, la grille
*/
void generateGrid(Grille *gr);

/*
*	@brief affiche la grille du démineur
*	@param[in] g, la grille
*/
void printGrid(const Grille *g);

/*
*	@brief Crée une grille de démineur
*/
void createGrille();

/*
*	@brief Démasque une case. Si elle est vide, démasque les autres aux alentours, sinon n'affiche que la case ciblé.
*	@param[in,out] gr, la grille
*	@param[in] x, l'abscisse
*	@param[in] y, l'ordonnée
*/
void unmaskMines(Grille &gr, unsigned int x, unsigned int y);

/*
*	@brief rentre les positions des mines dans le tableau associé
*	@param[in,out] gr, la grille
*/
void setMines(Grille *gr);

/*
*	@brief place les mines 
*	@param[in,out] g, la grille
*	@param[in] i, la ligne 
*	@param[in] j, la colonne
*	@param[in] numToCheck, le numéro correspondant à la position de la mine
*/
void placeMines(Grille *g, unsigned i, unsigned j, unsigned numToCheck);

/*
*	@brief initialise les colonnes de la grille
*	@param[in,out] g, la grille
*/
void fillGrid(Grille *g);

#endif // !_GRILLE_

