#include <iostream>
#include <time.h>
#include <cassert>

#define maxMines 32

/**
*	@brief représente un problème dans une partie de démineur
*	nbLignes, le nombre de lignes de la future grille
*	nbColonnes, le nombre de colonnes de la future grille
*	nbMines, le nombre de mines de la future grille
*/
struct Probleme {
	unsigned int nbLignes;
	unsigned int nbColonnes;
	unsigned int nbMines;
	unsigned int tabMines[maxMines];
};

struct Historique {
	unsigned int nbCoups;
};

struct Grille {
	Probleme probleme;
	Historique coups;
};

/**
*	@brief Crée un problème
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
			break;
		
		case '5':
		//
			break;
		default:
			break;
	}
}

void createProblem(Probleme& p) {
	
	std::cin >> p.nbLignes >> p.nbColonnes >> p.nbMines;

	assert(p.nbLignes > 0 || p.nbColonnes > 0 || p.nbMines > 0);

	for (int i = 0; i < p.nbMines; i++) {
		
	}
}