#include <iostream>
#include <time.h>
#include <cassert>

/*	@brief repr�sente un probl�me dans une partie de d�mineur
*
*
*/
struct Probleme {
	unsigned int nbLignes;
	unsigned int nbColonnes;
	unsigned int nbMines;
};

struct Historique {
	unsigned int nbCoups;
};

struct Grille {
	Probleme probleme;
};

/*	@brief Cr�e un probl�me
*	@param[in-out] p, le probl�me
*/
void createProblem(Probleme& p);

int main() {
	srand((unsigned int)time(NULL));
	Probleme p;

	char commande;

	std::cin >> commande;

	switch (commande) {
		case '1':
			createProblem(p);

		case '2':
		//createGrid();

		case '3':
		//

		case '4':
		//

		case '5':
		//
		default:
			break;
	}
}

void createProblem(Probleme& p) {

	assert(p.nbLignes > 0 || p.nbColonnes || p.nbMines);
	
	std::cin >> p.nbLignes >> p.nbColonnes >> p.nbMines;

	for (int i = 0; i < p.nbMines; i++) {

	}
	
}