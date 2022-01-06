#ifndef _HISTORIQUE_
#define _HISTORIQUE_

#include "Stroke.h"

/**
 * @file Historique.h
 * @author WAHADA Mehdi & ALI Mehdi
 * @version 1 28/12/2021
 * @brief L'historique de coups
 */

struct Historique {
	unsigned nbrStrokes; // nbrStrokes, le nombre de coups
	Stroke *strokes; // strokes, le tableau de coups
};

/**
*	@brief d�finit l'historique de coups et l'alloue dynamiquement
*	@param[in,out] hist, l'historique de coups
*/
void defineHisto(Historique &hist);

#include "../components/Historique.cpp"
#endif // !_HISTORIQUE_