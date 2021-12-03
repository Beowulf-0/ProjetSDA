#include <iostream>
#include <time.h>
#include <cassert>
#include <random>

typedef char Coup[3];

/**
*	@brief repr�sente un probl�me dans une partie de d�mineur
*/
struct Probleme {
	unsigned int nbLignes;
	unsigned int nbColonnes;
	unsigned int nbMines;
	unsigned int *tabMines;
};

struct Historique {
	unsigned int nbCoups;
	Coup *coups;
};

struct Grille {
	Probleme probleme;
	unsigned int* tabGrille;
	Historique histo;
};

/**
*	@brief Cr�e un probl�me
*	@param[in-out] p, le probl�me
*/
void createProblem(Probleme& p);

/**	@brief G�n�re des mines sur des positions al�atoires
*	@param[in-out] p, le probl�me
*	@param[in-out] mines, le tableau de mines
*/
void genererMines(Probleme& p, unsigned int mines[]);

/**	@brief Cr�er une grille � partir d'un probl�me et de l'historique de coups
*	@param[in-out] g, la grille
*/
void createGrid(Grille& g);

void printGrid(const Grille& g, unsigned int lignes, unsigned int colonnes);

int main() {
	srand((unsigned int)time(NULL));

	Probleme p;
	Grille g;

	int commande;

	while (true) {
		std::cin >> commande;
		switch (commande) {
		case 1:
			createProblem(p);
			break;
		case 2:
			createGrid(g);
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
	std::cout << std::endl;
}

//pas oblig� de faire une seule ligne avec toutes les commandes, fait des boucles.
//pour extraire les sous chaines, voir strncpy et atoi (convertir)

//historique : boucle for lorsque l'on fournit le nombre de coups.

/**	@brief r�alise une grille � partir du nombre de lignes, de colonnes, de mines, des positions des mines et de l'historique de coups
*	@param[in-out] g, la grille cr��
*
*/
void createGrid(Grille& g) {
//	unsigned int *tMines = g.probleme.tabMines;
//	unsigned int limitePos = g.probleme.nbLignes * g.probleme.nbColonnes;
//
//	unsigned int lignes = g.probleme.nbLignes;
//	unsigned int colonnes = g.probleme.nbColonnes;
//
//	//char mot[4];
//
////	Grille **gr = new Grille*[lignes];
//
//	std::cin >> g.probleme.nbLignes >> g.probleme.nbColonnes >> g.probleme.nbMines;
//
//	tMines = new unsigned int[g.probleme.nbMines];
//
//	for (unsigned int m = 0; m < g.probleme.nbMines; m++) {
//		std::cin >> tMines[m];
//	}
//
//	std::cin >> g.histo.nbCoups;
//
//	g.histo.coups = new Coup[g.histo.nbCoups];
//
//	for (unsigned int c = 0; c < g.histo.nbCoups; c++) {
//		std::cin >> g.histo.coups[c];
//		//strncpy(mot, g.histo.coups[c], strlen(mot));
//	}
//	
//	std::cout << g.probleme.nbLignes << " " << g.probleme.nbColonnes << " " << g.probleme.nbMines << " ";
//	for (unsigned int i = 0; i < g.probleme.nbMines; i++) {
//		std::cout << tMines[i] << " ";
//	}
//
//	std::cout << g.histo.nbCoups << " ";
//
//	for (unsigned int j = 0; j < g.histo.nbCoups; j++) {
//		std::cout << g.histo.coups[j] << " ";
//	}
//
//	std::cout << std::endl;

	/*for (unsigned int grL = 0; grL < lignes; grL++) {
		gr[grL] = new Grille[colonnes];
	}*/

	printGrid(g, 3, 3);

	/*delete[] tMines;
	delete[] g.histo.coups;*/
}

void printGrid(const Grille& g, unsigned int lignes, unsigned int colonnes) {
	std::cout << lignes << " " << colonnes;
	std::cout << std::endl;
	for (unsigned int i = 0; i < lignes; i++) {
		for (unsigned int j = 0; j < colonnes; j++) {
			std::cout << "___" << std::endl;
			std::cout << "| " << " ";
			if (i == lignes - 1) std::cout << " |" << std::endl;
			if (j == colonnes - 1) std::cout << "___";
		}
	}
}

void genererMines(Probleme& p, unsigned int mines[]) {
	for (unsigned int m = 0; m < p.nbMines; m++) {
		unsigned int limitePos = p.nbColonnes * p.nbLignes;
		mines[m] = std::rand() % limitePos;
	}
}


void tests() {

}