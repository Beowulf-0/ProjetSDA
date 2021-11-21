#include <iostream>
#include <time.h>
#include <cassert>

/*	@brief représente un problème dans une partie de démineur
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

/*	@brief Crée un problème
*	@param[in-out] p, le problème
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