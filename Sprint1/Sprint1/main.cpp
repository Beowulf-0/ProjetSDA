#include <iostream>
#include <time.h>
#include <cassert>



/**
*	@brief repr�sente un probl�me dans une partie de d�mineur
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
	char coups[2];
};

struct Mine{
	bool estMarqu�e;
	char symbole = 'x';
};

struct Grille {
	Probleme probleme;
	unsigned int tabGrille;
	Historique coups;
};

/**
*	@brief Cr�e un probl�me
*	@param[in-out] p, le probl�me
*/
void createProblem(Probleme& p);

/**
*	@brief Affiche le probl�me
*	@param[in] p, le probl�me
*/
void printProblem(const Probleme& p);

/**
*
*
*/
void printGrid(const Grille& g);

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
			printGrid(g);
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
	//unsigned int lignes;
	//unsigned int colonnes;
	
	std::cin >> p.nbLignes >> p.nbColonnes >> p.nbMines;
	//p.tabMines = new unsigned int[p.nbMines];
	//assert((p.nbLignes > 0 || p.nbColonnes > 0 || p.nbMines > 0) && (p.nbLignes < 16 || p.nbColonnes < 16 || p.nbMines < 32));

}

void printProblem(const Probleme& p) {
	
	std::cout << p.nbLignes << " " << p.nbColonnes << " " << p.nbMines;
	for (unsigned int i = 0; i < p.nbMines; i++) {
		//std::cout << " " << p.tabMines[i];
	}
	std::cout << std::endl;
}

void createGrid(Grille& g) {
	unsigned int lignes, colonnes, nbreMines;
	Grille gr;
	gr.probleme.tabMines[g.probleme.nbMines];
	std::cin >> lignes >> colonnes >> nbreMines;
	
}

//
void printGrid(const Grille& g) {
	
}

void tests() {

}