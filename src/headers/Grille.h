#ifndef _GRILLE_
#define _GRILLE_

#include "Problem.h"
#include "Case.h"
#include "Historique.h"

/**
 * @file Grille.h
 * @author WAHADA Mehdi & ALI Mehdi
 * @version 1 28/12/2021
 * @brief La grille du d�mineur
 */

struct Grille {
	Problem pb;	// pb, le probl�me de la grille
	Case **tab;	// tab, le tableau 2D de cases
	Historique histo;	// histo, l'historique de coups
};

/**
*	@brief Alloue dynamiquement les colonnes de la grille
*	@param[in,out] gr, la grille
*/
void generateGrid(Grille &gr);

/**
*	@brief Affiche la grille de d�mineur
*	@param[in] g, la grille
*/
void printGrid(const Grille &g);

/**
*	@brief remplit la grille avec les mines
*	@param[in,out] gr, la grille
*/
void fillGrid(Grille &gr);

/**
*	@brief Analyse chaque coup de l'historique. Si la lettre du coup est un D, d�masque la case cibl�e et si c'est un M, la marque.
*	@param[in,out] gr, la grille
*/
void executeStroke(Grille &gr);

/**
*	@brief rentre les coups de l'historique
*	@param[in,out] gr, la grille
*/
void setStroke(Grille &gr);

/**
*	@brief v�rifie si une case est valide
*	@param[in] gr, la grille
*	@param[in] x, l'abscisse
*	@param[in] y, l'ordonn�e
*	@return true si x/y sont inf�rieurs au nombre de lignes / colonnes
*	et sup�rieurs ou �gales � 0, sinon false
*/
bool validCase(Grille &gr, unsigned int x, unsigned int y);

/**
*	@brief v�rifie si une case contient une mine
*	@param[in] gr, la grille
*	@param[in] x, l'abscisse
*	@param[in] y, l'ordonn�e
*	@return true si le contenu de la case est une mine, sinon false
*/
bool detectedMines(Grille &gr, unsigned int x, unsigned int y);

/**
*	@brief d�masque la case cibl�e et les cases aux alentours si la case d�masqu�e est vide
*	@param[in,out] gr, la grille
*	@param[in] x, l'abscisse
*	@param[in] y, l'ordonn�e
*/
void demask(Grille &gr, unsigned int x, unsigned int y);

/**
*	@brief Cr�e la grille de d�mineur
*/
void createGrille();

/**
*	@brief Entre les coordonn�es des mines sur la grille
*	@param[in,out] gr, la grille
*/
void setMines(Grille &gr);

/**
*	@brief Incr�mente les cases � proximit�s de mines
*	@param[in,out] gr, la grille
*	@param[in] x, l'abscisse x de la grille
*	@param[in] y, l'ordonn�e y de la grille
*	@return mineCount, le nombre de mines adjacentes � la case
*	sinon 0 dans le case ou la case incr�ment�e contient une mine
*/
unsigned minesNearby(Grille &gr, unsigned int x, unsigned int y);

/**
*	@brief d�termine si la partie est perdue
*/
void gameLost();

/**
*	@brief v�rifie si la partie est perdue
*	@param[in] gr, la grille
*	@return vrai si une case vide est d�masqu� ou si une case min�e est marqu�e, sinon false.
*/
bool isLost(const Grille &gr);

/**
*	@brief d�termine si la partie est perdue
*/
void gameWon();

#include "../components/Grille.cpp"
#endif // !_GRILLE_
