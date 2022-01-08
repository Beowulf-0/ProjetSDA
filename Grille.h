#ifndef _GRILLE_
#define _GRILLE_

#include "Problem.h"
#include "Case.h"
#include "Historique.h"

/**
 * @file Grille.h
 * @author WAHADA Mehdi & ALI Mehdi
 * @version 1 28/12/2021
 * @brief La grille du demineur
 */

struct Grille {
	Problem pb;	// pb, le probleme de la grille
	Case **tab;	// tab, le tableau 2D de cases
	Historique histo;	// histo, l'historique de coups
};

/**
*	@brief Alloue dynamiquement les colonnes de la grille
*	@param[in,out] gr, la grille
*/
void generateGrid(Grille &gr);

/**
*	@brief Affiche la grille de demineur
*	@param[in] g, la grille
*/
void printGrid(const Grille &g);

/**
*	@brief remplit la grille avec les mines
*	@param[in,out] gr, la grille
*/
void fillGrid(Grille &gr);

/**
*	@brief Analyse chaque coup de l'historique. Si la lettre du coup est un D, demasque la case ciblee et si c'est un M, la marque.
*	@param[in,out] gr, la grille
*/
void executeStroke(Grille &gr);

/**
*	@brief rentre les coups de l'historique
*	@param[in,out] gr, la grille
*/
void setStroke(Grille &gr);

/**
*	@brief verifie si une case est valide
*	@param[in] gr, la grille
*	@param[in] x, l'abscisse
*	@param[in] y, l'ordonnee
*	@return true si x/y sont inferieurs au nombre de lignes / colonnes
*	et superieurs ou egales e 0, sinon false
*/
bool validCase(Grille &gr, unsigned int x, unsigned int y);

/**
*	@brief verifie si une case contient une mine
*	@param[in] gr, la grille
*	@param[in] x, l'abscisse
*	@param[in] y, l'ordonnee
*	@return true si le contenu de la case est une mine, sinon false
*/
bool detectedMines(Grille &gr, unsigned int x, unsigned int y);

/**
*	@brief demasque la case ciblee et les cases aux alentours si la case demasquee est vide
*	@param[in,out] gr, la grille
*	@param[in] x, l'abscisse
*	@param[in] y, l'ordonnee
*/
void demask(Grille &gr, unsigned int x, unsigned int y);

/**
*	@brief Cree la grille de demineur
 *	@param[in] command Permet d'effectuer une action par rapport à la commande (lose, win, showGrid)
*/
void createGrille(unsigned command);

/**
*	@brief Entre les coordonnees des mines sur la grille
*	@param[in,out] gr, la grille
*/
void setMines(Grille &gr);

/**
*	@brief Incremente les cases e proximites de mines
*	@param[in,out] gr, la grille
*	@param[in] x, l'abscisse x de la grille
*	@param[in] y, l'ordonnee y de la grille
*	@return mineCount, le nombre de mines adjacentes e la case
*	sinon 0 dans le case ou la case incrementee contient une mine
*/
unsigned minesNearby(Grille &gr, unsigned int x, unsigned int y);

/**
*	@brief verifie si la partie est perdue
*	@param[in] gr, la grille
*	@return vrai si une case vide est demasque ou si une case minee est marquee, sinon false.
*/
bool isLost(const Grille &gr);

/**
*	@brief verifie si la partie est gagnée
*	@param[in] gr, la grille
*	@return vrai si la partie est gagnée, faux si perdue
*/
bool isWon(const Grille &gr);

/**
 * @brief supprime l'allocation dynamique attribué à la grille
 * @param[in] gr, la grille
 */
void deleteGrille(Grille &gr);

/**
 * @brief lis une grille et cherche une case démasquable
 */
void readGrille();

#endif // !_GRILLE_
