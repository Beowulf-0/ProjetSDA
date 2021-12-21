#ifndef _HISTORIQUE_

#define _HISTORIQUE_

#include "Stroke.h"

/*
*	@brief représente un historique de coups
*/
struct Historique {
	unsigned nbrStrokes; // nbrStrokes, le nombre de coups
	Stroke *strokes; // strokes, le tableau de coups
};

/*
*	@brief initialise un historique de coups
*	@param[in,out] hist, l'historique de coups
*	@param[in] nbrStroke, le nombre de coups
*/
void defineHisto(Historique *hist, unsigned nbrStroke);

#endif // !_HISTORIQUE_

