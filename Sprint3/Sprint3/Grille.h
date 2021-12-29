#ifndef _GRILLE_
#define _GRILLE_

#include "Problem.h"
#include "Case.h"
#include "Historique.h"

/**
 * @file Grille.h
 * @author WAHADA Mehdi & ALI Mehdi
 * @version 1 28/12/2021
 * @brief La grille du démineur
 */

struct Grille {
	Problem pb;	// pb, le problème de la grille
	Case **tab;	// tab, le tableau 2D de cases
	Historique histo;	// histo, l'historique de coups
};

/**
*	@brief Alloue dynamiquement les colonnes de la grille
*	@param[in,out] gr, la grille
*/
void generateGrid(Grille *gr);

/**
*	@brief Affiche la grille de démineur
*	@param[in] g, la grille
*/
void printGrid(const Grille *g);

/**
*	@brief remplit la grille avec les mines
*	@param[in,out] gr, la grille
*/
void fillGrid(Grille *gr);

/**
*	@brief Analyse chaque coup de l'historique. Si la lettre du coup est un D, démasque la case ciblée et si c'est un M, la marque.
*	@param[in,out] gr, la grille
*/
void executeStroke(Grille *gr);

/**
*	@brief rentre les coups de l'historique
*	@param[in,out] gr, la grille
*/
void setStroke(Grille *gr);

/**
*	@brief vérifie si une case est valide
*	@param[in] gr, la grille
*	@param[in] x, l'abscisse
*	@param[in] y, l'ordonnée
*	@return true si x/y sont inférieurs au nombre de lignes / colonnes
*	et supérieurs ou égales à 0, sinon false
*/
bool validCase(Grille *gr, unsigned int x, unsigned int y);

/**
*	@brief vérifie si une case contient une mine
*	@param[in] gr, la grille
*	@param[in] x, l'abscisse
*	@param[in] y, l'ordonnée
*	@return true si le contenu de la case est une mine, sinon false
*/
bool detectedMines(Grille *gr, unsigned int x, unsigned int y);

/**
*	@brief démasque la case ciblée et les cases aux alentours si la case démasquée est vide
*	@param[in,out] gr, la grille
*	@param[in] x, l'abscisse
*	@param[in] y, l'ordonnée
*/
void demask(Grille *gr, unsigned int x, unsigned int y);

/**
*	@brief Crée la grille de démineur
*/
void createGrille();

/**
*	@brief Entre les coordonnées des mines sur la grille
*	@param[in,out] gr, la grille
*/
void setMines(Grille *gr);

/**
*	@brief Incrémente les cases à proximités de mines
*	@param[in,out] gr, la grille
*	@param[in] x, l'abscisse x de la grille
*	@param[in] y, l'ordonnée y de la grille
*	@return mineCount, le nombre de mines adjacentes à la case
*	sinon 0 dans le case ou la case incrémentée contient une mine
*/
unsigned minesNearby(Grille *gr, unsigned int x, unsigned int y);

/**
*	@brief détermine si la partie est perdue
*/
void gameWon();

/**
*	@brief vérifie si la partie est gagnée
*	@param[in] gr, la grille
*	@return true si toutes les cases vides sont démasquées, sinon false.
*/
bool isWon(const Grille *gr);

#endif // !_GRILLE_
