#include <iostream>
#include <time.h>
#include <cassert>
#include <random>



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
	unsigned int* tabMines;
};

struct Historique {
	unsigned int nbCoups;
	unsigned int position;
	char symbole;
};

struct Grille {
	Probleme probleme;
	unsigned int tabGrille;
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

void genererMines(Probleme& p, unsigned int mines[]);


int main() {
	srand((unsigned int)time(NULL));

	Probleme p;
	Grille g;

	int commande;

	std::cin >> commande;
	while (true) {
		switch (commande) {
		case 1:
			createProblem(p);
			printProblem(p);
			break;
		case 2:
			//printGrid(g);
			break;

		case 5:
			//
			break;
		case 6:
			return 0;
			break;
		}
	}

}

void createProblem(Probleme& p) {

	std::cin >> p.nbLignes >> p.nbColonnes >> p.nbMines;
	
	p.tabMines = new unsigned int[p.nbMines];

	genererMines(p, p.tabMines);

	std::cout << p.nbLignes << " " << p.nbColonnes << " " << p.nbMines;

	for (unsigned int i = 0; i < p.nbMines; i++) {
		std::cout << " " << p.tabMines[i];
	}
}

void printProblem(const Probleme& p) {

	std::cout << p.nbLignes << " " << p.nbColonnes << " " << p.nbMines;
	for (unsigned int i = 0; i < p.nbMines; i++) {
		//std::cout << " " << p.tabMines[i];
	}
	std::cout << std::endl;
}

void createGrid(Grille& g) {
	std::cin >> g.probleme.nbLignes >> g.probleme.nbColonnes >> g.probleme.nbMines;
	for (unsigned int i = 0; i < g.probleme.nbMines; i++) {
		std::cin >> g.probleme.tabMines[i];
	}
	std::cin >> g.coups.nbCoups;

}

void genererMines(Probleme& p, unsigned int mines[]) {
	for (unsigned int m = 0; m < p.nbMines; m++) {
		unsigned int limitePos = p.nbColonnes * p.nbLignes;
		mines[m] = std::rand() % limitePos;
	}
}


void tests() {

}