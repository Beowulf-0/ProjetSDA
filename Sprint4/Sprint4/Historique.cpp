#include "Historique.h"
#include <iostream>

/**
*	@brief définit l'historique de coups et l'alloue dynamiquement
*	@param[in,out] hist, l'historique de coups
*/
void defineHisto(Historique *hist) {
	unsigned nbrStroke;
	std::cin >> nbrStroke;
	hist->nbrStrokes = nbrStroke;
	hist->strokes = new Stroke[hist->nbrStrokes];
}