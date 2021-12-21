#ifndef _STROKE_
#define _STROKE_

#include "Grille.h"

/*
*	@brief représente un coup au démineur
*/
struct Stroke {
	char letter; // Lettre du coup
	unsigned int pos; // Position du coup dans la grille
};

/*
*	@brief insère les coups dans l'historique de coups
*	@param[in,out] gr, la grille
*	@pre la lettre du coup rentré est soit D, soit M
*/
void setStroke(Grille &gr);

/*
*	@brief vérifie chaque coup de l'historique, si la lettre du coup est un D
*	@param[in,out] gr, la grille
*	@param[in] x, l'abscisse
*	@param[in] y, l'ordonnée
*	@pre si la lettre du coup est pas D ou M et si la position < x * y
*/
void checkStroke(Grille *gr, unsigned int x, unsigned int y);

#endif // !_STROKE_