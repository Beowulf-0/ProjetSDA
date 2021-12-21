#include "Historique.h"

/*
*	@brief initialise un historique de coups
*	@param[in,out] hist, l'historique de coups
*	@param[in] nbrStroke, le nombre de coups
*/
void defineHisto(Historique *hist, unsigned nbrStroke) {
	hist->nbrStrokes = nbrStroke;
	hist->strokes = new Stroke[hist->nbrStrokes];
}