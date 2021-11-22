#include <iostream>
#include <time.h>
#include <cassert>

#define minMines 1
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

/**
*	@brief Affiche le problème
*	@param[in] p, le problème
*/
void printProblem(const Probleme& p);

int main() {
	srand((unsigned int)time(NULL));
	Probleme p;

	char commande;

	std::cin >> commande;

	switch (commande) {
		case '1':
			createProblem(p);
			printProblem(p);

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

	assert((p.nbLignes > 0 || p.nbColonnes > 0 || p.nbMines > 0) && (p.nbLignes < 16 || p.nbColonnes < 16 || p.nbMines < maxMines));

	for (unsigned int i = 0; i < p.nbMines; i++) {
		p.tabMines[i] = rand() % (maxMines / 2) + minMines;
	}
}

void printProblem(const Probleme& p) {
	std::cout << p.nbLignes << " " << p.nbColonnes << " " << p.nbMines;
	for (unsigned int i = 0; i < p.nbMines; i++) {
		std::cout << " " << p.tabMines[i];
	}
}

void tests() {

}