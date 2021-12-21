#include "Grille.h"
#include "Element.h"
#include <cassert>
#include <iostream>

/*
*	@brief vérifie si une case de la grille est valide
*	@param[in,out] gr, la grille
*	@param[in] x, l'abscisse
*	@param[in] y, l'ordonnée
*	@return vrai si x / y <= 0 et >= au nombre de lignes / colonnes
*/
bool validCase(Grille *gr, unsigned int x, unsigned int y) {
	return (x >= 0 && x < gr->pb.lineNumber) && (y >= 0 && y < gr->pb.columnNumber);
}

/*
*	@brief vérifie s'il y a des mines sur la case choisie
*	@param[in,out] gr, la grille
*	@param[in] x, l'abscisse
*	@param[in] y, l'ordonnée
*	@return vrai si la case[x][y] contient une mine
*/
bool detectedMines(Grille *gr, unsigned int x, unsigned int y) {
	return gr->tab[x][y] == ELEMENTS::BOMB;
}

/**
*	@brief Incrémente les cases à proximités de mines
*	@param[in,out] gr, la grille
*	@param[in] x, l'abscisse x de la grille
*	@param[in] y, l'ordonnée y de la grille
*	@return le nombre de mines à proximité de la case.
*/
unsigned int minesNearby(Grille *gr, unsigned int x, unsigned int y) {
	//Si c'est une mine, ça dégage ;)
	if (detectedMines(gr, x, y)) return 0;

	unsigned int mineCount = 0;
	enum {
		TESTS_TO_DO = 8
	};
	unsigned int toTest[TESTS_TO_DO][2] =
	{
			{x,     y + 1},
			{x,     y - 1},
			{x + 1, y + 0},
			{x + 1, y + 1},
			{x + 1, y - 1},
			{x - 1, y + 0},
			{x - 1, y + 1},
			{x - 1, y - 1},
	};

	//Auto && testing element permet de boucler les éléments du tableau de toTest
	// donc testingElement aura au début la première valeur de toTest puis la deuxième... etc
	for (auto &testingElement : toTest) {
		if (validCase(gr, testingElement[0], testingElement[1])
			&& detectedMines(gr, testingElement[0], testingElement[1]))
			mineCount++;
	}
	return mineCount;
}


/*
*	@brief Démasque une case. Si elle est vide, démasque les autres aux alentours, sinon n'affiche que la case ciblé.
*	@param[in,out] gr, la grille
*	@param[in] x, l'abscisse
*	@param[in] y, l'ordonnée
*/
void unmaskMines(Grille &gr, unsigned int x, unsigned int y) {
	if (gr.tab[x][y] == ELEMENTS::VOID) {
		gr.tab[x][y] = ELEMENTS::VIEWED;
	}
	else {
		gr.tab[x][y] = ELEMENTS::VIEWED;
	}
}

/*
*	@brief initialise les colonnes de la grille
*	@param[in,out] gr, la grille
*/
void generateGrid(Grille *gr) {
	gr->tab = new unsigned *[gr->pb.lineNumber];
	for (unsigned i = 0; i < gr->pb.lineNumber; i++) {
		gr->tab[i] = new unsigned[gr->pb.columnNumber];
	}
}


/*
*	@brief Crée une grille de démineur
*/
void createGrille() {
	unsigned line, column, nbrMine, nbrStroke;
	Grille gr{};

	std::cin >> line >> column >> nbrMine;

	defineProblem(&gr.pb, line, column, nbrMine);
	generateGrid(&gr);
	setMines(&gr);

	//std::cin >> nbrStroke;

	fillGrid(&gr);
	printGrid(&gr);

	//delete memory
	for (unsigned i = 0; i < line; i++) {
		delete[] gr.tab[i];
	}
	delete[] gr.tab;
}

/*
*	@brief initialise les colonnes de la grille
*	@param[in,out] g, la grille
*/
void fillGrid(Grille *g) {
	unsigned lines = g->pb.lineNumber,
		columns = g->pb.columnNumber;

	for (unsigned i = 0; i < lines; i++) {
		for (unsigned j = 0; j < columns; j++) {
			unsigned readableNum = i * lines + j;
			placeMines(g, i, j, readableNum);
			if (g->tab[i][j] != ELEMENTS::BOMB) g->tab[i][j] = ELEMENTS::VOID;
			//g->tab[i][j] = minesNearby(g, i, j);
		}
	}
}