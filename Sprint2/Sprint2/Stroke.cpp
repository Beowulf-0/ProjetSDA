#include <cassert>
#include <iostream>

#include "Stroke.h"

/*
*	@brief insère les coups dans l'historique de coups
*	@param[in,out] gr, la grille
*	@pre la lettre du coup rentré est soit D, soit M et que la position rentrée
*/
void setStroke(Grille &gr) {
	for (unsigned int str = 0; str < gr.histo.nbrStrokes; str++) {
		char stroke;
		unsigned int pos;
		std::cin >> stroke >> pos;
		gr.histo.strokes[str].letter = stroke;
		gr.histo.strokes[str].pos = pos;
	}
}

void checkStroke(Grille &gr, unsigned int x, unsigned int y) {
	unsigned lines = gr.pb.lineNumber, column = gr.pb.columnNumber;
	for (unsigned int i = 0; i < gr.histo.nbrStrokes; i++) {
		assert((gr.histo.strokes[i].letter == 'D' || 
			gr.histo.strokes[i].letter == 'M') && gr.histo.strokes[i].pos < lines * column);
		if (gr.histo.strokes[i].letter == 'D') {
			unmaskMines(gr, x, y);
		}
	}
}